/*
 * Copyright (C) 2015, The CyanogenMod Project <http://www.cyanogenmod.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define LOG_TAG "power"
#include <utils/Log.h>

#include <hardware/hardware.h>
#include <hardware/power.h>

#define MAX_INPUTS 20
#define INPUT_PREFIX "/sys/class/input/input"
#define MAX_PATH_SIZE (strlen(INPUT_PREFIX) + 20)

static const char *names[] = { "sec_touchscreen", "sec_touchkey", "gpio-keys" };
#define N_NAMES (sizeof(names) / sizeof(names[0]))
static char *paths[N_NAMES];
static int have_found_paths;

static size_t sysfs_read(char *path, char *buffer, size_t n)
{
    char buf[80];
    int fd;
    ssize_t len;

    if ((fd = open(path, O_RDONLY)) < 0) {
        if (errno != ENOENT) {
            strerror_r(errno, buf, sizeof(buf));
            ALOGE("Error opening %s: %s\n", path, buf);
        }
        return 0;
    }

    len = read(fd, buffer, n);
    if (len < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error reading from %s: %s\n", path, buf);
        return 0;
    }

    while (len > 0 && isspace(buffer[len-1])) len--;
    if ((size_t) len < n) buffer[len] = '\0';

    close(fd);

    return len;
}

static void sysfs_write(char *path, char *s)
{
    char buf[80];
    int len;
    int fd;

    if (path == NULL) return;

    if ((fd = open(path, O_WRONLY)) < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error opening %s: %s\n", path, buf);
        return;
    }

    len = write(fd, s, strlen(s));
    if (len < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error writing to %s: %s\n", path, buf);
    }

    close(fd);
}

static void find_paths(void)
{
    size_t i, j;
    char path[MAX_PATH_SIZE];
    char name[20];

    for (i = 0; i < MAX_INPUTS; i++) {
        sprintf(path, "%s%d/name", INPUT_PREFIX, i);
        if (sysfs_read(path, name, sizeof(name)) > 0) {
            for (j = 0; j < N_NAMES; j++) {
                if (strcmp(name, names[j]) == 0) {
                    paths[j] = malloc(MAX_PATH_SIZE);
                    sprintf(paths[j], "%s%d/enabled", INPUT_PREFIX, i);
                    ALOGD("%s => %s\n", names[j], paths[j]);
                }
            }
        }
    }
}

static void power_init(struct power_module *module)
{
}

static void power_set_interactive(struct power_module *module, int on)
{
    size_t i;

    ALOGD("%s: %s input devices", __func__, on ? "enabling" : "disabling");

    if (! have_found_paths) {
        find_paths();
        have_found_paths = 1;
    }

    for (i = 0; i < N_NAMES; i++) sysfs_write(paths[i], on ? "1" : "0");
}

static void power_hint(struct power_module *module, power_hint_t hint,
                       void *data) {
    switch (hint) {
    default:
        break;
    }
}

static struct hw_module_methods_t power_module_methods = {
    .open = NULL,
};

struct power_module HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = POWER_MODULE_API_VERSION_0_2,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = POWER_HARDWARE_MODULE_ID,
        .name = "JA3G Power Module",
        .author = "The CyanogenMod Project",
        .methods = &power_module_methods,
    },

    .init = power_init,
    .setInteractive = power_set_interactive,
    .powerHint = power_hint,
};
