LOCAL_PATH := $(call my-dir)

# HAL module implemenation stored in
# # hw/<POWERS_HARDWARE_MODULE_ID>.<ro.hardware>.so
include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_SHARED_LIBRARIES := liblog libcutils libhardware libdl
LOCAL_SRC_FILES := irda.c
LOCAL_MODULE:= irda.universal5410
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
