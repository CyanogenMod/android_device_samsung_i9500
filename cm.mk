# Copyright (C) 2014 The CyanogenMod Project
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

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from i9500 device
$(call inherit-product, device/samsung/i9500/i9500.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_NAME := cm_i9500
PRODUCT_DEVICE := i9500
PRODUCT_MANUFACTURER := samsung
PRODUCT_MODEL := GT-I9500

PRODUCT_BRAND := samsung

PRODUCT_BUILD_PROP_OVERRIDES += \
	PRODUCT_MODEL=GT-I9500 \
	PRODUCT_NAME=ja3gxx \
	PRODUCT_DEVICE=ja3g \
	TARGET_DEVICE=ja3g \
	BUILD_FINGERPRINT="samsung/ja3gxx/ja3g:5.0.2/LRX22G/I9500XXUFNI2:user/release-keys" \
	PRIVATE_BUILD_DESC="ja3gxx-user 5.0.2 LRX22G I9500XXUFNI2 release-keys"
