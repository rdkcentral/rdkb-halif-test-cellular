/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:*
 * Copyright 2023 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cellular_hal.h"

unsigned int cellular_hal_IsModemDevicePresent(void)
{
  /*TODO: Implement Me!*/
  return (unsigned int)0;
}

int cellular_hal_init(CellularContextInitInputStruct *pstCtxInputStruct)
{
  /*TODO: Implement Me!*/
  (void)pstCtxInputStruct;
  return (int)0;
}

int cellular_hal_open_device(CellularDeviceContextCBStruct *pstDeviceCtxCB)
{
  /*TODO: Implement Me!*/
  (void)pstDeviceCtxCB;
  return (int)0;
}

unsigned char cellular_hal_IsModemControlInterfaceOpened(void)
{
  /*TODO: Implement Me!*/
  return (unsigned char)0;
}

int cellular_hal_select_device_slot(cellular_device_slot_status_api_callback device_slot_status_cb)
{
  /*TODO: Implement Me!*/
  (void)device_slot_status_cb;
  return (int)0;
}

int cellular_hal_sim_power_enable(unsigned int slot_id, unsigned char enable)
{
  /*TODO: Implement Me!*/
  (void)slot_id;
  (void)enable;
  return (int)0;
}

int cellular_hal_get_total_no_of_uicc_slots(unsigned int *total_count)
{
  /*TODO: Implement Me!*/
  (void)total_count;
  return (int)0;
}

int cellular_hal_get_uicc_slot_info(unsigned int slot_index, CellularUICCSlotInfoStruct *pstSlotInfo)
{
  /*TODO: Implement Me!*/
  (void)slot_index;
  (void)pstSlotInfo;
  return (int)0;
}

int cellular_hal_get_active_card_status(CellularUICCStatus_t *card_status)
{
  /*TODO: Implement Me!*/
  (void)card_status;
  return (int)0;
}

int cellular_hal_monitor_device_registration(cellular_device_registration_status_callback device_registration_status_cb)
{
  /*TODO: Implement Me!*/
  (void)device_registration_status_cb;
  return (int)0;
}

int cellular_hal_profile_create(CellularProfileStruct *pstProfileInput, cellular_device_profile_status_api_callback device_profile_status_cb)
{
  /*TODO: Implement Me!*/
  (void)pstProfileInput;
  (void)device_profile_status_cb;
  return (int)0;
}

int cellular_hal_profile_delete(CellularProfileStruct *pstProfileInput, cellular_device_profile_status_api_callback device_profile_status_cb)
{
  /*TODO: Implement Me!*/
  (void)pstProfileInput;
  (void)device_profile_status_cb;
  return (int)0;
}

int cellular_hal_profile_modify(CellularProfileStruct *pstProfileInput, cellular_device_profile_status_api_callback device_profile_status_cb)
{
  /*TODO: Implement Me!*/
  (void)pstProfileInput;
  (void)device_profile_status_cb;
  return (int)0;
}

int cellular_hal_get_profile_list(CellularProfileStruct **ppstProfileOutput, int *profile_count)
{
  /*TODO: Implement Me!*/
  (void)ppstProfileOutput;
  (void)profile_count;
  return (int)0;
}

int cellular_hal_start_network(CellularNetworkIPType_t ip_request_type, CellularProfileStruct *pstProfileInput, CellularNetworkCBStruct *pstCBStruct)
{
  /*TODO: Implement Me!*/
  (void)ip_request_type;
  (void)pstProfileInput;
  (void)pstCBStruct;
  return (int)0;
}

int cellular_hal_stop_network(CellularNetworkIPType_t ip_request_type)
{
  /*TODO: Implement Me!*/
  (void)ip_request_type;
  return (int)0;
}

int cellular_hal_get_signal_info(CellularSignalInfoStruct *signal_info)
{
  /*TODO: Implement Me!*/
  (void)signal_info;
  return (int)0;
}

int cellular_hal_set_modem_operating_configuration(CellularModemOperatingConfiguration_t modem_operating_config)
{
  /*TODO: Implement Me!*/
  (void)modem_operating_config;
  return (int)0;
}

int cellular_hal_get_device_imei(char *imei)
{
  /*TODO: Implement Me!*/
  (void)imei;
  return (int)0;
}

int cellular_hal_get_device_imei_sv(char *imei_sv)
{
  /*TODO: Implement Me!*/
  (void)imei_sv;
  return (int)0;
}

int cellular_hal_get_modem_current_iccid(char *iccid)
{
  /*TODO: Implement Me!*/
  (void)iccid;
  return (int)0;
}

int cellular_hal_get_modem_current_msisdn(char *msisdn)
{
  /*TODO: Implement Me!*/
  (void)msisdn;
  return (int)0;
}

int cellular_hal_get_packet_statistics(CellularPacketStatsStruct *network_packet_stats)
{
  /*TODO: Implement Me!*/
  (void)network_packet_stats;
  return (int)0;
}

int cellular_hal_get_current_modem_interface_status(CellularInterfaceStatus_t *status)
{
  /*TODO: Implement Me!*/
  (void)status;
  return (int)0;
}

int cellular_hal_set_modem_network_attach(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int cellular_hal_set_modem_network_detach(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int cellular_hal_get_modem_firmware_version(char *firmware_version)
{
  /*TODO: Implement Me!*/
  (void)firmware_version;
  return (int)0;
}

int cellular_hal_get_current_plmn_information(CellularCurrentPlmnInfoStruct *plmn_info)
{
  /*TODO: Implement Me!*/
  (void)plmn_info;
  return (int)0;
}

int cellular_hal_get_available_networks_information(CellularNetworkScanResultInfoStruct **network_info, unsigned int *total_network_count)
{
  /*TODO: Implement Me!*/
  (void)network_info;
  (void)total_network_count;
  return (int)0;
}

int cellular_hal_get_modem_preferred_radio_technology(char *preferred_rat)
{
  /*TODO: Implement Me!*/
  (void)preferred_rat;
  return (int)0;
}

int cellular_hal_set_modem_preferred_radio_technology(char *preferred_rat)
{
  /*TODO: Implement Me!*/
  (void)preferred_rat;
  return (int)0;
}

int cellular_hal_get_modem_current_radio_technology(char *current_rat)
{
  /*TODO: Implement Me!*/
  (void)current_rat;
  return (int)0;
}

int cellular_hal_get_modem_supported_radio_technology(char *supported_rat)
{
  /*TODO: Implement Me!*/
  (void)supported_rat;
  return (int)0;
}

int cellular_hal_modem_factory_reset(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int cellular_hal_modem_reset(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}
