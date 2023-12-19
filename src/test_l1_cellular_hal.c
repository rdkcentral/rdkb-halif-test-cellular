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
 
/**
* @file test_l1_cellular_hal.c
* @page cellular_hal Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
* This is to ensure that the cellular_hal APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include <stdlib.h>
#include <string.h>
#include "cellular_hal.h"

/**
* @brief Test for checking the behavior of cellular_hal_IsModemDevicePresent() function when no modem device is present.
*
* This test case checks the return value of the cellular_hal_IsModemDevicePresent() function. The objective of this test is to ensure that the function correctly.
* 
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 001 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke cellular_hal_IsModemDevicePresent() API  | None | TRUE or FALSE | Should return success |
*/
void test_l1_cellular_hal_positive1_IsModemDevicePresent(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_IsModemDevicePresent...");
    unsigned int status = 0;

    UT_LOG("Invoking cellular_hal_IsModemDevicePresent() ");
    status = cellular_hal_IsModemDevicePresent();
    UT_LOG("Return Status: %d", status);

    if( status == TRUE || status == FALSE)
    {
        UT_LOG("cellular_hal_IsModemDevicePresent returns %d which is a valid value", status);
        UT_PASS("cellular_hal_IsModemDevicePresent validation success");
    }
    else
    {
        UT_LOG("cellular_hal_IsModemDevicePresent returns is %d which is an invalid value", status);
        UT_FAIL("cellular_hal_IsModemDevicePresent failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_IsModemDevicePresent...");
}

/**
* @brief Test case to validate the valid initialization of the L1 Cellular HAL
*
* This test case is used to verify the functionality of the L1 Cellular HAL when it is initialized with valid values. The objective of this test is to ensure that the initialization function returns the expected result when valid data is provided.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 002 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, they need to select this test case via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_init()  with valid pstCtxInputStruct pointer  | pstCtxInputStruct = valid pointer | RETURN_OK | should return successful|
*/
void test_l1_cellular_hal_positive1_init(void) 
{    
    UT_LOG("Entering test_l1_cellular_hal_positive1_init...");
    int result = 0;
    CellularContextInitInputStruct *pstCtxInputStruct = (CellularContextInitInputStruct*) malloc(sizeof(CellularContextInitInputStruct)) ;
    if(pstCtxInputStruct != NULL)
    {
        memset(pstCtxInputStruct, 0, sizeof(CellularContextInitInputStruct));                
        UT_LOG("Invoking cellular_hal_init.........");                
        result = cellular_hal_init(pstCtxInputStruct);
        UT_LOG("Return Status: %d", result);

        if(pstCtxInputStruct != NULL)
        {
            if((pstCtxInputStruct->enIPFamilyPreference == IP_FAMILY_UNKNOWN) || (pstCtxInputStruct->enIPFamilyPreference == IP_FAMILY_IPV4) || (pstCtxInputStruct->enIPFamilyPreference == IP_FAMILY_IPV6) || (pstCtxInputStruct->enIPFamilyPreference == IP_FAMILY_IPV4_IPV6))
            {
                UT_LOG(" pstCtxInputStruct->enIPFamilyPreference is valid %d ",pstCtxInputStruct->enIPFamilyPreference);
                UT_PASS("stCtxInputStruct->enIPFamilyPreference is valid");
            }
            else
            {
                UT_LOG(" pstCtxInputStruct->enIPFamilyPreference is Invalid %d ",pstCtxInputStruct->enIPFamilyPreference);
                UT_FAIL("stCtxInputStruct->enIPFamilyPreference is Invalid");
            }
            if(pstCtxInputStruct->stIfInput.ProfileID >= 0 && pstCtxInputStruct->stIfInput.ProfileID <= 2147483647)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.ProfileID is valid %d ",pstCtxInputStruct->stIfInput.ProfileID);
                UT_PASS("pstCtxInputStruct->stIfInput.ProfileID is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.ProfileID is invalid %d ",pstCtxInputStruct->stIfInput.ProfileID);
                UT_FAIL("pstCtxInputStruct->stIfInput.ProfileID is invalid");
            }
            
            if(pstCtxInputStruct->stIfInput.ProfileType == CELLULAR_PROFILE_TYPE_3GPP || pstCtxInputStruct->stIfInput.ProfileType == CELLULAR_PROFILE_TYPE_3GPP2)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.ProfileType is valid %d ",pstCtxInputStruct->stIfInput.ProfileType);
                UT_PASS("pstCtxInputStruct->stIfInput.ProfileType is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.ProfileType is invalid %d ",pstCtxInputStruct->stIfInput.ProfileType);
                UT_FAIL("pstCtxInputStruct->stIfInput.ProfileType is invalid");		
            }
            
            if(pstCtxInputStruct->stIfInput.PDPContextNumber >= 0 && pstCtxInputStruct->stIfInput.PDPContextNumber <= 2147483647)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPContextNumber is valid %d ",pstCtxInputStruct->stIfInput.PDPContextNumber);
                UT_PASS("pstCtxInputStruct->stIfInput.PDPContextNumber is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPContextNumber is invalid %d ",pstCtxInputStruct->stIfInput.PDPContextNumber);
                UT_FAIL("pstCtxInputStruct->stIfInput.PDPContextNumber is invalid");
            }
            
            if((pstCtxInputStruct->stIfInput.PDPType == CELLULAR_PDP_TYPE_IPV4) || (pstCtxInputStruct->stIfInput.PDPType == CELLULAR_PDP_TYPE_PPP) || (pstCtxInputStruct->stIfInput.PDPType == CELLULAR_PDP_TYPE_IPV6) || (pstCtxInputStruct->stIfInput.PDPType == CELLULAR_PDP_TYPE_IPV4_OR_IPV6))
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPType is valid %d ",pstCtxInputStruct->stIfInput.PDPType);
                UT_PASS("pstCtxInputStruct->stIfInput.PDPType is valid");		 
            }
            else		
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPType is invalid %d ",pstCtxInputStruct->stIfInput.PDPType);
                UT_FAIL("pstCtxInputStruct->stIfInput.PDPType is invalid");
            }
            if((pstCtxInputStruct->stIfInput.PDPAuthentication == CELLULAR_PDP_AUTHENTICATION_NONE) || (pstCtxInputStruct->stIfInput.PDPAuthentication == CELLULAR_PDP_AUTHENTICATION_PAP) || (pstCtxInputStruct->stIfInput.PDPAuthentication == CELLULAR_PDP_AUTHENTICATION_CHAP))
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPAuthentication is valid %d ",pstCtxInputStruct->stIfInput.PDPAuthentication);
                UT_PASS("pstCtxInputStruct->stIfInput.PDPAuthentication is valid");		
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPAuthentication is invalid %d ",pstCtxInputStruct->stIfInput.PDPAuthentication);
                UT_FAIL("pstCtxInputStruct->stIfInput.PDPAuthentication is invalid");
            }	

            if((pstCtxInputStruct->stIfInput.PDPNetworkConfig == CELLULAR_PDP_NETWORK_CONFIG_NAS) || (pstCtxInputStruct->stIfInput.PDPNetworkConfig ==  CELLULAR_PDP_NETWORK_CONFIG_DHCP))
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPNetworkConfig is valid %d ",pstCtxInputStruct->stIfInput.PDPNetworkConfig);
                UT_PASS("pstCtxInputStruct->stIfInput.PDPNetworkConfig is valid");			
            }	
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.PDPNetworkConfig is invalid %d ",pstCtxInputStruct->stIfInput.PDPNetworkConfig);
                UT_FAIL("pstCtxInputStruct->stIfInput.PDPNetworkConfig is invalid");		
            }
			if(pstCtxInputStruct->stIfInput.ProfileName == NULL || pstCtxInputStruct->stIfInput.ProfileName[0] == '\0')
			{
                UT_LOG("pstCtxInputStruct->stIfInput.ProfileName is empty string");
                UT_FAIL("pstCtxInputStruct->stIfInput.ProfileName validation failed");
			}
			else
			{
                UT_LOG("pstCtxInputStruct->stIfInput.ProfileName is : %s ",pstCtxInputStruct->stIfInput.ProfileName);
                UT_PASS("pstCtxInputStruct->stIfInput.ProfileName validation success");
			}
			if(pstCtxInputStruct->stIfInput.APN == NULL || pstCtxInputStruct->stIfInput.APN[0] == '\0')
			{
                UT_LOG("pstCtxInputStruct->stIfInput.APN is empty string");
                UT_FAIL("pstCtxInputStruct->stIfInput.APN validation failed");
			}
			else
			{
                UT_LOG("pstCtxInputStruct->stIfInput.APN is : %s ",pstCtxInputStruct->stIfInput.APN);
                UT_PASS("pstCtxInputStruct->stIfInput.APN validation success");
			}
			if(pstCtxInputStruct->stIfInput.Username == NULL || pstCtxInputStruct->stIfInput.Username[0] == '\0')
			{
                UT_LOG("pstCtxInputStruct->stIfInput.Username is empty string");
                UT_FAIL("pstCtxInputStruct->stIfInput.Username validation failed");
			}
			else
			{
                UT_LOG("pstCtxInputStruct->stIfInput.Username is : %s ",pstCtxInputStruct->stIfInput.Username);
                UT_PASS("pstCtxInputStruct->stIfInput.Username validation success");
			}
			if(pstCtxInputStruct->stIfInput.Password == NULL || pstCtxInputStruct->stIfInput.Password[0] == '\0')
			{
                UT_LOG("pstCtxInputStruct->stIfInput.Password is empty string");
                UT_FAIL("pstCtxInputStruct->stIfInput.Password validation failed");
			}
			else
			{
                UT_LOG("pstCtxInputStruct->stIfInput.Password is : %s ",pstCtxInputStruct->stIfInput.Password);
                UT_PASS("pstCtxInputStruct->stIfInput.Password validation success");
			}
			if(pstCtxInputStruct->stIfInput.Proxy == NULL || pstCtxInputStruct->stIfInput.Proxy[0] == '\0')
			{
                UT_LOG("pstCtxInputStruct->stIfInput.Proxy is empty string");
                UT_FAIL("pstCtxInputStruct->stIfInput.Proxy validation failed");
			}
			else
			{
                UT_LOG("pstCtxInputStruct->stIfInput.Proxy is : %s ",pstCtxInputStruct->stIfInput.Proxy);
                UT_PASS("pstCtxInputStruct->stIfInput.Proxy validation success");
			}
            if(pstCtxInputStruct->stIfInput.ProxyPort >= 0 && pstCtxInputStruct->stIfInput.ProxyPort <= 65535)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.ProxyPort is valid %d ",pstCtxInputStruct->stIfInput.ProxyPort);
                UT_PASS("pstCtxInputStruct->stIfInput.ProxyPort is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.ProxyPort is invalid %d ",pstCtxInputStruct->stIfInput.ProxyPort);
                UT_FAIL("pstCtxInputStruct->stIfInput.ProxyPort is invalid");
            }
            if(pstCtxInputStruct->stIfInput.bIsNoRoaming == TRUE || pstCtxInputStruct->stIfInput.bIsNoRoaming == FALSE)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.bIsNoRoaming is valid %d ",pstCtxInputStruct->stIfInput.bIsNoRoaming);
                UT_PASS("pstCtxInputStruct->stIfInput.bIsNoRoaming is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.bIsNoRoaming is invalid %d ",pstCtxInputStruct->stIfInput.bIsNoRoaming);
                UT_FAIL("pstCtxInputStruct->stIfInput.bIsNoRoaming is invalid");
            }
            if(pstCtxInputStruct->stIfInput.bIsAPNDisabled == TRUE || pstCtxInputStruct->stIfInput.bIsAPNDisabled == FALSE)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.bIsAPNDisabled is valid %d ",pstCtxInputStruct->stIfInput.bIsAPNDisabled);
                UT_PASS("pstCtxInputStruct->stIfInput.bIsAPNDisabled is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.bIsAPNDisabled is invalid %d ",pstCtxInputStruct->stIfInput.bIsAPNDisabled);
                UT_FAIL("pstCtxInputStruct->stIfInput.bIsAPNDisabled is invalid");
            }
            if(pstCtxInputStruct->stIfInput.bIsThisDefaultProfile == TRUE || pstCtxInputStruct->stIfInput.bIsThisDefaultProfile == FALSE)
            {
                UT_LOG("pstCtxInputStruct->stIfInput.bIsThisDefaultProfile is valid %d ",pstCtxInputStruct->stIfInput.bIsThisDefaultProfile);
                UT_PASS("pstCtxInputStruct->stIfInput.bIsThisDefaultProfile is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->stIfInput.bIsThisDefaultProfile is invalid %d ",pstCtxInputStruct->stIfInput.bIsThisDefaultProfile);
                UT_FAIL("pstCtxInputStruct->stIfInput.bIsThisDefaultProfile is invalid");
            }
            if((pstCtxInputStruct->enPreferenceTechnology == PREF_GPRS) || (pstCtxInputStruct->enPreferenceTechnology == PREF_EDGE) || (pstCtxInputStruct->enPreferenceTechnology == PREF_UMTS) || (pstCtxInputStruct->enPreferenceTechnology == PREF_UMTSHSPA) || (pstCtxInputStruct->enPreferenceTechnology == PREF_CDMA2000OneX) || (pstCtxInputStruct->enPreferenceTechnology == PREF_CDMA2000HRPD) || (pstCtxInputStruct->enPreferenceTechnology == PREF_LTE) || (pstCtxInputStruct->enPreferenceTechnology == PREF_NR))
            {
                UT_LOG("pstCtxInputStruct->enPreferenceTechnology is valid %d ",pstCtxInputStruct->enPreferenceTechnology);
                UT_PASS("pstCtxInputStruct->enPreferenceTechnology is valid");
            }
            else
            {
                UT_LOG("pstCtxInputStruct->enPreferenceTechnology is invalid %d ",pstCtxInputStruct->enPreferenceTechnology);
                UT_FAIL("pstCtxInputStruct->enPreferenceTechnology is invalid");
            }

            free(pstCtxInputStruct);
        }
        else
        {
            UT_LOG("cellular_hal_init returned NULL pointer");
            UT_FAIL("cellular_hal_init returned NULL pointer");

        }
        UT_ASSERT_EQUAL(result, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_init...");
}

/**
* @brief Test the functionality of enabling power on a specific slot using the cellular_hal_sim_power_enable function.
*
* This test case checks if the cellular_hal_sim_power_enable function is able to successfully enable power on a specific slot.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 03 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable() with valid slot_id as 1  and enable value as true  | valid slot_id = 1, enable = true | Return OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_sim_power_enable...");
    unsigned int slot_id = 1;
    int result = 0;
    unsigned char enable = true;

    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_sim_power_enable...");
}

/**
* @brief Test Case to test the functionality of the cellular_hal_sim_power_enable API when disabling power on slot 1.
*
* This test case is used to verify if the cellular_hal_sim_power_enable API correctly disables power on slot 1.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 04 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable()  with valid slot id as 1 and enable value as false | valid slot_id = 1, enable = false | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_sim_power_enable...");
    unsigned int slot_id = 1;
    int result = 0;
    unsigned char enable = false;

    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive2_sim_power_enable...");
}

/**
* @brief This test case checks the functionality of the cellular_hal_sim_power_enable() function when enabling power on slot 2.
*
* The objective of this test is to ensure that the cellular_hal_sim_power_enable() function correctly enables power on slot 2 and returns the expected result.
*
* **Test Group ID:** Basic: 01 @n 
* **Test Case ID:** 05 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*  
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable() with valid slot id  as 2 and enable value as true| valid slot_id = 2, enable = true | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive3_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive3_sim_power_enable...");
    unsigned int slot_id = 2;
    int result = 0;
    unsigned char enable = true;

    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive3_sim_power_enable...");
}

/**
* @brief Test to verify disabling power on slot 2 using the cellular_hal_sim_power_enable() API.
*
* This test checks the functionality of disabling power on slot 2 by calling the cellular_hal_sim_power_enable() API.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 06 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data  | Expected Result| Notes|
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* |  01 | Invoke the sim_power_enable() with valid slot id as 2 and enable value as false | Valid input slot_id = 2, enable = false| RETURN_OK | Should be successful|
*/
void test_l1_cellular_hal_positive4_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive4_sim_power_enable...");
    unsigned int slot_id = 2;
    int result = 0;
    unsigned char enable = false;

    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive4_sim_power_enable...");
}

/**
* @brief This test case checks the handling of an invalid slot ID in the cellular_hal_sim_power_enable function.
*
* The purpose of this test is to verify that the function correctly handles an invalid slot ID value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 07 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable() with invalid slot id and valid enable value | slot_id = invalid value |  RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_sim_power_enable...");
    unsigned int slot_id = 999;
    int result = 0;
    unsigned char enable = true;

    UT_LOG("Invoking cellular_hal_sim_power_enable with invalid slot_id = %d, enable = %d...", slot_id, enable);
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_sim_power_enable...");
}

/**
* @brief Verify the behavior of the function when providing an invalid value for the enable parameter.
*
* This test case checks if the function behaves correctly when an invalid value is provided for the enable parameter. The slot_id parameter is set to 1 and the enable parameter is set to 2, which is an invalid value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 08 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable() with valid slot id and invalid enable value | slot_id = 1, enable = invalid value| RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative2_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative2_sim_power_enable...");
    unsigned int slot_id = 1;
    int result = 0;
    unsigned char enable = '2';

    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, invalid enable = %c...", slot_id, enable);
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative2_sim_power_enable...");
}
/**
* @brief This test function is used to test the functionality of cellular_hal_get_total_no_of_uicc_slots API.
*
* The objective of this test is to verify that the API cellular_hal_get_total_no_of_uicc_slots returns the correct value for the total number of UICC slots available.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 09 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_total_no_of_uicc_slots with  valid total_slots value | total_slots = valid value | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_total_no_of_uicc_slots(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive_1_get_total_uicc_slots...");
    int result = 0;   
    unsigned int total_slots = 0;

    UT_LOG("Invoking cellular_hal_get_total_no_of_uicc_slots with total_slots = 0");
    result = cellular_hal_get_total_no_of_uicc_slots(&total_slots);
    UT_LOG("Return Status: %d", result);

    if((total_slots == 1) || (total_slots == 2))
    {
        UT_LOG("total number of uicc_slots %u which is a valid value", total_slots);
        UT_PASS("cellular_hal_get_total_no_of_uicc_slots validation success");
    }
    else
    {
        UT_LOG("total number of uicc_slots is %u which is an invalid value", total_slots);
        UT_FAIL("cellular_hal_get_total_no_of_uicc_slots failed");
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive_1_get_total_no_of_uicc_slots...");
}


/**
* @brief Tests the functionality of the cellular_hal_get_uicc_slot_info function
*
* This test case verifies the correctness of the cellular_hal_get_uicc_slot_info function by invoking it with different input values and checking the Return Status and the values in the slot_info structure.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 010 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result| Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_uicc_slot_info function with valid slot index and slot info structure |  slot_index = valid value, slot_info = valid struct |  RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info...");
    int status = 0;
    unsigned int slot_index = 0;

    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof (CellularUICCSlotInfoStruct)) ;

    if(slot_info != NULL)
    {
        memset(slot_info, 0, sizeof(CellularUICCSlotInfoStruct));
        UT_LOG("Invoking cellular_hal_get_uicc_slot_info with valid input");
        status = cellular_hal_get_uicc_slot_info(slot_index, slot_info);
        UT_LOG("Return Status: %d", status);
        if(slot_info != NULL)
        {
            if(slot_info->SlotEnable == TRUE || slot_info->SlotEnable == FALSE)
            {
                UT_LOG("slot_info->SlotEnable is %d which is a valid value", slot_info->SlotEnable);
                UT_PASS("slot_info->SlotEnable validation success");
            }
            else
            {
                UT_LOG("slot_info->SlotEnable is %d which is an invalid value", slot_info->SlotEnable);
                UT_FAIL("slot_info->SlotEnable validation failed");
            }

            if(slot_info->IsCardPresent == TRUE || slot_info->IsCardPresent == FALSE)
            {
                UT_LOG("slot_info->IsCardPresent is %d which is a valid value", slot_info->IsCardPresent);
                UT_PASS("slot_info->IsCardPresent validation success");
            }
            else
            {
                UT_LOG("slot_info->IsCardPresent is %d which is an invalid value", slot_info->IsCardPresent);
                UT_FAIL("slot_info->IsCardPresent  validation failed");
            }        

            if(slot_info->CardEnable == TRUE || slot_info->CardEnable == FALSE)
            {
                UT_LOG("slot_info->CardEnable is %d which is a valid value", slot_info->CardEnable);
                UT_PASS("slot_info->CardEnable validation success");
            }
            else
            {
                UT_LOG("slot_info->CardEnable is %d which is an invalid value", slot_info->CardEnable);
                UT_FAIL("slot_info->CardEnable validation failed");
            }          

            if(slot_info->FormFactor == 0 || slot_info->FormFactor == 1 || slot_info->FormFactor == 2 || slot_info->FormFactor == 3)
            {
                UT_LOG("slot_info->FormFactor is %d which is a valid value", slot_info->FormFactor);
                UT_PASS("slot_info->FormFactor validation success");
            }
            else
            {
                UT_LOG("slot_info->FormFactor is %d which is an invalid value", slot_info->FormFactor);
                UT_FAIL("slot_info->FormFactor validation failed");
            }         

            if(slot_info->Application == 0 || slot_info->Application == 1 || slot_info->Application == 2)
            {
                UT_LOG("slot_info->Application is %d which is a valid value", slot_info->Application);
                UT_PASS("slot_info->Application validation success");
            }
            else
            {
                UT_LOG("slot_info->Application is %d which is an invalid value", slot_info->Application);
                UT_FAIL("slot_info->Application validation failed");
            }          

            if(slot_info->Status == 0 || slot_info->Status == 1 || slot_info->Status == 2 || slot_info->Status == 3 )
            {
                UT_LOG("slot_info->Status is %d which is a valid value", slot_info->Status);
                UT_PASS("slot_info->Status validation success");
            }
            else
            {
                UT_LOG("slot_info->Status is %d which is an invalid value", slot_info->Status);
                UT_FAIL("slot_info->Status validation failed");
            } 
            if(slot_info->MnoName == NULL || slot_info->MnoName[0] == '\0')
            {
                UT_LOG("slot_info->MnoName is empty string");
                UT_FAIL("slot_info->MnoName validation failed");
            }
            else
            {
                UT_LOG("slot_info->MnoName is %s",slot_info->MnoName);
                UT_PASS("slot_info->MnoName validation success");  

            } 
            if(slot_info->iccid == NULL || slot_info->iccid[0] == '\0')
            {
                UT_LOG("slot_info->iccid is empty string");
                UT_FAIL("slot_info->iccid validation failed");
            }
            else
            {
                UT_LOG("slot_info->iccid is %s",slot_info->iccid);
                UT_PASS("slot_info->iccid validation success");  
            }
            if(slot_info->msisdn == NULL || slot_info->msisdn[0] == '\0')
            {
                UT_LOG("slot_info->msisdn is empty string");
                UT_FAIL("slot_info->msisdn validation failed");
            }
            else            
            {
                UT_LOG("slot_info->msisdn is %s",slot_info->msisdn); 
                UT_PASS("slot_info->msisdn validation success"); 
            }
            free(slot_info);
        }
        else
        {
            UT_LOG("API RETURNS NULL POINTER");
            UT_FAIL("API RETURNS NULL POINTER");

        }
        UT_ASSERT_EQUAL(status, RETURN_OK);

    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info...");
}

/**
* @brief This test case is used to verify the functionality of the API cellular_hal_get_uicc_slot_info().
*
* This test case verifies the proper functioning of the API cellular_hal_get_uicc_slot_info() when using maximum value for slot_index by checking the Return Status and validating the structure fields.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 011 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_uicc_slot_info API with valid slot_index and slot_info structure | slot_index = valid max value, slot_info = valid structure | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info...");
    int status = 0;
    unsigned int slot_index = 4294967295;

    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof(CellularUICCSlotInfoStruct));

    if(slot_info != NULL)
    {
        memset(slot_info, 0, sizeof(CellularUICCSlotInfoStruct));
        UT_LOG("Invoking cellular_hal_get_uicc_slot_info with valid slot_index = 4294967295 and valid pointer to CellularUICCSlotInfoStruct");
        status = cellular_hal_get_uicc_slot_info(slot_index, slot_info);
        UT_LOG("Return Status: %d", status);
        if(slot_info != NULL)
        {
            if(slot_info->SlotEnable == TRUE || slot_info->SlotEnable == FALSE)
            {
                UT_LOG("slot_info->slotEnable is  %d which is a valid value", slot_info->SlotEnable);
                UT_PASS("slot_info->slotEnable validation success");
            }
            else
            {
                UT_LOG("slot_info->slotEnable is  %d which is an invalid value", slot_info->SlotEnable);
                UT_FAIL("slot_info->slotEnable validation failed");
            }

            if(slot_info->IsCardPresent == TRUE || slot_info->IsCardPresent == FALSE)
            {
                UT_LOG("slot_info->IsCardPresent is  %d which is a valid value", slot_info->IsCardPresent);
                UT_PASS("slot_info->IsCardPresent validation success");
            }
            else
            {
                UT_LOG("slot_info->IsCardPresent is  %d which is an invalid value", slot_info->IsCardPresent);
                UT_FAIL("slot_info->IsCardPresent validation failed");
            }

            if(slot_info->CardEnable == TRUE || slot_info->CardEnable == FALSE)
            {
                UT_LOG("slot_info->CardEnable is  %d which is a valid value", slot_info->CardEnable);
                UT_PASS("slot_info->CardEnable validation success");
            }
            else
            {
                UT_LOG("slot_info->CardEnable is  %d which is an invalid value", slot_info->CardEnable);
                UT_FAIL("slot_info->CardEnable validation failed");
            }

            if(slot_info->FormFactor == 0 || slot_info->FormFactor == 1 || slot_info->FormFactor == 2 || slot_info->FormFactor == 3)
            {
                UT_LOG("slot_info->FormFactor is  %d which is a valid value", slot_info->FormFactor);
                UT_PASS("slot_info->FormFactor validation success");
            }
            else
            {
                UT_LOG("slot_info->FormFactor is  %d which is an invalid value", slot_info->FormFactor);
                UT_FAIL("slot_info->FormFactor validation failed");
            }

            if(slot_info->Application == 0 || slot_info->Application == 1 || slot_info->Application == 2)
            {
                UT_LOG("slot_info->Application is  %d which is a valid value", slot_info->Application);
                UT_PASS("slot_info->Application validation success");
            }
            else
            {
                UT_LOG("slot_info->Application is  %d which is an invalid value", slot_info->Application);
                UT_FAIL("slot_info->Application validation failed");
            }        

            if(slot_info->Status == 0 || slot_info->Status == 1 || slot_info->Status == 2 || slot_info->Status == 3 )
            {
                UT_LOG("slot_info->Status is  %d which is a valid value", slot_info->Status);
                UT_PASS("slot_info->Status validation success");
            }
            else
            {
                UT_LOG("slot_info->Status is  %d which is an invalid value", slot_info->Status);
                UT_FAIL("slot_info->Status validation failed");
            }          
            if(slot_info->MnoName == NULL || slot_info->MnoName[0] == '\0')
            {
                UT_LOG("slot_info->MnoName is empty string");
                UT_FAIL("slot_info->MnoName validation failed");                
            }
            else
            {
                UT_LOG("slot_info->MnoName is %s",slot_info->MnoName); 
                UT_PASS("slot_info->MnoName validation success");  
            }
            if(slot_info->iccid == NULL || slot_info->iccid[0] == '\0')
            {
                UT_LOG("slot_info->iccid is empty string");
                UT_FAIL("slot_info->iccid validation failed");                
            }
            else
            {            
                UT_LOG("slot_info->iccid is %s",slot_info->iccid);
                UT_PASS("slot_info->iccid validation success");  
            }
            if(slot_info->msisdn == NULL || slot_info->msisdn[0] == '\0')
            {
                UT_LOG("slot_info->msisdn is empty string");
                UT_FAIL("slot_info->msisdn validation failed");                
            }
            else
            {            
                UT_LOG("slot_info->msisdn is %s",slot_info->msisdn);
                UT_PASS("slot_info->msisdn validation success");
            }
            free(slot_info);
        }
        else
        {
            UT_LOG("API RETURNS NULL POINTER");
            UT_FAIL("API RETURNS NULL POINTER");

        }
        UT_ASSERT_EQUAL(status, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info...");
}

/**
* @brief Test case to verify the behavior of the cellular_hal_get_uicc_slot_info function when invoked with invalid input arguments.
*
* This test case is used to verify that the cellular_hal_get_uicc_slot_info function behaves as expected when it is invoked with invalid input arguments, specifically with a NULL pointer as the output parameter.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 012 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_uicc_slot_info function with valid slot_index and NULL slot_info | slot_index = valid value, slot_info = NULL | RETURN_ERROR |Should return RETURN_ERROR |
*/
void test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info...");
    CellularUICCSlotInfoStruct *slot_info = NULL;
    int status = 0;
    unsigned int slot_index = 1;
    
    UT_LOG("Invoking cellular_hal_get_uicc_slot_info with NULL pointer ");
    status = cellular_hal_get_uicc_slot_info(slot_index, slot_info);
    UT_LOG("Return Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info...");
}

/**
* @brief Unit test to verify the behavior of the function cellular_hal_get_uicc_slot_info in negative scenario
*
* This test case verifies the behavior of the function cellular_hal_get_uicc_slot_info in a negative scenario. It checks if the function returns the expected status code for invalid slot_index.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 013 @n 
* **Priority:** High @n@n 
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_uicc_slot_info function with valid slot index| slot_index = invalid value | RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info...");
    int status = 0;
    unsigned int slot_index = 4294967296; 

    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof(CellularUICCSlotInfoStruct));
    if(slot_info != NULL)
    {
        memset(slot_info, 0, sizeof(CellularUICCSlotInfoStruct));
        UT_LOG("Invoking cellular_hal_get_uicc_slot_info with invalid slot_index ");
        status = cellular_hal_get_uicc_slot_info(slot_index, slot_info);
        UT_LOG("Return Status: %d", status);

        free(slot_info);
        UT_ASSERT_EQUAL(status, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info...");
}
/**
* @brief Test for checking the behaviour of "cellular_hal_get_active_card_status" in positive scenario
*
* This test is to verify that the function 'cellular_hal_get_active_card_status' correctly returns the active card status and it should be valid.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 014 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* |:----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_active_card_status function to get the active card status | card_status = valid pointer | RETURN_OK | should be success |
*/
void test_l1_cellular_hal_positive1_get_active_card_status(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_active_card_status...");
    int status = 0;
    CellularUICCStatus_t card_status = 0;

    UT_LOG("Invoking cellular_hal_get_active_card_status with valid card_status ");
    status = cellular_hal_get_active_card_status(&card_status);
    UT_LOG("Return Status: %d", status);

    if((card_status == 0) || (card_status == 1) || (card_status == 2) || (card_status == 3))
    {
        UT_LOG("active_card_status %d which is a valid value",card_status);
        UT_PASS("get_active_card_status validation success");
    }
    else
    {
        UT_LOG("active_card_status %d which is a invalid value",card_status);
        UT_FAIL("get_active_card_status validation fail");
    }

    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_active_card_status...");
}
/**
* @brief Test case to verify the functionality of the cellular_hal_get_profile_list function in positive scenario.
* 
* This test case checks whether the cellular_hal_get_profile_list function returns the correct result and does not crash when invoked with valid parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 015 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode,then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_profile_list  with valid profile and profile count| profiles = valid structure, profileCount = valid value | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_profile_list(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_profile_list...");
    int result = 0;
    int i = 0;
    int profileCount = 0;
    CellularProfileStruct *profiles = NULL;
    UT_LOG("Invoking cellular_hal_get_profile_list with valid parameters...");
    result = cellular_hal_get_profile_list(&profiles, &profileCount);
    UT_LOG("Return Status: %d", result);

    if(profiles != NULL)
    {
        UT_LOG("get_profile_list profileCount: %d",profileCount);
        if(profileCount > 0)
        {
            for(i = 0; i <profileCount; i++)
            {    
                UT_LOG("get_profile_list profile_ID: %d",profiles[i].ProfileID);
                UT_LOG("get_profile_list PDPContextNumber:%d",profiles[i].PDPContextNumber);

                if(profiles[i].ProfileType == 0 || profiles[i].ProfileType == 1 )
                {
                    UT_LOG("profiles[i].ProfileType is  %d which is a valid value", profiles[i].ProfileType);
                    UT_PASS("profiles[i].ProfileType validation success");
                }
                else
                {
                    UT_LOG("profiles[i].ProfileType is  %d which is an invalid value", profiles[i].ProfileType);
                    UT_FAIL("profiles[i].ProfileType validation failed");
                }

                if(profiles[i].PDPType == 0 || profiles[i].PDPType == 1 || profiles[i].PDPType == 2 || profiles[i].PDPType == 3)
                {
                    UT_LOG("profiles[i].PDPType is  %d which is a valid value", profiles[i].PDPType);
                    UT_PASS("profiles[i].PDPType validation success");
                }
                else
                {
                    UT_LOG("profiles[i].PDPType is  %d which is an invalid value", profiles[i].PDPType);
                    UT_FAIL("profiles[i].PDPType validation failed");
                }        

                if(profiles[i].PDPAuthentication == 0 || profiles[i].PDPAuthentication == 1 || profiles[i].PDPAuthentication == 2 )
                {
                    UT_LOG("profiles[i].PDPAuthentication is  %d which is a valid value", profiles[i].PDPAuthentication);
                    UT_PASS("profiles[i].PDPAuthentication validation success");
                }
                else
                {
                    UT_LOG("profiles[i].PDPAuthentication is  %d which is an invalid value", profiles[i].PDPAuthentication);
                    UT_FAIL("profiles[i].PDPAuthentication validation failed");
                }            

                if( profiles[i].bIsNoRoaming == TRUE || profiles[i].bIsNoRoaming == FALSE )
                {
                    UT_LOG("profiles[i].bIsNoRoaming is  %d which is a valid value", profiles[i].bIsNoRoaming);
                    UT_PASS("profiles[i].bIsNoRoaming validation success");
                }
                else
                {
                    UT_LOG("profiles[i].bIsNoRoaming is  %d which is an invalid value", profiles[i].bIsNoRoaming);
                    UT_FAIL("profiles[i].bIsNoRoaming validation failed");
                }         

                if( profiles[i].bIsAPNDisabled == TRUE || profiles[i].bIsAPNDisabled == FALSE )
                {
                    UT_LOG("profiles[i].bIsAPNDisabled is  %d which is a valid value", profiles[i].bIsAPNDisabled);
                    UT_PASS("profiles[i].bIsAPNDisabled validation success");
                }
                else
                {
                    UT_LOG("profiles[i].bIsAPNDisabled is  %d which is an invalid value", profiles[i].bIsAPNDisabled);
                    UT_FAIL("profiles[i].bIsAPNDisabled validation failed");
                }          

                if( profiles[i].bIsThisDefaultProfile == TRUE || profiles[i].bIsThisDefaultProfile == FALSE )
                {
                    UT_LOG("profiles[i].bIsThisDefaultProfile is  %d which is a valid value", profiles[i].bIsThisDefaultProfile);
                    UT_PASS("profiles[i].bIsThisDefaultProfile validation success");
                }
                else
                {
                    UT_LOG("profiles[i].bIsThisDefaultProfile is  %d which is an invalid value", profiles[i].bIsThisDefaultProfile);
                    UT_FAIL("profiles[i].bIsThisDefaultProfile validation failed");
                }      

                UT_LOG("get_profile_list ppstProfileOutput.PDPNetworkConfig %d",profiles[i].PDPNetworkConfig);

                if(profiles[i].ProfileName == NULL || profiles[i].ProfileName[0] == '\0')
                {
                    UT_LOG("profiles[i].ProfileName is empty string");
                    UT_FAIL("profiles[i].ProfileName validation failed");
                }
                else
                {
                    UT_LOG("get_profile_list profiles[i].ProfileName %s",profiles[i].ProfileName);
                    UT_PASS("profiles[i].ProfileName validation success");
                }
                if(profiles[i].APN == NULL || profiles[i].APN[0] == '\0')
                {
                    UT_LOG("profiles[i].APN is empty string");
                    UT_FAIL("profiles[i].APN validation failed");
                } 
                else
                {
                    UT_LOG("get_profile_list profiles[i].APN %s",profiles[i].APN);
                    UT_PASS("profiles[i].APN validation success");           
                }       
                if(profiles[i].Username == NULL || profiles[i].Username[0] == '\0')
                {
                    UT_LOG("profiles[i].Username is empty string");
                    UT_FAIL("profiles[i].Username validation failed");
                }
                else
                {
                    UT_LOG("get_profile_list profiles[i].Username %s",profiles[i].Username);
                    UT_PASS("profiles[i].Username validation success");
                }         
                if(profiles[i].Password == NULL || profiles[i].Password[0] == '\0')
                {
                    UT_LOG("profiles[i].Password is empty string");
                    UT_FAIL("profiles[i].Password validation failed");
                }
                else
                {
                    UT_LOG("get_profile_list profiles[i].Password %s",profiles[i].Password); 
                    UT_PASS("profiles[i].Password validation  success");
                }        
                if(profiles[i].Proxy == NULL || profiles[i].Proxy[0] == '\0')
                {
                    UT_LOG("profiles[i].Proxy is empty string");
                    UT_FAIL("profiles[i].Proxy validation failed");
                }
                else
                {
                    UT_LOG("get_profile_list profiles[i].Proxy %s",profiles[i].Proxy);
                    UT_PASS("profiles[i].Proxy validation success");
                }        
                
                UT_LOG("get_profile_list ppstProfileOutput.ProxyPort %d",profiles[i].ProxyPort);
            }
        }

        free(profiles);
    }
    else
    {
        UT_LOG("API RETURNS NULL POINTER");
        UT_FAIL("API RETURNS NULL POINTER");

    }
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_profile_list...");
}
/**
* @brief Tests the functionality of the l1_cellular_hal_negative2_get_profile_list function in negative scenario.
*
* This test is intended to verify the behavior of the l1_cellular_hal_negative2_get_profile_list function when passed a NULL profile_count parameter.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 016 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking the cellular_hal_get_profile_list function with NULL profile_count and valid ppstProfileOutput | ppstProfileOutput = valid structure, profilesCount = NULL | RETURN_ERROR | Should return an error |
*/
void test_l1_cellular_hal_negative2_get_profile_list(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative2_get_profile_list...");
    int *profileCount = NULL;
    int result = 0;

    CellularProfileStruct *profiles = NULL;

    UT_LOG("Invoking cellular_hal_get_profile_list with  *profile_count = NULL...");
    result = cellular_hal_get_profile_list(&profiles, profileCount);
    UT_LOG("Return Status: %d", result);
    
    free(profiles);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative2_get_profile_list...");
}

/**
* @brief Test the functionality of the cellular_hal_stop_network function when stopping the network with IPV4 IP type.
*
* This test case verifies the implementation of the cellular_hal_stop_network function when stopping the network with the IPV4 IP type. The function is expected to return a success status upon successfully stopping the network.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 017 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_stop_network API with IPV4 IP type as CELLULAR_NETWORK_IP_FAMILY_IPV4 | ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV4 | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV4;

    UT_LOG("Invoking cellular_hal_stop_network with ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV4...");
    result = cellular_hal_stop_network(ip_request_type);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_cellular_hal_stop_network...");
}

/**
* @brief This function tests the functionality of cellular_hal_stop_network function when stopping the network with CELLULAR_NETWORK_IP_FAMILY_UNKNOWN type.
*
* The purpose of this test is to verify the behavior of the cellular_hal_stop_network function and check if it returns the expected result when called with the given input parameters.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 018 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* |  01  | Invoke cellular_hal_stop_network function with ip_request_type as CELLULAR_NETWORK_IP_FAMILY_UNKNOWN| ip_request_type = CELLULAR_NETWORK_IP_FAMILY_UNKNOWN | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = CELLULAR_NETWORK_IP_FAMILY_UNKNOWN;

    UT_LOG("Invoking cellular_hal_stop_network with ip_request_type = CELLULAR_NETWORK_IP_FAMILY_UNKNOWN...");
    result = cellular_hal_stop_network(ip_request_type);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive2_cellular_hal_stop_network...");
}

/**
* @brief Test case to verify the behavior of cellular_hal_stop_network function when stopping the network with CELLULAR_NETWORK_IP_FAMILY_IPV6.
*
* This test case verifies the behavior of the cellular_hal_stop_network function when stopping the network. The test checks if the function returns the expected result when invoked with a specific input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 019 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* 01 | Invoke the cellular_hal_stop_network function with ip_request_type as CELLULAR_NETWORK_IP_FAMILY_IPV6 | ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV6 | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive3_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive3_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV6;

    UT_LOG("Invoking cellular_hal_stop_network with ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV6...");
    result = cellular_hal_stop_network(ip_request_type);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive3_cellular_hal_stop_network...");
}

/**
* @brief Test case to verify the behavior of the function 'cellular_hal_stop_network' when the input IP type is invalid.
*
* This test case checks the behavior of the function 'cellular_hal_stop_network' when an invalid IP type is provided as input. It is important to test this behavior as the function should handle such inputs properly and return an appropriate error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 020 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_stop_network with invalid ip_request_type | Invalid ip_request_type = 99 | RETURN_ERROR | Should return an error |
*/
void test_l1_cellular_hal_negative1_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = 99;

    UT_LOG("Invoking cellular_hal_stop_network with invalid ip_request_type = 99...");
    result = cellular_hal_stop_network(ip_request_type);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_cellular_hal_stop_network...");
}

/**
* @brief This test case validates the functionality of the cellular_hal_get_signal_info API with valid profile inputs and a callback.
*
* The purpose of this test is to verify that the cellular_hal_get_signal_info API returns the expected result when called with valid profile inputs and a callback.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 021 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, they must select the test case via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Call the cellular_hal_get_signal_info API with valid signal_info | signal_info = valid pointer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_signal_info(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_signal_info...");
    int result = 0;
    CellularSignalInfoStruct *signal_info = (CellularSignalInfoStruct*)malloc(sizeof(CellularSignalInfoStruct));

    if(signal_info != NULL)
    {
        memset(signal_info, 0, sizeof(CellularSignalInfoStruct));
        UT_LOG("Invoking cellular_hal_get_signal_info with valid value...");
        result = cellular_hal_get_signal_info(signal_info);
        UT_LOG("Return Status: %d", result);
        if(signal_info != NULL)
        {
            if((signal_info->RSSI <= -30) && (signal_info->RSSI >= -90))
            {
                UT_LOG("signal_info->RSSI is  %d which is a valid value", signal_info->RSSI);
                UT_PASS("signal_info->RSSI validation success");
            }
            else
            {
                UT_LOG("signal_info->RSSI is  %d which is an invalid value", signal_info->RSSI);
                UT_FAIL("signal_info->RSSI validation failed");
            }

            if((signal_info->RSRQ <= -3) && (signal_info->RSRQ >= -19.5))
            {
                UT_LOG("signal_info->RSRQ is  %d which is a valid value", signal_info->RSRQ);
                UT_PASS("signal_info->RSRQ validation success");
            }
            else
            {
                UT_LOG("signal_info->RSRQ is  %d which is an invalid value", signal_info->RSRQ);
                UT_FAIL("signal_info->RSRQ validation failed");
            }

            if((signal_info->RSRP <= -44) && (signal_info->RSRP >= -140))
            {
                UT_LOG("signal_info->RSRP is  %d which is a valid value", signal_info->RSRP);
                UT_PASS("signal_info->RSRP validation success");
            }
            else
            {
                UT_LOG("signal_info->RSRP is  %d which is an invalid value", signal_info->RSRP);
                UT_FAIL("signal_info->RSRP validation failed");
            }

            if((signal_info->SNR <= 30) && (signal_info->SNR >= -20))
            {
                UT_LOG("signal_info->SNR is  %d which is a valid value", signal_info->SNR);
                UT_PASS("signal_info->SNR validation success");
            }
            else
            {
                UT_LOG("signal_info->SNR is  %d which is an invalid value", signal_info->SNR);
                UT_FAIL("signal_info->SNR validation failed");
            }        

            if((signal_info->TXPower <= 30) && (signal_info->TXPower >= 0))
            {
                UT_LOG("signal_info->TXPower is  %d which is a valid value", signal_info->TXPower);
                UT_PASS("signal_info->TXPower validation success");
            }
            else
            {
                UT_LOG("signal_info->TXPower is  %d which is an invalid value", signal_info->TXPower);
                UT_FAIL("signal_info->TXPower validation failed");
            }

            free(signal_info);
        }
        else
        {
            UT_LOG("API RETURNS NULL POINTER");
            UT_FAIL("API RETURNS NULL POINTER");

        }
        UT_ASSERT_EQUAL(result, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_signal_info...");
}

/**
* @brief Test case to verify the behavior of the 'cellular_hal_get_signal_info' function when a null callback function is passed.
*
* This test case checks if the 'cellular_hal_get_signal_info' function returns the expected result when a null callback function is passed as an argument. This scenario is being tested to ensure that the function handles this edge case properly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 022 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_signal_info API with NULL signal_info | signal_info = NULL | RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_get_signal_info(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_signal_info...");
    int result = 0;
    CellularSignalInfoStruct *signal_info = NULL;

    UT_LOG("Invoking cellular_hal_get_signal_info with NULL signal_info");
    result = cellular_hal_get_signal_info(signal_info);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_signal_info...");
}

/**
* @brief Test to verify the functionality of the 'cellular_hal_set_modem_operating_configuration' API.
*
* This test case focuses on verifying the functionality of the 'cellular_hal_set_modem_operating_configuration' API by setting a valid modem operating configuration and checking the Return Status.
*
* **Test Group ID:** Basic:01 @n
* **Test Case ID:** 023 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_operating_configuration with modem_operating_config as CELLULAR_MODEM_SET_ONLINE | modem_operating_config = CELLULAR_MODEM_SET_ONLINE | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_set_modem_operating_configuration(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_set_modem_operating_configuration...");
    int result = 0;
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_ONLINE;

    UT_LOG("Invoking cellular_hal_set_modem_operating_configuration with valid modem_operating_config %d", modem_operating_config );
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_set_modem_operating_configuration...");
}

/**
* @brief Test to verify the functionality of the 'cellular_hal_set_modem_operating_configuration' API.
*
* This test case focuses on verifying the functionality of the 'cellular_hal_set_modem_operating_configuration' API by setting a valid modem operating configuration and checking the Return Status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 024 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_operating_configuration with valid modem_operating_config as CELLULAR_MODEM_SET_OFFLINE| modem_operating_config = CELLULAR_MODEM_SET_OFFLINE | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_set_modem_operating_configuration(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_set_modem_operating_configuration...");
    int result = 0;
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_OFFLINE;

    UT_LOG("Invoking cellular_hal_set_modem_operating_configuration with valid modem_operating_config %d", modem_operating_config);
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive2_set_modem_operating_configuration...");
}

/**
* @brief Test to verify the functionality of the cellular_hal_set_modem_operating_configuration API.
*
* This test case focuses on verifying the functionality of the cellular_hal_set_modem_operating_configuration API by setting a valid modem operating configuration and checking the Return Status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 025 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_operating_configuration with valid modem_operating_config as CELLULAR_MODEM_SET_LOW_POWER_MODE | modem_operating_config = CELLULAR_MODEM_SET_LOW_POWER_MODE | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive3_set_modem_operating_configuration(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive_3_set_modem_operating_configuration...");
    int result = 0;
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_LOW_POWER_MODE;

    UT_LOG("Invoking cellular_hal_set_modem_operating_configuration with valid modem_operating_config %d", modem_operating_config);
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive_3_set_modem_operating_configuration...");
}

/**
* @brief Test to verify the functionality of the cellular_hal_set_modem_operating_configuration API.
*
* This test case focuses on verifying the functionality of the cellular_hal_set_modem_operating_configuration API by setting a valid modem operating configuration and checking the Return Status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 026 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_operating_configuration with valid modem_operating_config as CELLULAR_MODEM_SET_RESET | modem_operating_config = CELLULAR_MODEM_SET_RESET | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive4_set_modem_operating_configuration(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive_4_set_modem_operating_configuration...");
    int result = 0;
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_RESET;

    UT_LOG("Invoking cellular_hal_set_modem_operating_configuration with valid modem_operating_config %d", modem_operating_config);
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive_4_set_modem_operating_configuration...");
}

/**
* @brief Test to verify the functionality of the cellular_hal_set_modem_operating_configuration API.
*
* This test case focuses on verifying the functionality of the cellular_hal_set_modem_operating_configuration API by setting a valid modem operating configuration and checking the Return Status.
*
* **Test Group ID:** Basic : 01 @n
* **Test Case ID:** 027 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via . @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 |Invoke cellular_hal_set_modem_operating_configuration with valid modem_operating_config as CELLULAR_MODEM_SET_FACTORY_RESET | modem_operating_config = CELLULAR_MODEM_SET_FACTORY_RESET | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive5_set_modem_operating_configuration(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive_5_set_modem_operating_configuration...");
    int result = 0;
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_FACTORY_RESET;

    UT_LOG("Invoking cellular_hal_set_modem_operating_configuration with valid modem_operating_config %d", modem_operating_config);
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive_5_set_modem_operating_configuration...");
}

/**
* @brief Test case to verify the behavior of the function when an invalid profile type is provided.
*
* This test case is used to verify the behavior of the function "cellular_hal_set_modem_operating_configuration" when an invalid profile type is provided as input. The objective of this test is to ensure that the function returns the expected result when invoked with an invalid profile type.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 028 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_operating_configuration with invalid modem_operating_config as 100 | modem_operating_config = 100 | RETURN_ERROR | Should return error |
*/
void test_l1_cellular_hal_negative1_set_modem_operating_configuration(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_operating_configuration...");
    int result = 0;
    CellularModemOperatingConfiguration_t modem_operating_config = 100;

    UT_LOG("Invoking cellular_hal_set_modem_operating_configuration with invalid modem_operating_config %d", modem_operating_config);
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_operating_configuration...");
}

/**
* @brief This test is to verify the functionality of the "cellular_hal_get_device_imei_sv" API.
*
* The purpose of this test is to ensure that the "cellular_hal_get_device_imei_sv" API returns the IMEI of the device correctly. This test is part of the Basic test group and has a high priority.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 029 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_device_imei_sv with valid imei buffer | imei = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_device_imei_sv(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_device_imei_sv...");
    int status = 0;    
    char imei[16] = {"\0"};

    UT_LOG("Invoking cellular_hal_get_device_imei_sv with valid imei buffer");
    status = cellular_hal_get_device_imei_sv(imei);
    UT_LOG("Return Status: %d", status);
    if(imei == NULL || imei[0] == '\0')
    {
        UT_LOG("imei is empty string");
        UT_FAIL("cellular_hal_get_device_imei_sv validation failed");
    }
    else
    {
        UT_LOG("imei :%s",imei);
        UT_PASS("imei validation success");
    }
    UT_ASSERT_EQUAL(status, RETURN_OK);
    
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_device_imei_sv...");
}

/**
* @brief Test case to validate the negative scenario of the cellular_hal_get_device_imei_sv API.
*
* This test case verifies the behavior of cellular_hal_get_device_imei_sv API when the input parameter imei is NULL.
* 
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 030 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_device_imei_sv API with NULL imei | imei = NULL | RETURN_ERROR |should return an error |
*/
void test_l1_cellular_hal_negative1_get_device_imei_sv(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_device_imei_sv...");
    int status = 0;    
    char *imei = NULL;

    UT_LOG("Invoking cellular_hal_get_device_imei_sv with imei as NULL");
    status = cellular_hal_get_device_imei_sv(imei);
    UT_LOG("Return Status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_device_imei_sv...");
}

/**
* @brief Test to validate the functionality of retrieving the IMEI from the modem.
*
* The objective of this test is to ensure that the function cellular_hal_get_device_imei() returns a valid IMEI value and a success status when provided with a valid IMEI buffer.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 031 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_device_imei with valid imei buffer  | imei = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_device_imei( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_device_imei...");
    char imei[16] = {"\0"};
    int status = 0;    

    UT_LOG("Invoking cellular_hal_get_device_imei with valid imei");
    status = cellular_hal_get_device_imei(imei);
    UT_LOG("Return Status: %d", status);
    if(imei == NULL || imei[0] == '\0')
    {
        UT_LOG("imei is empty string");
        UT_FAIL("cellular_hal_get_device_imei validation failed");       
    }
    else
    {
        UT_LOG("imei : %s",imei);
        UT_PASS("cellular_hal_get_device_imei validation success")
    }

    UT_ASSERT_EQUAL(status, RETURN_OK);
   
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_device_imei...");
}

/**
* @brief This test is used to verify the behavior when a NULL IMEI buffer is passed to the cellular_hal_get_device_imei function.
*
* The purpose of this test is to ensure that the function handles the case of a NULL IMEI buffer correctly and returns the expected status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 032 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_device_imei with NULL imei buffer | imei = NULL |  RETURN_ERROR | Should return error |
*/
void test_l1_cellular_hal_negative1_get_device_imei( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_device_imei...");
    char* imei = NULL;
    int status = 0;    

    UT_LOG("Invoking cellular_hal_get_device_imei with NULL imei buffer");
    status = cellular_hal_get_device_imei(imei);
    UT_LOG("Return Status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_device_imei...");
}

/**
* @brief Unit test to verify the functionality of retrieving the ICCID from the modem.
*
* This test case verifies the functionality of the "cellular_hal_get_modem_current_iccid" API by retrieving the ICCID from the modem and checking the Return Status and the retrieved ICCID.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 033 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_modem_current_iccid API with valid iccid buffer | iccid = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_current_iccid(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_iccid...");
    int status = 0;
    char iccid[21] = {"\0"};

    UT_LOG("Invoking ellular_hal_get_modem_current_iccid API with valid iccid buffer");
    status = cellular_hal_get_modem_current_iccid(iccid);
    UT_LOG("Return Status: %d", status);

    if(iccid != NULL || iccid[0] != '\0')
    { 
        UT_LOG("get_modem_current_iccid  is %s", iccid);
        UT_PASS (" get_modem_current_iccid validation success");
    }
    else
    {
        UT_LOG("get_modem_current_iccid returns empty string");
        UT_FAIL(" get_modem_current_iccid validation Failure");    
    }
    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_iccid...");
}

/**
* @brief Test case to verify the behavior of retrieving modem ICCID when the ICID buffer is NULL.
*
* This test case checks if the function properly handles the scenario when the ICCID buffer is NULL and returns an error status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 034 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result| Notes|
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_modem_current_iccid function with a NULL ICCID buffer| iccid = NULL| RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_get_modem_current_iccid(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_current_iccid...");
    int status = 0;
    char* iccid = NULL;

    UT_LOG("Invoking cellular_hal_get_modem_current_iccid with NULL iccid");
    status = cellular_hal_get_modem_current_iccid(iccid);
    UT_LOG("Return Status: %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_current_iccid...");
}

/**
* @brief This is a positive test case to verify the functionality of the cellular_hal_get_modem_current_msisdn function.
*
* This test case verifies if the function retrieves the current MSISDN (Mobile Subscriber Integrated Services Digital Network Number) from the modem correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 035 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_modem_current_msisdn with valid msisdn buffer | msisdn = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_current_msisdn(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_msisdn...");
    int result = 0;
    char msisdn[20] = {"\0"};

    UT_LOG("Invoking cellular_hal_get_modem_current_msisdn with valid msisdn buffer");
    result = cellular_hal_get_modem_current_msisdn(msisdn);
    UT_LOG("Return Status : %d", result);
    if(msisdn == NULL || msisdn[0] == '\0')
    {
        UT_LOG("msisdn is empty string");
        UT_FAIL("cellular_hal_get_modem_current_msisdn validation failed");
    }
    else
    {
        UT_LOG("modem_current_msisdn Value: %s", msisdn);
        UT_PASS("cellular_hal_get_modem_current_msisdn validation success");
    }

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_msisdn...");
}

/**
* @brief This is a negative test case to verify the functionality of the cellular_hal_get_modem_current_msisdn function .
*
* This test case verifies if the function  handles correctly when NULL is passed as MSISDN
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 036 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_modem_current_msisdn function with NULL msisdn  | msisdn = NULL | RETURN_ERROR | Should return an error |
*/
void test_l1_cellular_hal_negative1_get_modem_current_msisdn(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_current_msisdn...");
    int result = 0;
    char *msisdn = NULL;

    UT_LOG("Invoked cellular_hal_get_modem_current_msisdn with NULL msisdn");
    result = cellular_hal_get_modem_current_msisdn(msisdn);
    UT_LOG("Return Status : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_current_msisdn...");
}

/**
* @brief Test case to check for the functionality of the 'cellular_hal_get_packet_statistics' function 
*
* This test case is meant to verify the functionality of the function with valid network packet stats pointer .
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 037 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_packet_statistics function with valid network_packet_stats | network_packet_stats = valid pointer| RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_packet_statistics(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_packet_statistics...");
    int result = 0;
    CellularPacketStatsStruct *network_packet_stats = (CellularPacketStatsStruct*) malloc(sizeof(CellularPacketStatsStruct));

    if(network_packet_stats != NULL)
    {
        memset(network_packet_stats, 0, sizeof(CellularPacketStatsStruct));
        UT_LOG("Invoking cellular_hal_get_packet_statistics with valid network_packet_stats");
        result = cellular_hal_get_packet_statistics(network_packet_stats);
        UT_LOG("Return Status: %d", result);
        if(network_packet_stats != NULL)
        {
            UT_LOG("cellular_hal_get_packet_statistics BytesSent :%lu",network_packet_stats->BytesSent);
            UT_LOG("cellular_hal_get_packet_statistics BytesReceived :%lu",network_packet_stats->BytesReceived);
            UT_LOG("cellular_hal_get_packet_statistics PacketsSent :%lu",network_packet_stats->PacketsSent);
            UT_LOG("cellular_hal_get_packet_statistics PacketsReceived :%lu",network_packet_stats->PacketsReceived);
            UT_LOG("cellular_hal_get_packet_statistics PacketsSentDrop :%lu",network_packet_stats->PacketsSentDrop);
            UT_LOG("cellular_hal_get_packet_statistics PacketsReceivedDrop :%lu",network_packet_stats->PacketsReceivedDrop);
            UT_LOG("cellular_hal_get_packet_statistics UpStreamMaxBitRate  :%lu",network_packet_stats->UpStreamMaxBitRate);
            UT_LOG("cellular_hal_get_packet_statistics DownStreamMaxBitRate :%lu",network_packet_stats->DownStreamMaxBitRate);

            free(network_packet_stats);
        }
        else
        {
            UT_LOG("API RETURNS NULL POINTER");
            UT_FAIL("API RETURNS NULL POINTER");
        }
        UT_ASSERT_EQUAL(result, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_packet_statistics...");
}

/**
* @brief Test case to check for the functionality of the 'cellular_hal_get_packet_statistics' function  when NULL is passed as arguement
*
* This test case is meant to verify the functionality of the function with NULL is passed as  network packet stats pointer .
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 038 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_packet_statistics function with NULL network_packet_stats | network_packet_stats = NULL| RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_get_packet_statistics(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_packet_statistics...");
    int result = 0;
    CellularPacketStatsStruct *network_packet_stats = NULL;

    UT_LOG("Invoking cellular_hal_get_packet_statistics with NULL network_packet_stats");
    result = cellular_hal_get_packet_statistics(network_packet_stats);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_packet_statistics...");
}

/**
* @brief Test case to verify the behavior of the function cellular_hal_get_current_modem_interface_status when invoked with a positive input.
*
* This test case checks if the function cellular_hal_get_current_modem_interface_status returns the correct result and updates the output values when invoked with a positive input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 039 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_current_modem_interface_status with valid status value | status = valid value | RETURN_OK | Should be success |
*/
void test_l1_cellular_hal_positive1_get_current_modem_interface_status( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_current_modem_interface_status...");
    CellularInterfaceStatus_t status = 0 ;
    int result = 0;

    UT_LOG("Invoking cellular_hal_get_current_modem_interface_status with valid status value");
    result = cellular_hal_get_current_modem_interface_status(&status);
    UT_LOG("Return Status: %d", result);
    UT_LOG("modem interface status value: %d", status);

    if ((status == 1) || (status == 2) || (status == 3) || (status == 4) || (status == 5) || (status == 6) || (status == 7))
    {
        UT_LOG("get_current_modem_interface_status %d which is a valid value",status);
        UT_PASS("get_current_modem_interface_status validation success");
    }
    else
    {
        UT_LOG("get_current_modem_interface_status %d which is a Invalid value",status);
        UT_FAIL("get_current_modem_interface_status validation fail");
    }
    
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_current_modem_interface_status...");
}

/**
* @brief This test is to verify the behavior of the function `cellular_hal_get_current_modem_interface_status` when providing a NULL pointer as the input parameter.
*
* The objective of this test is to ensure that the function handles the NULL pointer input correctly and returns the expected result.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 040 @n
* **Priority:** High  @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Call the cellular_hal_get_current_modem_interface_status API with NULL status | status = NULL | RETURN_ERROR | Should return the error value |
*/
void test_l1_cellular_hal_negative1_get_current_modem_interface_status( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_current_modem_interface_status...");
    int result = 0;
    CellularInterfaceStatus_t *status = NULL;

    UT_LOG("Invoking cellular_hal_get_current_modem_interface_status with NULL status");
    result = cellular_hal_get_current_modem_interface_status(status);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_current_modem_interface_status...");
}

/**
* @brief This test is to verify the behavior of the function cellular_hal_set_modem_network_attach .
*
* The purpose of this test is to ensure that the function returns RETURN_ERROR  
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 041 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_network_attach function when the network is not possible| None | RETURN_ERROR | Should return error |
*/
void test_l1_cellular_hal_negative1_set_modem_network_attach(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_network_attach...");
    int result = 0;

    UT_LOG("Invoking cellular_hal_set_modem_network_attach function");
    result = cellular_hal_set_modem_network_attach();
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_network_attach...");
}

/**
* @brief Test to verify the behavior of the function 'cellular_hal_set_modem_network_detach' when detaching from the network is not possible.
*
* This test verifies the behavior of the 'cellular_hal_set_modem_network_detach' function when detaching from the network is not possible. The API is expected to return an error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 042 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_negative1_set_modem_network_detach function when the network is not possible| None | RETURN_ERROR | Should return an error code |
*/
void test_l1_cellular_hal_negative1_set_modem_network_detach( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_network_detach...");
    int result = 0;   

    UT_LOG("Invoking cellular_hal_negative1_set_modem_network_detach function");
    result = cellular_hal_set_modem_network_detach();
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_network_detach...");
}

/**
* @brief This test function is to validate the retrieval of firmware version.
*
* The objective of this test is to check if the function `cellular_hal_get_modem_firmware_version` returns firmware version correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 043 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_modem_firmware_version function with valid firmware_version buffer| firmware_version = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_firmware_version(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_firmware_version...");
    char firmware_version[128] = {"\0"};
    int result = 0;

    UT_LOG("Invoking cellular_hal_get_modem_firmware_version with valid firmware_version buffer");
    result = cellular_hal_get_modem_firmware_version(firmware_version);
    UT_LOG("Return Status : %d", result);

    if(firmware_version != NULL || firmware_version[0] != '\0')
    { 
        UT_LOG("get_modem_firmware_version  is %s", firmware_version);
        UT_PASS (" get_modem_firmware_version success");
    }
    else
    {
        UT_LOG("get_modem_firmware_version returns empty string");
        UT_FAIL(" get_modem_firmware_version Failure");    
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_firmware_version..");
}


/**
* @brief Test to verify the functionality of cellular_hal_get_current_plmn_information function.
*
* This test checks if the cellular_hal_get_current_plmn_information function returns the expected status and fills in the plmn_info structure correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 044 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_current_plmn_information with valid plmn_info structure | plmn_info = valid structure | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_current_plmn_information(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_current_plmn_information...");
    int status = 0;
    CellularCurrentPlmnInfoStruct *plmn_info = (CellularCurrentPlmnInfoStruct*)malloc(sizeof(CellularCurrentPlmnInfoStruct));

    if(plmn_info != NULL)
    {
        memset(plmn_info, 0, sizeof(CellularCurrentPlmnInfoStruct));
        UT_LOG("Invoking cellular_hal_get_current_plmn_information with valid plmn_info structure.");
        status = cellular_hal_get_current_plmn_information(plmn_info);
        UT_LOG("Return Status: %d", status);
        
        if(plmn_info != NULL)
        {            
            if(plmn_info->plmn_name == NULL || plmn_info->plmn_name[0] == '\0')
            {
                UT_LOG("plmn_info->plmn_name is empty string");
                UT_FAIL("plmn_info->plmn_name validation failed");
            }
            else
            {
                UT_LOG("cellular_hal_get_current_plmn_information plmn_name :%s",plmn_info->plmn_name);
                UT_PASS("plmn_info->plmn_name validation success");
            }

            if((plmn_info->MCC >= 0) && (plmn_info->MCC <= 999))
            {
                UT_LOG("plmn_info->MCC is  %d which is a valid value", plmn_info->MCC);
                UT_PASS("plmn_info->MCC validation success");
            }
            else
            {
                UT_LOG("plmn_info->MCC is  %d which is an invalid value", plmn_info->MCC);
                UT_FAIL("plmn_info->MCC validation failed");
            }

            if((plmn_info->MNC >= 0) && (plmn_info->MNC <= 999))
            {
                UT_LOG("plmn_info->MNC is  %d which is a valid value", plmn_info->MNC);
                UT_PASS("plmn_info->MNC validation success");
            }
            else
            {
                UT_LOG("plmn_info->MNC is  %d which is an invalid value", plmn_info->MNC);
                UT_FAIL("plmn_info->MNC validation failed");
            }        

            if((plmn_info->roaming_enabled >= 0) && (plmn_info->roaming_enabled <= 255))
            {
                UT_LOG("plmn_info->roaming_enabled is  %d which is a valid value", plmn_info->roaming_enabled);
                UT_PASS("plmn_info->roaming_enabled validation success");
            }
            else
            {
                UT_LOG("plmn_info->roaming_enabled is  %d which is an invalid value", plmn_info->roaming_enabled);
                UT_FAIL("plmn_info->roaming_enabled validation failed");
            } 

            if((plmn_info->area_code >= 0) && (plmn_info->area_code <= 2147483647))
            {
                UT_LOG("plmn_info->area_code is  %d which is a valid value", plmn_info->area_code);
                UT_PASS("plmn_info->area_code validation success");
            }
            else
            {
                UT_LOG("plmn_info->area_code is  %d which is an invalid value", plmn_info->area_code);
                UT_FAIL("plmn_info->area_code validation failed");
            } 

            if((plmn_info->cell_id >= 0) && (plmn_info->cell_id <= 4294967295))
            {
                UT_LOG("plmn_info->cell_id is  %lu which is a valid value", plmn_info->cell_id);
                UT_PASS("plmn_info->cell_id validation success");
            }
            else
            {
                UT_LOG("plmn_info->cell_id is  %lu which is an invalid value", plmn_info->cell_id);
                UT_FAIL("plmn_info->cell_id validation failed");
            }                

            if((plmn_info->registration_status == 1) || (plmn_info->registration_status == 2))
            {
                UT_LOG("plmn_info->registration_status is  %d which is a valid value", plmn_info->registration_status);
                UT_PASS("plmn_info->registration_status validation success");
            }
            else
            {
                UT_LOG("plmn_info->registration_status is  %d which is an invalid value", plmn_info->registration_status);
                UT_FAIL("plmn_info->registration_status validation failed");
            }         

            if((plmn_info->registered_service == 1) || (plmn_info->registered_service == 2) || (plmn_info->registered_service == 3) || (plmn_info->registered_service ==0))
            {
                UT_LOG("plmn_info->registered_service is  %d which is a valid value", plmn_info->registered_service);
                UT_PASS("plmn_info->registered_service validation success");
            }
            else
            {
                UT_LOG("plmn_info->registered_service is  %d which is an invalid value", plmn_info->registered_service);
                UT_FAIL("plmn_info->registered_service validation failed");
            }         
            free(plmn_info);
        }
        else
        {
            UT_LOG("API RETURNS NULL POINTER");
            UT_FAIL("API RETURNS NULL POINTER");

        }
        UT_ASSERT_EQUAL(status, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_current_plmn_information...");
}

/**
* @brief This test function verifies the behavior of cellular_hal_get_current_plmn_information when passed a NULL plmn_info structure.
*
* The objective of this test is to ensure that the API correctly handles the case when a NULL plmn_info structure is passed as an argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 045 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_current_plmn_information with NULL plmn_info structure. | plmn_info = NULL | RETURN_ERROR| Should return an error status code. |
*/
void test_l1_cellular_hal_negative1_get_current_plmn_information(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_current_plmn_information...");
    int status = 0;
    CellularCurrentPlmnInfoStruct *plmn_info = NULL;

    UT_LOG("Invoking cellular_hal_get_current_plmn_information with NULL plmn_info structure");
    status = cellular_hal_get_current_plmn_information(plmn_info);
    UT_LOG("Return Status : %d", status);
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_current_plmn_information...");
}

/**
* @brief This test case is used to verify the functionality of the function cellular_hal_get_available_networks_information().
*
* This test case is used to test the functionality of the function cellular_hal_get_available_networks_information(). This function is responsible for retrieving available network information from the cellular module.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 046 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_available_networks_information API with valid network_info structure and total_network_count |network_info = valid structure, total_network_count = valid value| RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_available_networks_information(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_available_networks_information...");
    int status = 0; 
    int i = 0; 
    unsigned int total_network_count = 0 ; 
    CellularNetworkScanResultInfoStruct *network_info = NULL;

    UT_LOG("invoking cellular_hal_get_available_networks_information with  network_info pointer and total_network_count");
    status = cellular_hal_get_available_networks_information(&network_info, &total_network_count);
    UT_LOG("Return Status : %d", status);
    if(network_info != NULL)
    {
        UT_LOG("cellular_hal_get_available_networks_information total_network_count :%d ",total_network_count);
        if(total_network_count > 0)
        {
            for(i = 0; i < total_network_count; i++)
            {
                if(network_info[i].network_name == NULL || network_info[i].network_name[0] == '\0')
                {
                    UT_LOG("network_info[i].network_name is empty string");
                    UT_FAIL("cellular_hal_get_available_networks_information validation failed");
                } 
                else
                {
                    UT_LOG("cellular_hal_get_available_networks_information network_name : %s",network_info[i].network_name);
                    UT_PASS("network_info[i].network_name validation success");
                }   

                if((network_info[i].MCC >= 0) && (network_info[i].MCC <= 999))
                {
                    UT_LOG("network_info[i].MCC is  %d which is a valid value", network_info[i].MCC);
                    UT_PASS("network_info[i].MCC validation success");
                }
                else
                {
                    UT_LOG("network_info[i].MCC is  %d which is an invalid value", network_info[i].MCC);
                    UT_FAIL("network_info[i].MCC validation failed");
                }

                if((network_info[i].MNC >= 0) && (network_info[i].MNC <= 999))
                {
                    UT_LOG("network_info[i].MNC is  %d which is a valid value", network_info[i].MNC);
                    UT_PASS("network_info[i].MNC validation success");
                }
                else
                {
                    UT_LOG("network_info[i].MNC is  %d which is an invalid value", network_info[i].MNC);
                    UT_FAIL("network_info[i].MNC validation failed");
                }

                if(network_info[i].network_allowed_flag == TRUE || network_info[i].network_allowed_flag == FALSE)
                {
                    UT_LOG("network_info[i].network_allowed_flag is  %d which is a valid value", network_info[i].network_allowed_flag);
                    UT_PASS("network_info[i].network_allowed_flag validation success");
                }
                else
                {
                    UT_LOG("network_info[i].network_allowed_flag is  %d which is an invalid value", network_info[i].network_allowed_flag);
                    UT_FAIL("network_info[i].network_allowed_flag validation failed");
                }
            }       
        }

        free(network_info);
    }
    else
    {
        UT_LOG("API RETURNS NULL POINTER");
        UT_FAIL("API RETURNS NULL POINTER");

    }
    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_available_networks_information...");
}



/**
* @brief This test function is used to verify the functionality of the "cellular_hal_get_modem_preferred_radio_technology" API.
*
* The objective of this test is to ensure that the API returns the preferred radio technology correctly.test_l1_cellular_hal_positive1_get_modem_current_radio_technology
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 047 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_modem_preferred_radio_technology API with valid preferred radio technology buffer| preferred_rat = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology...");
    char preferred_rat[128] = {"\0"};
    int ret = 0;

    UT_LOG("Invoking cellular_hal_get_modem_preferred_radio_technology with valid character array preferred_rat..."); 
    ret = cellular_hal_get_modem_preferred_radio_technology(preferred_rat); 
    UT_LOG("Return Status : %d", ret);

    if(preferred_rat == NULL || preferred_rat[0] == '\0')
    {
        UT_LOG("preferred radio technology is empty string");
        UT_FAIL("preferred radio technology is empty string");
    }

    else if(!strcmp(preferred_rat, "AUTO") || !strcmp(preferred_rat, "CDMA20001X") || !strcmp(preferred_rat, "EVDO") || !strcmp(preferred_rat, "GSM") || !strcmp(preferred_rat, "UMTS") || !strcmp(preferred_rat, "LTE"))
    {
        UT_LOG("preferred radio technology is  %s which is a valid value",preferred_rat);
        UT_PASS("modem_preferred_radio_technology validation success");
    }

    else
    {
        UT_LOG("preferred radio technology is  %s which is a Invalid value",preferred_rat);
        UT_FAIL("modem_preferred_radio_technology fail");
    }

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology...");
}

/**
* @brief This test verifies the functionality of the 'cellular_hal_get_modem_preferred_radio_technology' API when a NULL pointer is passed as input.
*
* This test case tests the behavior of the 'cellular_hal_get_modem_preferred_radio_technology' API when a NULL pointer is passed as input. It checks if the API returns the expected error value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 048 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_modem_preferred_radio_technology with NULL preferred radio technology buffer | preferred_rat = NULL | RETURN_ERROR | Should return error |
*/
void test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology...");
    int ret = 0;
    char *preferred_rat = NULL;

    UT_LOG("Invoking cellular_hal_get_modem_preferred_radio_technology with NULL preferred radio technology buffer"); 
    ret = cellular_hal_get_modem_preferred_radio_technology(preferred_rat); 
    UT_LOG("Return Status: %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology...");
}

/**
* @brief Test function to verify if it sets valid Modem preferred Radio Technologies passed.
*
* The objective of this test is to verify that the cellular_hal_set_modem_preferred_radio_technology functions correctly with valid value "UMTS"
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 049 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_set_modem_preferred_radio_technology function with valid preferred_rat buffer as "UMTS" | preferred_rat = "UMTS" | RETURN_OK |Should be successful | 
*/
void test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology...");
    int result = 0;
    char preferred_rat[128] = "LTE" ; //"UMTS"

    UT_LOG("Invoking cellular_hal_set_modem_preferred_radio_technology with valid preferred_rat = \"{LTE / AUTO}\"");  
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology...");
}

/**
* @brief Test function to verify if it sets valid Modem preferred Radio Technologies.
*
* The objective of this test is to verify that the cellular_hal_set_modem_preferred_radio_technology functions correctly with valid value as "AUTO"
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 050 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:**  @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the cellular_hal_set_modem_preferred_radio_technology function with valid preferred_rat buffer as "AUTO" | preferred_rat = "AUTO"| RETURN_OK |Should be successful | 
*/
void test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology...");
    char preferred_rat[128] = "AUTO" ; //"AUTO";
    int result = 0;

    UT_LOG("Invoking cellular_hal_set_modem_preferred_radio_technology with valid preferred_rat = \"{GSM / AUTO}\"");  
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology...");
}



/**
* @brief Test to validate the behavior when a null pointer is passed as input to the API.
*
* This test verifies the behavior of the API when a null pointer is passed as input. It checks whether the API handles the null pointer correctly and returns the expected error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 051 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_preferred_radio_technology API with null preferred_rat | preferred_rat = NULL | RETURN_ERROR | Should return error code |
*/
void test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology...");
    char* preferred_rat = NULL;
    int result = 0;

    UT_LOG("Invoking cellular_hal_set_modem_preferred_radio_technology with NULL  preferred_rat");  
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology...");
}

/**
* @brief Test case to verify the behavior of the API when an invalid status value is provided.
*
* This test case checks the behavior of the API when an invalid status value is provided as input. The purpose of this test is to ensure that the function handles invalid status values correctly and returns the expected results.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 052 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_set_modem_preferred_radio_technology API with invalid preferred_rat | preferred_rat = "Unknown_TECH" | RETURN_ERROR | Should return an error code |
*/
void test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology...");
    char preferred_rat[128] = "Unknown_TECH";
    int result = 0;

    UT_LOG("Invoking cellular_hal_set_modem_preferred_radio_technology with invalid input preferred_rat = Unknown_TECH");
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology...");
}

/**
* @brief Test function to verify if it sets valid Modem preferred Radio Technologies.
*
* The objective of this test is to verify that the cellular_hal_set_modem_preferred_radio_technology functions correctly with valid value as "LTE,UMTS".
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 053 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the cellular_hal_set_modem_preferred_radio_technology function with valid preferred_rat buffer as "LTE,UMTS" | preferred_rat "LTE,UMTS" |RETURN_OK  |Should be successful | 
*/
void test_l1_cellular_hal_negative3_set_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_negative3_set_modem_preferred_radio_technology...");
    char preferred_rat[128] = "UMTS";
    int result = 0;

    UT_LOG("Invoking cellular_hal_set_modem_preferred_radio_technology with valid preferred_rat = \"{LTE / UMTS}\"");  
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative3_set_modem_preferred_radio_technology...");
}
/**
* @brief Test the function get_modem_current_radio_technology_lte of the L1 Cellular HAL module.
*
* This test checks if the function get_modem_current_radio_technology_lte returns the correct current RAT (Radio Access Technology) for LTE.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 054 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_modem_current_radio_technology with valid  current_rat buffer | current_rat = valid buffer | RETURN_OK| Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_current_radio_technology( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_radio_technology...");
    int result = 0;
    char current_rat[128] = {"\0"};

    UT_LOG("Invoking cellular_hal_get_modem_current_radio_technology with valid buffer current_rat  ...");
    result = cellular_hal_get_modem_current_radio_technology(current_rat);
    UT_LOG("Return Status: %d", result);

    if(current_rat == NULL || current_rat[0] == '\0')
    {
        UT_LOG("current radio technology is empty string");
        UT_FAIL("get_modem_current_radio_technology fail");
    }

    else if (!strcmp(current_rat,"AUTO") || !strcmp(current_rat,"CDMA20001X") || !strcmp(current_rat,"EVDO") || !strcmp(current_rat,"GSM")||  !strcmp(current_rat,"UMTS") || !strcmp(current_rat,"LTE") || !strcmp(current_rat,"UMTS,LTE"))
    {
        UT_LOG("current radio technology %s which is a valid value",current_rat);
        UT_PASS("get_modem_current_radio_technology validation success");
    }

    else
    {
        UT_LOG("current radio technologyy %s which is a Invalid value",current_rat);
        UT_FAIL("get_modem_current_radio_technology fail");
    }

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_radio_technology...");
}
/**
* @brief This test verifies the behavior of the function `cellular_hal_get_modem_current_radio_technology` when a null pointer is provided as the input argument.
*
* This test case is part of the Basic (L1) test group and has a high priority as it tests a fundamental functionality of the API.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 055 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_modem_current_radio_technology function with NULL current_rat buffer  | current_rat = NULL | RETURN_ERROR | Should return error |
*/
void test_l1_cellular_hal_negative1_get_modem_current_radio_technology( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_current_radio_technology...");
    int result = 0;
    char *current_rat = NULL;

    UT_LOG("Invoking cellular_hal_get_modem_current_radio_technology with NULL current_rat buffer");
    result = cellular_hal_get_modem_current_radio_technology(current_rat);
    UT_LOG("Return Status: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_current_radio_technology...");
}

/**
* @brief Test case to verify the behavior when failed to attach to the network in cellular_hal_get_modem_current_radio_technology
*
* This test case verifies the behavior of the cellular_hal_get_modem_current_radio_technology function when it fails to attach to the network.
*
* **Test Group ID:** Basic : 01 @n
* **Test Case ID:** 056 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description  | Test Data  | Expected Result  | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* |  01 | Invoke the cellular_hal_get_modem_supported_radio_technology function with valid supported_rat buffer | supported_rat = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_supported_radio_technology( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_radio_technology...");
    char supported_rat[128] = {"\0"};
    int status = 0;

    UT_LOG("Invoking cellular_hal_get_modem_supported_radio_technology with valid supported_rat buffer");
    status = cellular_hal_get_modem_supported_radio_technology(supported_rat);
    UT_LOG("Return Status: %d", status);
    if(supported_rat == NULL || supported_rat[0] == '\0')
    {
        UT_LOG("supported_radio_technology is empty string");
        UT_FAIL("cellular_hal_get_modem_supported_radio_technology validation failed");
    }
    else
    {
        UT_LOG("supported_rat is %s", supported_rat);
        UT_PASS("cellular_hal_get_modem_supported_radio_technology validation  success");
    }

    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_supported_radio_technology...");
}

/**
* @brief Unit test for the function cellular_hal_get_modem_supported_radio_technology
*
* This test verifies the functionality of the function cellular_hal_get_modem_supported_radio_technology by passing invalid parameters and checking if the return value is as expected.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 057 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_modem_supported_radio_technology with NULL supported_rat |  supported_rat = NULL| RETURN_ERROR | Should return error |
*/
void test_l1_cellular_hal_negative1_get_modem_supported_radio_technology(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_supported_radio_technology...");
    int ret = 0;
    char *supported_rat = NULL;

    UT_LOG("Invoking cellular_hal_get_modem_supported_radio_technology with supported_rat as NULL");
    ret = cellular_hal_get_modem_supported_radio_technology(supported_rat);
    UT_LOG("Return Status: %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_supported_radio_technology...");
}

/**
* @brief Test the positive scenario of the function cellular_hal_modem_factory_reset.
*
* This test verifies that the function cellular_hal_modem_factory_reset returns the expected result.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 058 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the function cellular_hal_modem_factory_reset | None | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_modem_factory_reset(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_modem_factory_reset...");   
    int result = 0;

    UT_LOG("Invoking cellular_hal_modem_factory_reset function");
    result = cellular_hal_modem_factory_reset();
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_modem_factory_reset...");
}

/**
* @brief This test case is used to verify the functionality of the cellular_hal_modem_reset function. 
*
* The purpose of this test is to ensure that the function cellular_hal_modem_reset is able to reset the modem successfully.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 059 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_modem_reset function| None | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_cellular_hal_modem_reset(void) 
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_modem_reset...");
    int result = 0;

    UT_LOG("Invoking cellular_hal_modem_reset function");
    result = cellular_hal_modem_reset();
    UT_LOG("Return Status : %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_cellular_hal_modem_reset...");
}

static UT_test_suite_t * pSuite = NULL;

/**
* @brief Register the main tests for this module
*
* @return int - 0 on success, otherwise failure
*/

int init_cellular_hal_init()
{
    UT_LOG("ENTERING INTO cellular_hal_init FUNCTION");
    int result = 0;
    CellularContextInitInputStruct *pstCtxInputStruct = (CellularContextInitInputStruct*) malloc(sizeof(CellularContextInitInputStruct)) ;
    if(pstCtxInputStruct != NULL)
    { 
        memset(pstCtxInputStruct, 0, sizeof(CellularContextInitInputStruct));
        UT_LOG("Invoking cellular_hal_init.........");                
        result = cellular_hal_init(pstCtxInputStruct);
        UT_LOG("Return status : %d",result);
        free(pstCtxInputStruct);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("EXITING  cellular_hal_init FUNCTION");
    return 0;
}

int teardown()
{
    UT_LOG("suit [L1_cellular_hal] completed");
    return 0;
}

int test_cellular_hal_l1_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1_cellular_hal]", init_cellular_hal_init, teardown);
    if (pSuite == NULL) 
    {
        return -1;
    }

   
    UT_add_test( pSuite, "l1_cellular_hal_positive1_IsModemDevicePresent", test_l1_cellular_hal_positive1_IsModemDevicePresent);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_init", test_l1_cellular_hal_positive1_init);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_sim_power_enable", test_l1_cellular_hal_positive1_sim_power_enable);
    UT_add_test( pSuite, "l1_cellular_hal_positive2_sim_power_enable", test_l1_cellular_hal_positive2_sim_power_enable);
    UT_add_test( pSuite, "l1_cellular_hal_positive3_sim_power_enable", test_l1_cellular_hal_positive3_sim_power_enable);
    UT_add_test( pSuite, "l1_cellular_hal_positive4_sim_power_enable", test_l1_cellular_hal_positive4_sim_power_enable);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_sim_power_enable", test_l1_cellular_hal_negative1_sim_power_enable);
    UT_add_test( pSuite, "l1_cellular_hal_negative2_sim_power_enable", test_l1_cellular_hal_negative2_sim_power_enable);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_total_no_of_uicc_slots", test_l1_cellular_hal_positive1_get_total_no_of_uicc_slots);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info", test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info);
    UT_add_test( pSuite, "l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info", test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info", test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info);
    UT_add_test( pSuite, "l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info", test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_active_card_status", test_l1_cellular_hal_positive1_get_active_card_status);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_profile_list", test_l1_cellular_hal_positive1_get_profile_list);
    UT_add_test( pSuite, "l1_cellular_hal_negative2_get_profile_list", test_l1_cellular_hal_negative2_get_profile_list);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_cellular_hal_stop_network", test_l1_cellular_hal_positive1_cellular_hal_stop_network);
    UT_add_test( pSuite, "l1_cellular_hal_positive2_cellular_hal_stop_network", test_l1_cellular_hal_positive2_cellular_hal_stop_network);
    UT_add_test( pSuite, "l1_cellular_hal_positive3_cellular_hal_stop_network", test_l1_cellular_hal_positive3_cellular_hal_stop_network);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_cellular_hal_stop_network", test_l1_cellular_hal_negative1_cellular_hal_stop_network);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_signal_info", test_l1_cellular_hal_positive1_get_signal_info);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_signal_info", test_l1_cellular_hal_negative1_get_signal_info);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_set_modem_operating_configuration", test_l1_cellular_hal_positive1_set_modem_operating_configuration);
    UT_add_test( pSuite, "l1_cellular_hal_positive2_set_modem_operating_configuration", test_l1_cellular_hal_positive2_set_modem_operating_configuration);
    UT_add_test( pSuite, "l1_cellular_hal_positive3_set_modem_operating_configuration", test_l1_cellular_hal_positive3_set_modem_operating_configuration);
    UT_add_test( pSuite, "l1_cellular_hal_positive4_set_modem_operating_configuration", test_l1_cellular_hal_positive4_set_modem_operating_configuration);
    UT_add_test( pSuite, "l1_cellular_hal_positive5_set_modem_operating_configuration", test_l1_cellular_hal_positive5_set_modem_operating_configuration);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_set_modem_operating_configuration", test_l1_cellular_hal_negative1_set_modem_operating_configuration);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_device_imei_sv", test_l1_cellular_hal_positive1_get_device_imei_sv);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_device_imei_sv", test_l1_cellular_hal_negative1_get_device_imei_sv);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_device_imei", test_l1_cellular_hal_positive1_get_device_imei);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_device_imei", test_l1_cellular_hal_negative1_get_device_imei);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_modem_current_iccid", test_l1_cellular_hal_positive1_get_modem_current_iccid);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_modem_current_iccid", test_l1_cellular_hal_negative1_get_modem_current_iccid);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_modem_current_msisdn", test_l1_cellular_hal_positive1_get_modem_current_msisdn);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_modem_current_msisdn", test_l1_cellular_hal_negative1_get_modem_current_msisdn);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_packet_statistics", test_l1_cellular_hal_positive1_get_packet_statistics);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_packet_statistics", test_l1_cellular_hal_negative1_get_packet_statistics);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_current_modem_interface_status", test_l1_cellular_hal_positive1_get_current_modem_interface_status);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_current_modem_interface_status", test_l1_cellular_hal_negative1_get_current_modem_interface_status);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_set_modem_network_attach", test_l1_cellular_hal_negative1_set_modem_network_attach);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_set_modem_network_detach", test_l1_cellular_hal_negative1_set_modem_network_detach);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_modem_firmware_version", test_l1_cellular_hal_positive1_get_modem_firmware_version);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_current_plmn_information", test_l1_cellular_hal_positive1_get_current_plmn_information);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_current_plmn_information", test_l1_cellular_hal_negative1_get_current_plmn_information);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_available_networks_information", test_l1_cellular_hal_positive1_get_available_networks_information);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_modem_preferred_radio_technology", test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_modem_preferred_radio_technology", test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_set_modem_preferred_radio_technology", test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_positive2_set_modem_preferred_radio_technology", test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_set_modem_preferred_radio_technology", test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_negative2_set_modem_preferred_radio_technology", test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_negative3_set_modem_preferred_radio_technology", test_l1_cellular_hal_negative3_set_modem_preferred_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_modem_current_radio_technology", test_l1_cellular_hal_positive1_get_modem_current_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_modem_current_radio_technology", test_l1_cellular_hal_negative1_get_modem_current_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_get_modem_supported_radio_technology", test_l1_cellular_hal_positive1_get_modem_supported_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_negative1_get_modem_supported_radio_technology", test_l1_cellular_hal_negative1_get_modem_supported_radio_technology);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_modem_factory_reset", test_l1_cellular_hal_positive1_modem_factory_reset);
    UT_add_test( pSuite, "l1_cellular_hal_positive1_cellular_hal_modem_reset", test_l1_cellular_hal_positive1_cellular_hal_modem_reset);

    return 0;
}












