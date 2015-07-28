/*
 * Copyright (C) 2013 The CyanogenMod Project
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

#ifndef RIL_INTERFACE_H
#define RIL_INTERFACE_H

#define RIL_CLIENT_LIBPATH "libsecril-client.so"

#define RIL_CLIENT_ERR_SUCCESS      0
#define RIL_CLIENT_ERR_AGAIN        1
#define RIL_CLIENT_ERR_INIT         2 // Client is not initialized
#define RIL_CLIENT_ERR_INVAL        3 // Invalid value
#define RIL_CLIENT_ERR_CONNECT      4 // Connection error
#define RIL_CLIENT_ERR_IO           5 // IO error
#define RIL_CLIENT_ERR_RESOURCE     6 // Resource not available
#define RIL_CLIENT_ERR_UNKNOWN      7

#define RIL_OEM_UNSOL_RESPONSE_BASE 11000 // RIL response base index
#define RIL_UNSOL_WB_AMR_STATE \
    (RIL_OEM_UNSOL_RESPONSE_BASE + 17)    // RIL AMR state index

struct ril_handle
{
    void *handle;
    void *client;
    int volume_steps_max;
};

enum ril_sound_type {
    SOUND_TYPE_VOICE,
    SOUND_TYPE_SPEAKER,
    SOUND_TYPE_HEADSET,
    SOUND_TYPE_BTVOICE
};

enum ril_audio_path {
    SOUND_AUDIO_PATH_EARPIECE,
    SOUND_AUDIO_PATH_HEADSET,
    SOUND_AUDIO_PATH_SPEAKER,
    SOUND_AUDIO_PATH_BLUETOOTH,
    SOUND_AUDIO_PATH_STEREO_BT,
    SOUND_AUDIO_PATH_HEADPHONE,
    SOUND_AUDIO_PATH_BLUETOOTH_NO_NR,
    SOUND_AUDIO_PATH_MIC1,
    SOUND_AUDIO_PATH_MIC2,
    SOUND_AUDIO_PATH_BLUETOOTH_WB,
    SOUND_AUDIO_PATH_BLUETOOTH_WB_NO_NR
};

enum ril_extra_volume {
    ORIGINAL_PATH,
    EXTRA_VOLUME_PATH
};

enum ril_clock_state {
    SOUND_CLOCK_STOP,
    SOUND_CLOCK_START
};

enum ril_mute_state {
    TX_UNMUTE,
    TX_MUTE,
    RX_UNMUTE,
    RX_MUTE,
    RXTX_UNMUTE,
    RXTX_MUTE
};

enum ril_two_mic_device {
    AUDIENCE,
    FORTEMEDIA
};

enum ril_two_mic_state {
    TWO_MIC_SOLUTION_OFF,
    TWO_MIC_SOLUTION_ON
};

/* Function prototypes */
int ril_open(struct ril_handle *ril);
int ril_close(struct ril_handle *ril);
int ril_set_call_volume(struct ril_handle *ril, enum ril_sound_type sound_type,
                        float volume);
int ril_set_call_audio_path(struct ril_handle *ril,
                            enum ril_audio_path path,
                            enum ril_extra_volume mode);
int ril_set_call_clock_sync(struct ril_handle *ril, enum ril_clock_state state);
int ril_set_mute(struct ril_handle *ril, enum ril_mute_state state);
void ril_register_set_wb_amr_callback(void *function, void *data);
int ril_set_two_mic_control(struct ril_handle *ril, enum ril_two_mic_device device, enum ril_two_mic_state state);

#endif
