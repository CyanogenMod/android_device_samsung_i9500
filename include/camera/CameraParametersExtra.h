/*
 * Copyright (C) 2014 The CyanogenMod Project
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

#include "camera/CameraParametersExtraDurationTimer.h"

#define CAMERA_PARAMETERS_EXTRA_C \
const char CameraParameters::KEY_CITYID[] = "cityid"; \
const char CameraParameters::KEY_WEATHER[] = "weather"; \
const char CameraParameters::ISO_AUTO[] = "auto"; \
const char CameraParameters::ISO_100[] = "100"; \
const char CameraParameters::ISO_200[] = "200"; \
const char CameraParameters::ISO_400[] = "400"; \
const char CameraParameters::ISO_800[] = "800"; \
\
int CameraParameters::getInt64(const char *key) const { return -1; } \
extern "C" { \
    void acquire_dvfs_lock(void) { } \
    void release_dvfs_lock(void) { } \
} \
CAMERA_PARAMETERS_EXTRA_C_DURATION_TIMER \
\
/* LAST_LINE OF CAMERA_PARAMETERS_EXTRA_C, every line before this one *MUST* have
 * a backslash \ at the end of the line or else everything will break.
 */

#define CAMERA_PARAMETERS_EXTRA_H \
    static const char KEY_CITYID[]; \
    static const char KEY_WEATHER[]; \
    static const char ISO_AUTO[]; \
    static const char ISO_100[]; \
    static const char ISO_200[]; \
    static const char ISO_400[]; \
    static const char ISO_800[]; \
    \
    int getInt64(const char *key) const; \
    \
    /* LAST_LINE OF CAMERA_PARAMETERS_EXTRA_H, every line before this one *MUST* have
     * a backslash \ at the end of the line or else everything will break.
     */
