#
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
#

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)
$(call inherit-product, build/target/product/full.mk)

# The gps config appropriate for this device
$(call inherit-product, device/common/gps/gps_us_supl.mk)

LOCAL_PATH := device/samsung/i9500

DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# This device is xxhdpi.  However the platform doesn't
# currently contain all of the bitmaps at xxhdpi density so
# we do this little trick to fall back to the hdpi version
# if the xxhdpi doesn't exist.
PRODUCT_AAPT_CONFIG := normal hdpi xhdpi xxhdpi
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

# Rootdir
PRODUCT_COPY_FILES := \
    $(LOCAL_PATH)/rootdir/fstab.universal5410:root/fstab.universal5410 \
    $(LOCAL_PATH)/rootdir/init.universal5410.rc:root/init.universal5410.rc \
    $(LOCAL_PATH)/rootdir/init.universal5410.usb.rc:root/init.universal5410.usb.rc \
    $(LOCAL_PATH)/rootdir/init.wifi.rc:root/init.wifi.rc \
    $(LOCAL_PATH)/rootdir/ueventd.universal5410.rc:root/ueventd.universal5410.rc

$(call inherit-product-if-exists, vendor/samsung/i9500/i9500-vendor.mk)
