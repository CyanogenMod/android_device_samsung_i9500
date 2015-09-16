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

#define LOG_TAG "power"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <utils/Log.h>

#include <hardware/hardware.h>
#include <hardware/power.h>

#define PATH_GPIO_KEYS "/sys/class/input/input14/enabled"
#define PATH_TOUCHKEY "/sys/class/input/input15/enabled"
#define PATH_TOUCHSCREEN "/sys/class/input/input1/enabled"

static void sysfs_write(char *path, char *s)
{
    char buf[80];
    int len;
    int fd;

    if (path == NULL)
        return;

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

static void power_init(struct power_module *module)
{
}

static void power_set_interactive(struct power_module *module, int on)
{
    ALOGD("%s: %s input devices", __func__, on ? "enabling" : "disabling");

    sysfs_write(PATH_TOUCHSCREEN, on ? "1" : "0");
    sysfs_write(PATH_TOUCHKEY, on ? "1" : "0");
    sysfs_write(PATH_GPIO_KEYS, on ? "1" : "0");
}

static void power_hint(struct power_module *module, power_hint_t hint,
        void *data)
{
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
