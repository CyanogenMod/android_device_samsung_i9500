# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)

# Audio HAL
include $(CLEAR_VARS)

LOCAL_MODULE := audio.primary.$(TARGET_BOOTLOADER_BOARD_NAME)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := audio_hw.c ril_interface.c

LOCAL_C_INCLUDES += \
	external/tinyalsa/include \
	$(call include-path-for, audio-effects) \
	$(call include-path-for, audio-utils) \
	$(call include-path-for, audio-route)

LOCAL_SHARED_LIBRARIES := liblog libcutils libtinyalsa libaudioutils libdl \
	libaudience_voicefx libaudioroute

include $(BUILD_SHARED_LIBRARY)


# Audience voice preprocessing library
include $(CLEAR_VARS)

LOCAL_MODULE := libaudience_voicefx
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES:= eS325VoiceProcessing.cpp

LOCAL_C_INCLUDES += \
	$(call include-path-for, audio-effects)

LOCAL_SHARED_LIBRARIES := liblog libutils

include $(BUILD_SHARED_LIBRARY)


# Mixer configurations
include $(CLEAR_VARS)
LOCAL_MODULE := mixer_paths.xml
LOCAL_MODULE_TAGS := optional eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES := mixer_paths.xml
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)
include $(BUILD_PREBUILT)
