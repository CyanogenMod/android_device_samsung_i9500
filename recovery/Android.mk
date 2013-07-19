LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE		:= init.recovery.universal5410.rc
LOCAL_MODULE_TAGS	:= optional eng
LOCAL_MODULE_CLASS	:= ETC
LOCAL_SRC_FILES		:= etc/init.recovery.universal5410.rc
LOCAL_MODULE_PATH	:= $(TARGET_ROOT_OUT)
include $(BUILD_PREBUILT)
