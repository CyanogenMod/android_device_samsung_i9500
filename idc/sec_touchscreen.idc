# Copyright (C) 2015 The Android Open Source Project
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
# Input Device Calibration File for the universal5410 touch screen
#

#
# These calibration values are derived from empirical measurements
# and may not be appropriate for use with other touch screens.
# Refer to the input device configuration documentation for more details.
#

device.internal = 1

# Basic Parameters
touch.deviceType = touchScreen
touch.orientationAware = 1

# Tool Size
# Driver reports tool size as an area measurement.
#
# Based on empirical measurements, we estimate the size of the tool
# using size = sqrt(22 * rawToolArea + 0) * 6 + 0.
touch.size.calibration = area
touch.size.scale = 52
touch.size.bias = 11.8
touch.size.isSummed = 0

# Pressure
# Driver reports signal strength as pressure.
#
# A normal index finger touch typically registers about 80 signal strength
# units although we don't expect these values to be accurate.
touch.pressure.calibration = amplitude
touch.pressure.scale = 0.015

# Orientation
touch.orientation.calibration = vector

# Stock Values
touch.blockzone.xMin = 0
touch.blockzone.yMin = 426
touch.blockzone.xMax = 1080
touch.blockzone.yMax = 1920
