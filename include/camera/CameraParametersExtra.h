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
const char CameraParameters::KEY_SUPPORTED_ISO_MODES[] = "iso-values"; \
const char CameraParameters::KEY_FACE_DETECTION[] = "face-detection"; \
const char CameraParameters::KEY_SUPPORTED_FACE_DETECTION[] = "face-detection-values"; \
const char CameraParameters::KEY_ZSL[] = "zsl"; \
const char CameraParameters::KEY_ISO_MODE[] = "iso"; \
const char CameraParameters::KEY_CAMERA_MODE[] = "camera-mode"; \
const char CameraParameters::KEY_SAMSUNG_CAMERA_MODE[] = "cam_mode"; \
\
const char CameraParameters::KEY_ANTI_SHAKE_MODE[] = "anti-shake"; \
const char CameraParameters::KEY_METERING[] = "metering"; \
const char CameraParameters::KEY_WDR[] = "wdr"; \
const char CameraParameters::KEY_WEATHER[] = "weather"; \
const char CameraParameters::KEY_CITYID[] = "contextualtag-cityid"; \
\
const char CameraParameters::KEY_DYNAMIC_RANGE_CONTROL[] = "dynamic-range-control"; \
const char CameraParameters::KEY_SUPPORTED_DYNAMIC_RANGE_CONTROL[] = "dynamic-range-control-values"; \
const char CameraParameters::KEY_PHASE_AF[] = "phase-af"; \
const char CameraParameters::KEY_SUPPORTED_PHASE_AF[] = "phase-af-values"; \
const char CameraParameters::KEY_RT_HDR[] = "rt-hdr"; \
const char CameraParameters::KEY_SUPPORTED_RT_HDR[] = "rt-hdr-values"; \
const char CameraParameters::DRC_ON[] = "on"; \
const char CameraParameters::DRC_OFF[] = "off"; \
const char CameraParameters::PAF_ON[] = "on"; \
const char CameraParameters::PAF_OFF[] = "off"; \
const char CameraParameters::RTHDR_ON[] = "on"; \
const char CameraParameters::RTHDR_OFF[] = "off"; \
const char CameraParameters::EFFECT_CARTOONIZE[] = "cartoonize"; \
const char CameraParameters::EFFECT_POINT_RED_YELLOW[] = "point-red-yellow"; \
const char CameraParameters::EFFECT_POINT_GREEN[] = "point-green"; \
const char CameraParameters::EFFECT_POINT_BLUE[] = "point-blue"; \
const char CameraParameters::EFFECT_VINTAGE_COLD[] = "vintage-cold"; \
const char CameraParameters::EFFECT_VINTAGE_WARM[] = "vintage-warm"; \
const char CameraParameters::EFFECT_WASHED[] = "washed"; \
\
int CameraParameters::getInt64(const char *key) const { return -1; } \
\
CAMERA_PARAMETERS_EXTRA_C_DURATION_TIMER


#define CAMERA_PARAMETERS_EXTRA_H \
    static const char KEY_SUPPORTED_ISO_MODES[]; \
    static const char KEY_FACE_DETECTION[]; \
    static const char KEY_SUPPORTED_FACE_DETECTION[]; \
    static const char KEY_ZSL[]; \
    static const char KEY_ISO_MODE[]; \
    static const char KEY_CAMERA_MODE[]; \
    static const char KEY_SAMSUNG_CAMERA_MODE[]; \
    static const char KEY_ANTI_SHAKE_MODE[]; \
    static const char KEY_METERING[]; \
    static const char KEY_WDR[]; \
    static const char KEY_WEATHER[]; \
    static const char KEY_CITYID[]; \
\
    static const char KEY_DYNAMIC_RANGE_CONTROL[]; \
    static const char KEY_SUPPORTED_DYNAMIC_RANGE_CONTROL[]; \
    static const char KEY_PHASE_AF[]; \
    static const char KEY_SUPPORTED_PHASE_AF[]; \
    static const char KEY_RT_HDR[]; \
    static const char KEY_SUPPORTED_RT_HDR[]; \
    static const char DRC_ON[]; \
    static const char DRC_OFF[]; \
    static const char PAF_ON[]; \
    static const char PAF_OFF[]; \
    static const char RTHDR_ON[]; \
    static const char RTHDR_OFF[]; \
\
    static const char EFFECT_CARTOONIZE[]; \
    static const char EFFECT_POINT_RED_YELLOW[]; \
    static const char EFFECT_POINT_GREEN[]; \
    static const char EFFECT_POINT_BLUE[]; \
    static const char EFFECT_VINTAGE_COLD[]; \
    static const char EFFECT_VINTAGE_WARM[]; \
    static const char EFFECT_WASHED[]; \
\
    int getInt64(const char *key) const; \
    

