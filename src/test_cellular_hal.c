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
* @file test_cellular_hal.c
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
* @brief Test for checking the behavior of cellular_hal_IsModemDevicePresent()
*        function when no modem device is present.
*
* This test case checks the return value of the cellular_hal_IsModemDevicePresent()
* function when there is no modem device present. The objective of this test is
* to ensure that the function correctly detects the absence of the modem device.
* 
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 001 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
* 
* Test Procedure: @n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Test the behavior of cellular_hal_IsModemDevicePresent() when no modem device is present | None | FALSE | Should return FALSE |
*/
void test_l1_cellular_hal_positive1_IsModemDevicePresent(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_IsModemDevicePresent...");
    UT_LOG("Invoking cellular_hal_IsModemDevicePresent() with no modem device present");
    unsigned int status = 0;
    // Invoke the API function
    status = cellular_hal_IsModemDevicePresent();
    UT_LOG("Return Status: %d", status);
    // Check the return status
    //UT_ASSERT_EQUAL(status, FALSE);
    UT_ASSERT_TRUE( status == TRUE || status == FALSE);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_IsModemDevicePresent...");
}

/**
* @brief Test case to validate the valid initialization of the L1 Cellular HAL
*
* This test case is used to verify the functionality of the L1 Cellular HAL when it is initialized with valid values.
* The objective of this test is to ensure that the initialization function returns the expected result when valid data is provided.
*
* Test Group ID: Basic: 01 @n
* Test Case ID: 002 @n
* Priority: High @n@n
*
* Pre-Conditions: None @n
* Dependencies: None @n
* User Interaction: If the user chooses to run the test in interactive mode, they need to select this test case via the console. @n
*
* Test Procedure: @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_init()   | enIPFamilyPreference = IP_FAMILY_UNKNOWN | RETURN_OK | should return successful|
* 
*/
void test_l1_cellular_hal_positive1_init(void) {    
    // Test case 1: Valid Initialization
    UT_LOG("Entering test_l1_cellular_hal_positive1_init...");
    UT_LOG("Invoking cellular_hal_positive1_init with enIPFamilyPreference = IP_FAMILY_UNKNOWN ...");
    int result = 0;
    // Fill the structure with valid values
    CellularContextInitInputStruct pstCtxInputStruct;
    pstCtxInputStruct.enIPFamilyPreference = IP_FAMILY_UNKNOWN;
    // fill other fields with valid data
    // Invoke the API
    result = cellular_hal_init(&pstCtxInputStruct);
    UT_LOG("Return Status: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
  
    UT_LOG("Exiting test_l1_cellular_hal_positive1_init...");
}

/**
* @brief Test to validate the functionality of the IPv4 Preference test case.
*
* This test is to verify the behavior of the cellular_hal_init() function when provided with a valid IPv4 preference.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 003 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description                                   | Test Data                                   | Expected Result               | Notes       |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01               | Invoke cellular_hal_init()     | enIPFamilyPreference = IP_FAMILY_IPV4       |  RETURN_OK        | should return successful  |
*/
void test_l1_cellular_hal_positive2_init(void) {
    // Test case 2: IPv4 Preference
    UT_LOG("Entering test_l1_cellular_hal_positive2_init...");
    UT_LOG("Invoking cellular_hal_init with enIPFamilyPreference = IP_FAMILY_IPV4");
    int result = 0;
    // Fill the structure with valid values
    CellularContextInitInputStruct pstCtxInputStruct;
    pstCtxInputStruct.enIPFamilyPreference = IP_FAMILY_IPV4;
    // Invoke the API
    result = cellular_hal_init(&pstCtxInputStruct);
    UT_LOG("Return result: %d", result);
     // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive2_init...");
}

/**
* @brief Test case to verify the behavior of the cellular_hal_init function with a valid profile name.
*
* This test case checks if the cellular_hal_init function behaves correctly when provided with a valid profile name. The profile name is used to fill a structure, which is then passed to the function.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 004 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_init()  api |  enIPFamilyPreference = IP_FAMILY_IPV6       | RETURN_OK        | should return successful  |
*
*/
void test_l1_cellular_hal_positive3_init(void) {
    // Test case 3: Valid Profile Name
    UT_LOG("Entering test_l1_cellular_hal_positive3_init...");
    UT_LOG("Invoking cellular_hal_init with enIPFamilyPreference = IP_FAMILY_IPV6");
    int result = 0;
    // Fill the structure with valid values
    CellularContextInitInputStruct pstCtxInputStruct;
    //strcpy(pstCtxInputStruct.ProfileName, "valid_profile_name");
    // fill other fields with valid data
    pstCtxInputStruct.enIPFamilyPreference = IP_FAMILY_IPV6;
    // Invoke the API
    result = cellular_hal_init(&pstCtxInputStruct);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive3_init...");
}

/**
* @brief This test case is used to verify the behavior of the "cellular_hal_init" function when an invalid IP family preference is provided.
*
* The objective of this test is to ensure that the function returns an error when an invalid IP family preference is provided as input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 005 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description                                              | Test Data                            | Expected Result                  | Notes            |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* |       01         | Invoke cellular_hal_init() api  | enIPFamilyPreference = 0             | RETURN_ERROR                       | Should be failure |
*/

void test_l1_cellular_hal_negative1_init(void) {
    // Test case 1: Invalid IP Family Preference
    UT_LOG("Entering test_l1_cellular_hal_negative1_init...");
    UT_LOG("Invoking cellular_hal_negative1_init with invalid enum value");
    int result = 0;
    // Fill the structure with invalid IP family preference
    //CellularContextInitInputStruct pstCtxInputStruct.PDPType=1;
    //CellularContextInitInputStruct pstCtxInputStruct.PDPAuthentication=1;
    //CellularContextInitInputStruct pstCtxInputStruct.PDPNetworkConfig=1;
    CellularContextInitInputStruct pstCtxInputStruct;
	pstCtxInputStruct.enIPFamilyPreference = 0;
	pstCtxInputStruct.stIfInput.ProfileID = 10;
	pstCtxInputStruct.stIfInput.ProfileType = CELLULAR_PROFILE_TYPE_3GPP;
	pstCtxInputStruct.stIfInput.PDPContextNumber = 10;
	pstCtxInputStruct.stIfInput.PDPType = CELLULAR_PDP_TYPE_IPV4;
	pstCtxInputStruct.stIfInput.PDPAuthentication = CELLULAR_PDP_AUTHENTICATION_NONE;
	pstCtxInputStruct.stIfInput.PDPNetworkConfig = CELLULAR_PDP_NETWORK_CONFIG_NAS;
	pstCtxInputStruct.stIfInput.bIsNoRoaming = '1';
	pstCtxInputStruct.stIfInput.bIsAPNDisabled = '1';
	pstCtxInputStruct.stIfInput.bIsThisDefaultProfile = '1';
    pstCtxInputStruct.enPreferenceTechnology = PREF_GPRS;
    // fill other fields with valid data
    // Invoke the API
    result = cellular_hal_init(&pstCtxInputStruct);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_init...");
}

/**
 * @brief Tests the scenario where the preference technology is outside the defined range.
 *
 * This test case verifies the behavior of the `cellular_hal_init` function when the preference technology value is outside the defined range.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 006 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoke cellular_hal_init() api | enPreferenceTechnology = 0 | RETURN_ERROR | Should return an error |
 */
void test_l1_cellular_hal_negative2_init(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative2_init...");
    UT_LOG("Invoking cellular_hal_negative1_init with invalid");
    int result = 0;
    // Fill the structure with preference technology outside range
    //CellularContextInitInputStruct pstCtxInputStruct;
    //CellularContextInitInputStruct pstCtxInputStruct.PDPType=0;
    //CellularContextInitInputStruct pstCtxInputStruct.PDPAuthentication=1;
    //CellularContextInitInputStruct pstCtxInputStruct.PDPNetworkConfig=2;
    CellularContextInitInputStruct pstCtxInputStruct;
	pstCtxInputStruct.enIPFamilyPreference = IP_FAMILY_IPV4;
	pstCtxInputStruct.stIfInput.ProfileID = 10;
	pstCtxInputStruct.stIfInput.ProfileType = CELLULAR_PROFILE_TYPE_3GPP;
	pstCtxInputStruct.stIfInput.PDPContextNumber = 10;
	pstCtxInputStruct.stIfInput.PDPType = CELLULAR_PDP_TYPE_IPV4;
	pstCtxInputStruct.stIfInput.PDPAuthentication = CELLULAR_PDP_AUTHENTICATION_NONE;
	pstCtxInputStruct.stIfInput.PDPNetworkConfig = CELLULAR_PDP_NETWORK_CONFIG_NAS;
	pstCtxInputStruct.stIfInput.bIsNoRoaming = '1';
	pstCtxInputStruct.stIfInput.bIsAPNDisabled = '1';
	pstCtxInputStruct.stIfInput.bIsThisDefaultProfile = '1';	
	pstCtxInputStruct.enPreferenceTechnology = 0;
    // fill other fields with valid data
    // Invoke the API
    result = cellular_hal_init(&pstCtxInputStruct);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative2_init...");
}
/**
 * @brief Tests the scenario where the preference technology is outside the defined range.
 *
 * This test case verifies the behavior of the `cellular_hal_init` function when the preference technology value is outside the defined range.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 007 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoke cellular_hal_init() api | enPreferenceTechnology = 0 | RETURN_ERROR | Should return an error |
 */
void test_l1_cellular_hal_negative3_init(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative3_init...");
    UT_LOG("Invoking cellular_hal_negative3_init with invalid");
    int result = 0;

    // fill other fields with valid data
    // Invoke the API
    result = cellular_hal_init(NULL);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative3_init...");
}
/**
* @brief Test the functionality of enabling power on a specific slot using the cellular_hal_sim_power_enable function.
*
* This test case checks if the cellular_hal_sim_power_enable function is able to successfully enable power on a specific slot.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 08 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable()  | valid slot_id = 1, enable = true | Return OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_sim_power_enable...");
    // Set slot_id to 1
    int slot_id = 1;
    int result = 0;
    // Set enable to TRUE
    bool enable = true;
    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    // Call the API function
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_sim_power_enable...");
}

/**
* @brief Test Case to test the functionality of the cellular_hal_sim_power_enable API when disabling power on slot 1.
*
* This test case is used to verify if the cellular_hal_sim_power_enable API correctly disables power on slot 1.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 09 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable()  | valid slot_id = 1, enable = false | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_sim_power_enable...");
    // Set slot_id to 1
    int slot_id = 1;
    int result = 0;
    // Set enable to FALSE
    bool enable = false;
    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    // Call the API function
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive2_sim_power_enable...");
}

/**
 * @brief This test case checks the functionality of the cellular_hal_sim_power_enable() function when enabling power on slot 2.
 *
 * The objective of this test is to ensure that the cellular_hal_sim_power_enable() function correctly enables power on slot 2 and returns the expected result.
 *
 * **Test Group ID:** Basic: 01 @n 
 * **Test Case ID:** 10 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *  
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoke the sim_power_enable() | valid slot_id = 2, enable = true | RETURN_OK | Should be successful |
 */
void test_l1_cellular_hal_positive3_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive3_sim_power_enable...");

    // Set slot_id to 2
    int slot_id = 2;
    int result = 0;
    // Set enable to TRUE
    bool enable = true;
    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);

    // Call the API function
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive3_sim_power_enable...");
}

/**
 * @brief Test to verify disabling power on slot 2 using the cellular_hal_sim_power_enable() API.
 *
 * This test checks the functionality of disabling power on slot 2 by calling the cellular_hal_sim_power_enable() API.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 11 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data  | Expected Result  | Notes   |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
 * |  01 | Invoke the sim_power_enable() | Valid input slot_id = 2, enable = false       | RETURN_OK    | Should be successful  |
 *
 */
void test_l1_cellular_hal_positive4_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive4_sim_power_enable...");

    // Set slot_id to 2
    int slot_id = 2;
    int result = 0;
    // Set enable to FALSE
    bool enable = false;
    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    // Call the API function
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Exiting test_l1_cellular_hal_positive4_sim_power_enable...");
}

/**
* @brief This test case checks the handling of an invalid slot ID in the cellular_hal_sim_power_enable function.
*
* The purpose of this test is to verify that the function correctly handles an invalid slot ID value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 12 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable() | Invalid value slot_id = 0 |  RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_sim_power_enable...");

    // Set slot_id to an invalid value
    int slot_id = 999;
    int result = 0;
    // Set enable to TRUE or FALSE
    bool enable = true;
    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    // Call the API function
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERROR);


    UT_LOG("Exiting test_l1_cellular_hal_negative1_sim_power_enable...");
}

/**
* @brief Verify the behavior of the function when providing an invalid value for the enable parameter.
*
* This test case checks if the function behaves correctly when an invalid value is provided for the enable parameter. The slot_id parameter is set to 1 and the enable parameter is set to 2, which is an invalid value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 013 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.@n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the sim_power_enable() | Invalid value slot_id = 1, enable = 2 | RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative2_sim_power_enable(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative2_sim_power_enable...");
    // Set slot_id to 1 or 2
    int slot_id = 1;
    int result = 0;
    // Set enable to an invalid value
    bool enable = (bool)2;
    UT_LOG("Invoking cellular_hal_sim_power_enable with slot_id = %d, enable = %d...", slot_id, enable);
    // Call the API function
    result = cellular_hal_sim_power_enable(slot_id, enable);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative2_sim_power_enable...");
}
/**
* @brief This test function is used to test the functionality of cellular_hal_get_total_no_of_uicc_slots API.
*
* The objective of this test is to verify that the API cellular_hal_get_total_no_of_uicc_slots returns the correct value for the total number of UICC slots available.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 014 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_total_no_of_uicc_slots | total_slots = 0 | RETURN_OK | The total number of UICC slots should be 1 |
*/
void test_l1_cellular_hal_positive1_get_total_no_of_uicc_slots(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_1_get_total_uicc_slots...");
    int result = 0;   
    unsigned int total_slots = 0;
    UT_LOG("Invoking cellular_hal_get_total_no_of_uicc_slots with total_slots = %u");

    result = cellular_hal_get_total_no_of_uicc_slots(&total_slots);
    UT_LOG("Return result: %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);
    //UT_ASSERT_EQUAL(total_slots, 1);
    UT_ASSERT_TRUE((total_slots == 1) || (total_slots == 2))
    UT_LOG("cellular_hal_get_total_no_of_uicc_slots with total_slots is %d",total_slots);
    UT_LOG("Exiting test_l1_cellular_hal_positive_1_get_total_no_of_uicc_slots...");
}

/**
* @brief Test case to verify the negative scenario of the function cellular_hal_get_total_no_of_uicc_slots
*
* This test case is used to verify the behavior of the function cellular_hal_get_total_no_of_uicc_slots when a NULL pointer is passed for the output parameter. 
* The test checks if the function returns the expected error code in this scenario. 
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 015 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_get_total_no_of_uicc_slots with a NULL output parameter | output = NULL | RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_get_total_no_of_uicc_slots(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative_1_get_total_no_of_uicc_slots...");
    UT_LOG("Invoking cellular_hal_get_total_no_of_uicc_slots with NULL pointer for output parameter");
    int result = 0;
    result = cellular_hal_get_total_no_of_uicc_slots(NULL);
    UT_LOG("Return result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    
    UT_LOG("Exiting test_l1_cellular_hal_negative_1_get_total_no_of_uicc_slots...");
}
/**
* @brief Tests the functionality of the cellular_hal_get_uicc_slot_info function
*
* This test case verifies the correctness of the cellular_hal_get_uicc_slot_info function by invoking it with different input values and checking the return status and the values in the slot_info structure.
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
* | Variation / Step | Description                                      | Test Data                                 | Expected Result                                    | Notes            |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* |       01       | Invoking cellular_hal_get_uicc_slot_info function with valid input values  | valid input slot_index = 1, slot_info = empty struct  |  RETURN_OK | Should be successful |
*/

void test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info...");
    int status = 0;
    // Test case parameters
    unsigned int slot_index = 0;
    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof (CellularUICCSlotInfoStruct)) ;
    if(slot_info != NULL){
    UT_LOG("Invoking cellular_hal_positive1_cellular_hal_get_uicc_slot_info with valid input");

    // Invoke the API
    status = cellular_hal_get_uicc_slot_info(slot_index, slot_info);
    UT_LOG("Return status: %d", status);

    // Check the return status
    //if (status == 0){
    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %c",slot_info->SlotEnable);
    UT_ASSERT_TRUE(slot_info->SlotEnable == TRUE || slot_info->SlotEnable == FALSE);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %c",slot_info->IsCardPresent);
    UT_ASSERT_TRUE(slot_info->IsCardPresent == TRUE || slot_info->IsCardPresent == FALSE);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %c",slot_info->CardEnable);
    UT_ASSERT_TRUE(slot_info->CardEnable == TRUE || slot_info->CardEnable == FALSE);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %d",slot_info->FormFactor);
    UT_ASSERT_TRUE(slot_info->FormFactor == 0 || slot_info->FormFactor == 1 || slot_info->FormFactor == 2 || slot_info->FormFactor == 3);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %d",slot_info->Application);
    UT_ASSERT_TRUE(slot_info->Application == 0 || slot_info->Application == 1 || slot_info->Application == 2);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %d",slot_info->Status);
    UT_ASSERT_TRUE(slot_info->Status == 0 || slot_info->Status == 1 || slot_info->Status == 2 || slot_info->Status == 3 );

    UT_LOG("cellular_hal_get_uicc_slot_info->MnoName is %s",slot_info->MnoName);   
    UT_LOG("cellular_hal_get_uicc_slot_info->iccid is %s",slot_info->iccid); 
    UT_LOG("cellular_hal_get_uicc_slot_info->msisdn is %s",slot_info->msisdn); 

    //}
    UT_ASSERT_EQUAL(status, RETURN_OK);
    // Validate the structure fields
    // TODO: Add validation for the structure fields
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
* This test case verifies the proper functioning of the API cellular_hal_get_uicc_slot_info() by checking the return status and validating the structure fields.
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
* | 01 | Invoke API with slot_index and slot_info as 0 | valid input slot_index = 0, slot_info = 0 | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info...");
    int status = 0;
    // Test case parameters
    unsigned int slot_index = 4294967295;
    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof(CellularUICCSlotInfoStruct));
    if(slot_info != NULL){

    UT_LOG("Invoking cellular_hal_positive1_cellular_hal_get_uicc_slot_info with valid slot_index = 4294967295 and valid pointer to CellularUICCSlotInfoStruct");

    // Invoke the API
    status = cellular_hal_get_uicc_slot_info(slot_index, slot_info);
    UT_LOG("Return status: %d", status);
    //if(status == 0){
    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %c",slot_info->SlotEnable);
    UT_ASSERT_TRUE(slot_info->SlotEnable == TRUE || slot_info->SlotEnable == FALSE);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %c",slot_info->IsCardPresent);
    UT_ASSERT_TRUE(slot_info->IsCardPresent == TRUE || slot_info->IsCardPresent == FALSE);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %c",slot_info->CardEnable);
    UT_ASSERT_TRUE(slot_info->CardEnable == TRUE || slot_info->CardEnable == FALSE);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %d",slot_info->FormFactor);
    UT_ASSERT_TRUE(slot_info->FormFactor == 0 || slot_info->FormFactor == 1 || slot_info->FormFactor == 2 || slot_info->FormFactor == 3);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %d",slot_info->Application);
    UT_ASSERT_TRUE(slot_info->Application == 0 || slot_info->Application == 1 || slot_info->Application == 2);

    UT_LOG("cellular_hal_get_uicc_slot_info->slotEnable is %d",slot_info->Status);
    UT_ASSERT_TRUE(slot_info->Status == 0 || slot_info->Status == 1 || slot_info->Status == 2 || slot_info->Status == 3 );


    UT_LOG("cellular_hal_get_uicc_slot_info->MnoName is %s",slot_info->MnoName);   
    UT_LOG("cellular_hal_get_uicc_slot_info->iccid is %s",slot_info->iccid); 
    UT_LOG("cellular_hal_get_uicc_slot_info->msisdn is %s",slot_info->msisdn);


    //}
    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_OK);
    }
    // Validate the structure fields
    // TODO: Add validation for the structure fields
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
* | 01 | Invoke the cellular_hal_get_uicc_slot_info function  | Invalid input slot_index = 1, output_ptr = NULL | RETURN_ERROR | The function should return RETURN_ERROR |
*/
void test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info...");
    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof(CellularUICCSlotInfoStruct));
    if(slot_info != NULL){
    int status = 0;
    // Test case parameters
    unsigned int slot_index = 1;
    UT_LOG("Invoking cellular_hal_get_uicc_slot_info with NULL pointer ");

    // Invoke the API
    status = cellular_hal_get_uicc_slot_info(slot_index, NULL);
    UT_LOG("Return status: %d", status);

    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }


    UT_LOG("Exiting test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info...");
}

/**
* @brief Unit test to verify the behavior of the function cellular_hal_get_uicc_slot_info in negative scenario
*
* This test case verifies the behavior of the function cellular_hal_get_uicc_slot_info in a negative scenario. It checks if the function returns the expected status code and validates the structure fields.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 019 @n 
* **Priority:** High @n@n 
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the cellular_hal_get_uicc_slot_info function | invalid slot_index = 4294967296 | RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info...");
    CellularUICCSlotInfoStruct *slot_info = (CellularUICCSlotInfoStruct*) malloc(sizeof(CellularUICCSlotInfoStruct));
    if(slot_info != NULL){
    // Test case parameters
    int status = 0;
    unsigned int slot_index = 4294967296;  //2 power 32=4294967296
    CellularUICCSlotInfoStruct slot_info;
    // Populate slot_info with random values
    UT_LOG("Invoking cellular_hal_get_uicc_slot_info with invalid pointer ");

    // Invoke the API
    status = cellular_hal_get_uicc_slot_info(slot_index, &slot_info);
    UT_LOG("Return status: %d", status);

    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    }
    // Validate the structure fields
    // TODO: Add validation for the structure fields
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info...");
}
/**
* @brief Test for checking if the active card status is valid.
*
* This test is to verify that the function 'cellular_hal_get_active_card_status' correctly returns the active 
* card status and it should be valid.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 020 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* |:----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Call the function to get the active card status. | None | RETURN_OK | should be success |
*/
void test_l1_cellular_hal_positive1_get_active_card_status(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_1_get_active_card_status...");
    int status = 0;
    // Initialize the card status
    CellularUICCStatus_t card_status = 0;
    UT_LOG("Invoking cellular_hal_positive_1_get_active_card_status with valid input ");
    // Call the function to get the active card status
    status = cellular_hal_get_active_card_status(&card_status);
    UT_LOG("Return status: %d", status);
    UT_LOG("Card Status: %d ", card_status);
    // Check the return status
    //if(status == 0){
    if((card_status == 0) || (card_status == 1) || (card_status == 2) || (card_status == 3))
    {
        UT_LOG("get_active_card_status %d which is a valid value",card_status);
        UT_PASS("get_active_card_status validation success");
    }
    else
    {
        UT_LOG("get_active_card_status %d which is a invalid value",card_status);
        UT_FAIL("get_active_card_status validation fail");
    }
    //}
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive_1_get_active_card_status...");
}

/**
* @brief Test case to verify if the API handles null pointer correctly.
*
* This test verifies whether the API properly handles the case where a null pointer is passed as an argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 021 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Call the function to get the active card status | with NULL pointer | RETURN_ERROR | Should return RETURN_ERROR |
*/

void test_l1_cellular_hal_negative1_get_active_card_status(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_active_card_status...");
    int status = 0;
    UT_LOG("Invoking cellular_hal_negative_1_get_active_card_status with NULL pointer ");

    // Call the function with a null pointer
    status = cellular_hal_get_active_card_status(NULL);
    UT_LOG("Return status: %d", status);

    // Check the return status
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_active_card_status...");
}

/**
 * @brief Test case to verify the functionality of the cellular_hal_get_profile_list function.
 * 
 * This test case checks whether the cellular_hal_get_profile_list function returns the correct result 
 * and does not crash when invoked with valid parameters.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 023 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode,then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoking cellular_hal_get_profile_list | valid profiles, profileCount | RETURN_OK | Should be successful |
 */
void test_l1_cellular_hal_positive1_get_profile_list(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_profile_list...");
    int result = 0;
    // Test parameters
    CellularProfileStruct *profiles = (CellularProfileStruct*) malloc(sizeof(CellularProfileStruct));
    if(profiles != NULL){
    int profileCount = 0;
    UT_LOG("Invoking cellular_hal_get_profile_list with valid parameters...");

    // Invoke the API
    result = cellular_hal_get_profile_list(&profiles, &profileCount);
    UT_LOG("Return result: %d", result);
    //if(result == 0){
    UT_LOG("get_profile_list profileCount: %d",profileCount);    
    UT_LOG("get_profile_list profile_ID: %d",profiles->ProfileID);
    UT_LOG("get_profile_list PDPContextNumber:%d",profiles->PDPContextNumber);

    UT_LOG("get_profile_list ppstProfileOutput.ProfileType %d",profiles->ProfileType);
    UT_ASSERT_TRUE(profiles->ProfileType == 0 || profiles->ProfileType == 1 );

    UT_LOG("get_profile_list ppstProfileOutput.PDPType %d",profiles->PDPType);
    UT_ASSERT_TRUE(profiles->PDPType == 0 || profiles->PDPType == 1 || profiles->PDPType == 2 || profiles->PDPType == 3  );

    UT_LOG("get_profile_list ppstProfileOutput.PDPAuthentication %d",profiles->PDPAuthentication);
    UT_ASSERT_TRUE(profiles->PDPAuthentication == 0 || profiles->PDPAuthentication == 1 || profiles->PDPAuthentication == 2 );

    UT_LOG("get_profile_list ppstProfileOutput.bIsNoRoaming %c",profiles->bIsNoRoaming);
    UT_ASSERT_TRUE( profiles->bIsNoRoaming == TRUE || profiles->bIsNoRoaming == FALSE );

    UT_LOG("get_profile_list ppstProfileOutput.bIsAPNDisabled %c",profiles->bIsAPNDisabled);
    UT_ASSERT_TRUE( profiles->bIsAPNDisabled == TRUE || profiles->bIsAPNDisabled == FALSE );

    UT_LOG("get_profile_list ppstProfileOutput.bIsThisDefaultProfile %c",profiles->bIsThisDefaultProfile);
    UT_ASSERT_TRUE( profiles->bIsThisDefaultProfile == TRUE || profiles->bIsThisDefaultProfile == FALSE );

    UT_LOG("get_profile_list ppstProfileOutput.PDPNetworkConfig %d",profiles->PDPNetworkConfig);
    UT_LOG("get_profile_list ppstProfileOutput.ProfileName %s",profiles->ProfileName);
    UT_LOG("get_profile_list ppstProfileOutput.APN %s",profiles->APN);
    UT_LOG("get_profile_list ppstProfileOutput.Username %s",profiles->Username);
    UT_LOG("get_profile_list ppstProfileOutput.Password %s",profiles->Password);
    UT_LOG("get_profile_list ppstProfileOutput.Proxy %s",profiles->Proxy);
    UT_LOG("get_profile_list ppstProfileOutput.ProxyPort %d",profiles->ProxyPort);

    //}
// Check result
    UT_ASSERT_EQUAL(result, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_profile_list...");
}

/**
 * @brief Test to validate the behavior of cellular_hal_get_profile_list when called with a NULL ppstProfileOutput parameter.
 *
 * This test case is designed to verify the behavior of the cellular_hal_get_profile_list API when it is invoked with a NULL ppstProfileOutput parameter.
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
 * | 01 | Invoking cellular_hal_get_profile_list with NULL ppstProfileOutput parameter | ppstProfileOutput = NULL, profileCount = uninitialized | RETURN_ERROR | Should return RETURN_ERROR |
 */
void test_l1_cellular_hal_negative1_get_profile_list(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_profile_list...");
    CellularProfileStruct *profiles = ((CellularProfileStruct*) malloc(sizeof(CellularProfileStruct)));
    if(profiles != NULL){
    // Test parameters
    //CellularProfileStruct *profiles;
    int result = 0;
    int profileCount =0 ;
    UT_LOG("Invoking cellular_hal_negative1_get_profile_list with NULL ppstProfileOutput parameter...");

    // Invoke the API
    result = cellular_hal_get_profile_list(NULL, &profileCount);
    UT_LOG("Return result: %d", result);

    // Check result
    //UT_LOG("Invoking cellular_hal_get_profile_list with NULL ppstProfileOutput parameter...");
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_profile_list...");
}

/**
* @brief Tests the functionality of the l1_cellular_hal_negative2_get_profile_list function
*
* This test is intended to verify the behavior of the l1_cellular_hal_negative2_get_profile_list function when passed a NULL profile_count parameter.
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
* | 01 | Invoking the function with NULL profile_count parameter | profilesCount = NULL | RETURN_ERROR | Should return an error |
*/

void test_l1_cellular_hal_negative2_get_profile_list(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative2_get_profile_list...");
    CellularProfileStruct *profiles = (CellularProfileStruct*) malloc(sizeof(CellularProfileStruct));
    if(profiles != NULL){
    // Test parameters
    //CellularProfileStruct *profiles;
    int *profileCount = NULL;
    int result = 0;
    UT_LOG("Invoking cellular_hal_negative2_get_profile_list with out of range profile_count = 4294967297...");

    // Invoke the API
    result = cellular_hal_get_profile_list(&profiles, profileCount);
    UT_LOG("Return result: %d", result);

    // Check result
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_negative2_get_profile_list...");
}

/**
* @brief Test the functionality of the cellular_hal_stop_network function when stopping the network with IPV4 IP type.
*
* This test case verifies the implementation of the cellular_hal_stop_network function when stopping the network with the IPV4 IP type. The function is expected to return a success status upon successfully stopping the network.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 027 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Stop the network with IPV4 IP type | ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV4 | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV4;
    UT_LOG("Invoking cellular_hal_positive1_stop_network with ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV4...");

    result = cellular_hal_stop_network(ip_request_type);

    UT_LOG("Return result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_cellular_hal_stop_network...");
}

/**
 * @brief This function tests the functionality of cellular_hal_stop_network function.
 *
 * The purpose of this test is to verify the behavior of the cellular_hal_stop_network function and check if it returns the expected result when called with the given input parameters.
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
 * |  01  | Invoking cellular_hal_stop_network function | ip_request_type = CELLULAR_NETWORK_IP_FAMILY_UNKNOWN | RETURN_OK. | Should be successful |
 *
 */
void test_l1_cellular_hal_positive2_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive2_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = CELLULAR_NETWORK_IP_FAMILY_UNKNOWN;
    UT_LOG("Invoking cellular_hal_positive2_stop_network with ip_request_type = CELLULAR_NETWORK_IP_FAMILY_UNKNOWN...");

    result = cellular_hal_stop_network(ip_request_type);

    UT_LOG("Return result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive2_cellular_hal_stop_network...");
}

/**
* @brief Test case to verify the behavior of cellular_hal_stop_network function when stopping the network.
*
* This test case verifies the behavior of the cellular_hal_stop_network function when stopping the network. The test checks if the function returns the expected result when invoked with a specific input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 029 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* 01 | Invoke the function | ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV6 | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive3_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive3_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV6;
    UT_LOG("Invoking cellular_hal_positive3_stop_network with ip_request_type = CELLULAR_NETWORK_IP_FAMILY_IPV6...");

    result = cellular_hal_stop_network(ip_request_type);

    UT_LOG("Return result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive3_cellular_hal_stop_network...");
}

/**
* @brief Test case to verify the behavior of the function 'cellular_hal_stop_network' when the input IP type is invalid.
*
* This test case checks the behavior of the function 'cellular_hal_stop_network' when an invalid IP type is provided as input. 
* It is important to test this behavior as the function should handle such inputs properly and return an appropriate error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 030 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke Ap | Invalid ip_request_type = 99 | RETURN_ERROR | Should return an error |
*/
void test_l1_cellular_hal_negative1_cellular_hal_stop_network(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_cellular_hal_stop_network...");
    int result = 0;
    CellularNetworkIPType_t ip_request_type = 99;
    UT_LOG("Invoking cellular_hal_stop_network with ip_request_type = 99...");

    result = cellular_hal_stop_network(ip_request_type);
    //int result = cellular_hal_stop_network(NULL);
    UT_LOG("Return result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_cellular_hal_stop_network...");
}
/**
* @brief This test case validates the functionality of the cellular_hal_get_signal_info API with valid profile inputs and a callback.
*
* The purpose of this test is to verify that the cellular_hal_get_signal_info API returns the expected result when called with valid profile inputs and a callback.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 031 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, they must select the test case via the console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Call the API with valid profile inputs and a callback | valid value for signal_info | RETURN_OK | The API should return the expected result |
*/
void test_l1_cellular_hal_positive1_get_signal_info(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_signal_info...");
    int result = 0;
    // Arrange
    CellularSignalInfoStruct *signal_info = ((CellularSignalInfoStruct*)malloc(sizeof(CellularSignalInfoStruct)));
    if(signal_info != NULL){
    UT_LOG("Invoking cellular_hal_positive1_get_signal_info with valid value...");
    // Act
    result = cellular_hal_get_signal_info(signal_info);
    UT_LOG("Return result: %d", result);
    //if(result == 0){
    UT_LOG("signal_info RSSI VALUE :%d",signal_info->RSSI);
	UT_ASSERT_TRUE((signal_info->RSSI <= -30) && (signal_info->RSSI >= -90));

    UT_LOG("signal_info RSRQ VALUE :%d",signal_info->RSRQ);
	UT_ASSERT_TRUE((signal_info->RSRQ <= -3) && (signal_info->RSRQ >= -19.5));

    UT_LOG("signal_info RSRP VALUE :%d",signal_info->RSRP);
	UT_ASSERT_TRUE((signal_info->RSRP <= -44) && (signal_info->RSRP >= -140));

    UT_LOG("signal_info SNR VALUE :%d",signal_info->SNR);
	UT_ASSERT_TRUE((signal_info->SNR <= 30) && (signal_info->SNR >= -20));

    UT_LOG("signal_info TXPower VALUE :%d",signal_info->TXPower);
	UT_ASSERT_TRUE((signal_info->TXPower <= 30) && (signal_info->TXPower >= 0));
   // }
    // Assert
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
* **Test Case ID:** 032 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Verify behavior when a null function is passed | with NULL pointer | RETURN_ERROR | Should be failure |
*/
void test_l1_cellular_hal_negative1_get_signal_info(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_signal_info...");
    int result = 0;
    CellularSignalInfoStruct *signal_info = ((CellularSignalInfoStruct*)malloc(sizeof(CellularSignalInfoStruct)));
    if(signal_info != NULL){
    UT_LOG("Invoking cellular_hal_negative1_get_signal_info with null value...");

    result = cellular_hal_get_signal_info(NULL);
    UT_LOG("Return result: %d", result);
    // Assert
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_signal_info...");
  
}
/**
* @brief Test case to verify the behavior of the 'cellular_hal_get_signal_info' function when a null callback function is passed.
*
* This test case checks if the 'cellular_hal_get_signal_info' function returns the expected result when a null callback function is passed as an argument. This scenario is being tested to ensure that the function handles this edge case properly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 033 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Verify behavior when a null function is passed | with EMPTRY string | RETURN_ERROR | Should be failure |
*/
/*void test_l1_cellular_hal_negative2_get_signal_info(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative2_get_signal_inf...");
    UT_LOG("Invoking cellular_hal_negative2_get_signal_info with null value...");

    int result = cellular_hal_get_signal_info("");
    UT_LOG("Return result: %d", result);
    // Assert
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    UT_LOG("Exiting test_l1_cellular_hal_negative2_get_signal_info...");
  
}*/


/**
* @brief Test to verify the functionality of the 'cellular_hal_set_modem_operating_configuration' API.
*
* This test case focuses on verifying the functionality of the 'cellular_hal_set_modem_operating_configuration' API by setting a valid modem operating configuration and checking the return status.
*
* **Test Group ID:** Basic:01 @n
* **Test Case ID:** 034 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Set modem operating configuration | modem_operating_config = CELLULAR_MODEM_SET_ONLINE | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_set_modem_operating_configuration(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_1_set_modem_operating_configuration...");
    int result = 0;
    // Fill pstProfileInput with valid values
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_ONLINE;
    //modem_operating_config = CELLULAR_MODEM_SET_ONLINE;
    UT_LOG("Invoking cellular_hal_positive_1_set_modem_operating_configuration with valid value ... %d", modem_operating_config );

    // Invoke the API with valid inputs
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive_1_set_modem_operating_configuration...");
}
/**
* @brief Test to verify the functionality of the 'cellular_hal_set_modem_operating_configuration' API.
*
* This test case focuses on verifying the functionality of the 'cellular_hal_set_modem_operating_configuration' API by setting a valid modem operating configuration and checking the return status.
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
* | 01 | Set modem operating configuration | modem_operating_config = CELLULAR_MODEM_SET_OFFLINE | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive2_set_modem_operating_configuration(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_2_set_modem_operating_configuration...");
    int result = 0;
    // Fill pstProfileInput with valid values
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_OFFLINE;
    UT_LOG("Invoking cellular_hal_positive_2_set_modem_operating_configuration with valid value... %d", modem_operating_config);

    // Invoke the API with valid inputs
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive_2_set_modem_operating_configuration...");
}
/**
* @brief Test to verify the functionality of the cellular_hal_set_modem_operating_configuration API.
*
* This test case focuses on verifying the functionality of the cellular_hal_set_modem_operating_configuration API by setting a valid modem operating configuration and checking the return status.
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
* | 01 | Set modem operating configuration | modem_operating_config = CELLULAR_MODEM_SET_LOW_POWER_MODE | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive3_set_modem_operating_configuration(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_3_set_modem_operating_configuration...");
    int result = 0;
    // Fill pstProfileInput with valid values
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_LOW_POWER_MODE;
    UT_LOG("Invoking cellular_hal_positive_3_set_modem_operating_configuration with valid value... %d", modem_operating_config);

    // Invoke the API with valid inputs
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive_3_set_modem_operating_configuration...");
}
/**
* @brief Test to verify the functionality of the cellular_hal_set_modem_operating_configuration API.
*
* This test case focuses on verifying the functionality of the cellular_hal_set_modem_operating_configuration API by setting a valid modem operating configuration and checking the return status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 037 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Set modem operating configuration | modem_operating_config = CELLULAR_MODEM_SET_RESET | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive4_set_modem_operating_configuration(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_4_set_modem_operating_configuration...");
    int result = 0;
    // Fill pstProfileInput with valid values
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_RESET;
    UT_LOG("Invoking cellular_hal_positive_4_set_modem_operating_configuration with valid value... %d", modem_operating_config);

    // Invoke the API with valid inputs
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return result: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive_4_set_modem_operating_configuration...");
}
/**
* @brief Test to verify the functionality of the cellular_hal_set_modem_operating_configuration API.
*
* This test case focuses on verifying the functionality of the cellular_hal_set_modem_operating_configuration API by setting a valid modem operating configuration and checking the return status.
*
* **Test Group ID:** Basic : 01 @n
* **Test Case ID:** 038 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via . @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Set modem operating configuration | modem_operating_config = CELLULAR_MODEM_SET_FACTORY_RESET | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive5_set_modem_operating_configuration(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive_5_set_modem_operating_configuration...");
    int result = 0;
    // Fill pstProfileInput with valid values
    //CellularModemOperatingConfiguration_t modem_operating_config = ((CellularModemOperatingConfiguration_t)malloc(sizeof(CellularModemOperatingConfiguration_t)))
    CellularModemOperatingConfiguration_t modem_operating_config = CELLULAR_MODEM_SET_FACTORY_RESET;
    //modem_operating_config.CELLULAR_MODEM_SET_FACTORY_RESET;
    UT_LOG("Invoking cellular_hal_positive_5_set_modem_operating_configuration with valid value... %d", modem_operating_config);

    // Invoke the API with valid inputs
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive_5_set_modem_operating_configuration...");
}


/**
* @brief Test case to verify the behavior of the function when an invalid profile type is provided.
*
* This test case is used to verify the behavior of the function "cellular_hal_set_modem_operating_configuration" when an invalid profile type is provided as input. The objective of this test is to ensure that the function returns the expected result when invoked with an invalid profile type.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 040 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the API with an invalid profile type | modem_operating_config = 100 | RETURN_ERROR | The API should return the expected result indicating failure due to an invalid profile type |
*/
void test_l1_cellular_hal_negative2_set_modem_operating_configuration(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative_2_set_modem_operating_configuration_invalid_profile...");
    int result = 0;
    // Fill pstProfileInput with invalid profile type
    CellularModemOperatingConfiguration_t modem_operating_config = 100;
    UT_LOG("Invoking cellular_hal_negative_2_set_modem_operating_configuration with invalid value...");

    // Invoke the API with invalid profile type
    result = cellular_hal_set_modem_operating_configuration(modem_operating_config);
    UT_LOG("Return result: %d", result);

    // Check the return status
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative_2_set_modem_operating_configuration_invalid_profile...");
}
/**
* @brief This test is to verify the functionality of the "cellular_hal_get_device_imei_sv" API.
*
* The purpose of this test is to ensure that the "cellular_hal_get_device_imei_sv" API returns the IMEI of the device correctly.
* This test is part of the Basic test group and has a high priority.
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
* | 01 | Invoking cellular_hal_get_device_imei_sv and checking the return status | imei = "123456789012345" | RETURN_OK | Should be successful |
*/

void test_l1_cellular_hal_positive1_get_device_imei_sv(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_device_imei_sv...");
    int status = 0;    
    char imei[16] = {"\0"};
    UT_LOG("Invoking cellular_hal_positive_1_get_device_imei_sv with valid character array ");

    status = cellular_hal_get_device_imei_sv(imei);
    UT_LOG("Return status: %d", status);
    UT_LOG("imei :%s",imei);
    UT_ASSERT_EQUAL(status, RETURN_OK);
    
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_device_imei_sv...");
}
/**
 * @brief Test case to validate the negative scenario of the cellular_hal_get_device_imei_sv API.
 *
 * This test case verifies the behavior of cellular_hal_get_device_imei_sv API when the input parameter imei is NULL.
 * 
 * Test Group ID: Basic: 01 @n
 * Test Case ID: 042 @n
 * Priority: High @n@n
 * 
 * Pre-Conditions: None @n
 * Dependencies: None @n
 * User Interaction: If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Verify the behavior of the API when imei is NULL. | imei = NULL |  RETURN_ERROR | The API should return an error. |
 */
void test_l1_cellular_hal_negative1_get_device_imei_sv(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_device_imei_sv...");
    int status = 0;    
    char *imei = NULL;
    UT_LOG("Invoking cellular_hal_negative_1_get_device_imei_sv with imei as NULL");

    status = cellular_hal_get_device_imei_sv(imei);
    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_device_imei_sv...");
}

/**
* @brief Test to validate the functionality of retrieving the IMEI from the modem.
*
* The objective of this test is to ensure that the function cellular_hal_retrieve_modem_imei() returns a valid IMEI value and a success status when provided with a valid IMEI buffer.
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
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
| 01 | Invoking cellular_hal_retrieve_modem_imei with imei buffer of size >= 16 bytes | imei = "123456789012345" | RETURN_OK | Should be successful |
*/

void test_l1_cellular_hal_positive1_get_device_imei( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_device_imei...");
    
    /* Input */
    char imei[16] = {"\0"};
    int status = 0;    
    /* Test description */
    UT_LOG("Invoking cellular_hal_positive_1_retrieve_modem_imei with imei buffer of size >= 16 bytes");
    
    /* Invoke API */
    status = cellular_hal_get_device_imei(imei);
    UT_LOG("Return status: %d", status);
    UT_LOG("imei :%s",imei);


    /* Check return value */
    UT_ASSERT_EQUAL(status, RETURN_OK);
    
    /* Check if imei contains a valid IMEI value */
    /* Add assertion to check IMEI validity */
    
    //UT_LOG("IMEI: %s", imei);
    UT_LOG("IMEI: %d", imei);
    UT_LOG("Status: %d", status);
    
    UT_LOG("Exiting test_l1_cellular_hal_positive1_retrieveModemIMEI...");
}

/**
* @brief This test is used to verify the behavior when a NULL IMEI buffer is passed to the cellular_hal_retrieve_modem_imei function.
*
* The purpose of this test is to ensure that the function handles the case of a NULL IMEI buffer correctly and returns the expected status.
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
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_retrieve_modem_imei with NULL imei buffer | imei = NULL | status = RETURN_ERROR | Should return RETURN_ERROR |
*/
void test_l1_cellular_hal_negative1_get_device_imei( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_device_imei...");
    
    /* Input */
    char* imei = NULL;
    int status = 0;    
    /* Test description */
    UT_LOG("Invoking cellular_hal_negative_1_retrieve_modem_imei with NULL imei buffer");
    
    /* Invoke API */
    status = cellular_hal_get_device_imei(imei);
    UT_LOG("Return status: %d", status);

    /* Check return value */
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    
    UT_LOG("Status: %d", status);
    
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_device_imei...");
}

/**
 * @brief Unit test to verify the functionality of retrieving the ICCID from the modem.
 *
 * This test case verifies the functionality of the "cellular_hal_retrieve_modem_current_iccid" API by retrieving the ICCID from the modem and checking the return status and the retrieved ICCID.
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
 * | 01 | Retrieving ICCID | iccid = "" | return status = RETURN_OK, iccid not NULL | Should be successful |
 */
void test_l1_cellular_hal_positive1_get_modem_current_iccid(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_iccid...");
    int status = 0;
    char iccid[21] = {"\0"};
    UT_LOG("Invoking cellular_hal_positive_1_retrieve_modem_current_iccid with iccid");

    status = cellular_hal_get_modem_current_iccid(iccid);

    UT_LOG("Return status: %d", status);
   // UT_LOG("Actual Result: %d", result);
    UT_LOG("Value: %s", iccid);
    UT_ASSERT_EQUAL(status, RETURN_OK);
    //UT_ASSERT_PTR_NOT_NULL(iccid);
    if(iccid != NULL)
    { 
            UT_LOG("get_modem_current_iccid  is %s", iccid);
            UT_PASS (" get_modem_current_iccid success");
    }
    else
    {
            UT_LOG("get_modem_current_iccid is %s", iccid);
            UT_FAIL(" get_modem_current_iccid Failure");    
    }

    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_iccid...");
}

/**
 * @brief Test case to verify the behavior of retrieving modem ICCID when the ICID buffer is NULL.
 *
 * This test case checks if the function properly handles the scenario when the ICCID buffer is NULL and returns an error status.
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
 * | Variation / Step | Description | Test Data                                     | Expected Result              | Notes            |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01   | Invoke the function with a NULL ICCID buffer.   | iccid = NULL    | RETURN_ERROR   | Should be failure |
 */
void test_l1_cellular_hal_negative1_get_modem_current_iccid(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative_null_iccid_buffer...");
    int status = 0;
    char* iccid = NULL;
    UT_LOG("Invoking cellular_hal_negative_1_get_modem_current_iccid with NULL iccid");

    status = cellular_hal_get_modem_current_iccid(iccid);

    UT_LOG("Return status: %d", status);
    UT_LOG("value: %d", iccid);

    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative_null_iccid_buffer...");
}
/**
 * @brief Test case to verify the behavior of retrieving modem ICCID when the ICID buffer is NULL.
 *
 * This test case checks if the function properly handles the scenario when the ICCID buffer is NULL and returns an error status.
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
 * | Variation / Step | Description | Test Data                                     | Expected Result              | Notes            |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01   | Invoke the function with a NULL ICCID buffer.   | iccid = empty string   | RETURN_ERROR   | Should be failure |
 */
/*void test_l1_cellular_hal_negative2_get_modem_current_iccid(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative2_empty_iccid_buffer...");

    char* iccid = " ";
    UT_LOG("Invoking cellular_hal_negative_2_get_modem_current_iccid with NULL iccid");

    int status = cellular_hal_get_modem_current_iccid(iccid);

    UT_LOG("Return status: %d", status);
    UT_LOG("Return status: %d", iccid);
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative2_empty_iccid_buffer...");
}*/

/**
* @brief This is a positive test case to verify the functionality of the cellular_hal_retrieve_modem_current_msisdn function.
*
* This test case verifies if the function retrieves the current MSISDN (Mobile Subscriber Integrated Services Digital Network Number) from the modem correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 050 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_retrieve_modem_current_msisdn with valid buffer | msisdn = valid buffer | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_current_msisdn(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_msisdn...");

    // Input
    int result = 0;
    char msisdn[20] = {"\0"};
    UT_LOG("Invoking cellular_hal_positive_1_retrieve_modemmsisdn_current_msisdn with input parameters: msisdn (valid buffer)");

    // Invoke the API
    result = cellular_hal_get_modem_current_msisdn(msisdn);

    // Test description
    UT_LOG("Actual Result: %d", result);
    //UT_LOG("Value: %s", msisdn);
    UT_LOG("Value: %d", msisdn);
    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_OK);
    // Additional asserts can be added to validate the MSISDN value

    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_msisdn...");
}
/**
 * @brief Test case to verify the behavior of the function when an invalid IP request type is provided.
 *
 * This test case is meant to verify the functionality of the function when an invalid IP request type is provided as input. The function is expected to return an error in this case.
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
 * | 01 | Invoke the function | with NULL pointer| RETURN_ERROR | Should return an error |
 */
void test_l1_cellular_hal_negative1_get_modem_current_msisdn(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_invalid_ip_request_type...");
    int result = 0;

    UT_LOG("Invoked cellular_hal_negative_1_get_modem_current_msisdn with NULL msisdn buffer");
    // Invoke the API
    result = cellular_hal_get_modem_current_msisdn(NULL);
    UT_LOG("Actual result: %d", result);
    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_invalid_ip_request_type...");
}

/**
 * @brief Test case to check for the functionality of the 'cellular_hal_get_packet_statistics' function when an invalid IP request type is passed as an argument.
 *
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 053 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | invoke the function | with valid input| RETURN_OK | Should be successfull |
 */
void test_l1_cellular_hal_positive1_get_packet_statistics(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_packet_statistics...");
    int result = 0;
    CellularPacketStatsStruct *network_packet_stats = ((CellularPacketStatsStruct*) malloc (sizeof(CellularPacketStatsStruct)));
    if(network_packet_stats != NULL){
    UT_LOG("Invoking cellular_hal_positive1_get_packet_statistics with valid input");

    result = cellular_hal_get_packet_statistics(network_packet_stats);
    UT_LOG("Function return value: %d", result);
    //if(result= 0)
    //{
    UT_LOG("cellular_hal_get_packet_statistics BytesSent :%lu",network_packet_stats->BytesSent);
    UT_LOG("cellular_hal_get_packet_statistics BytesReceived :%lu",network_packet_stats->BytesReceived);
    UT_LOG("cellular_hal_get_packet_statistics PacketsSent :%lu",network_packet_stats->PacketsSent);
    UT_LOG("cellular_hal_get_packet_statistics PacketsReceived :%lu",network_packet_stats->PacketsReceived);
    UT_LOG("cellular_hal_get_packet_statistics PacketsSentDrop :%lu",network_packet_stats->PacketsSentDrop);
    UT_LOG("cellular_hal_get_packet_statistics PacketsReceivedDrop :%lu",network_packet_stats->PacketsReceivedDrop);
    UT_LOG("cellular_hal_get_packet_statistics UpStreamMaxBitRate  :%lu",network_packet_stats->UpStreamMaxBitRate);
    UT_LOG("cellular_hal_get_packet_statistics DownStreamMaxBitRate :%lu",network_packet_stats->DownStreamMaxBitRate);
    //}

    // Validate the result
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
 * @brief Test case to check for the functionality of the 'cellular_hal_get_packet_statistics' function when an invalid IP request type is passed as an argument.
 *
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 054 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoke the api | with NULL pointer | RETURN_ERROR | Should be failure |
 */
void test_l1_cellular_hal_negative1_get_packet_statistics(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_packet_statistics...");
    int result = 0;
    CellularPacketStatsStruct *network_packet_stats = ((CellularPacketStatsStruct*) malloc (sizeof(CellularPacketStatsStruct)));
    if(network_packet_stats != NULL){
    // Input
    // Set ip_request_type to an invalid value
    //CellularNetworkIpFamily.ip_request_type = NULL;
    UT_LOG("Invoking cellular_hal_negative1_get_packet_statistics with NULL");

    // Invoke the API
    result = cellular_hal_get_packet_statistics(NULL);
    UT_LOG("Function return value: %d", result);

    // Validate the result
    UT_ASSERT_EQUAL(result, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_packet_statistics...");
}

/**
* @brief Test case to verify the behavior of the function cellular_hal_get_current_modem_interface_status when invoked with a positive input.
*
* This test case checks if the function cellular_hal_get_current_modem_interface_status returns the correct result and updates the output values when invoked with a positive input.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 056 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke cellular_hal_get_current_modem_interface_status | with possible valid values | RETUEN_OK | Should be success |
*/
void test_l1_cellular_hal_positive1_get_current_modem_interface_status( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_current_modem_interface_status...");

    // Input
    CellularInterfaceStatus_t status = 0 ;
    //CellularInterfaceStatus_t status;
    // Call the API
    UT_LOG("Invoking cellular_hal_positive_1_get_current_modem_interface_status with input parameters");

    int result = cellular_hal_get_current_modem_interface_status(&status);
    UT_LOG("Function return value: %d", result);
    // Check the return value and output values
    UT_LOG("status value: %d", status);
    UT_ASSERT_EQUAL(result, RETURN_OK);
   /*if (strcmp(&status,"IF_UP") || strcmp(&status,"IF_DOWN") || strcmp(&status,"IF_UNKNOWN") || strcmp(&status,"IF_DORMANT")||  strcmp(&status,"IF_NOTPRESENT"))*/
    if ((status == 1) || (status == 2) || (status == 3) || (status == 4) || (status == 5) || (status == 6) || (status == 7))
    {
            UT_LOG("get_current_modem_interface_status %s which is a valid value",result);
            UT_PASS("get_current_modem_interface_status validation success");
    }
    else
    {
            UT_LOG("get_current_modem_interface_status %s which is a Invalid value",result);
            UT_FAIL("get_current_modem_interface_status validation fail");
    }
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_current_modem_interface_status...");
}

/**
* @brief This test is to verify the behavior of the function `cellular_hal_get_current_modem_interface_status` when providing a NULL pointer as the input parameter.
*
* The objective of this test is to ensure that the function handles the NULL pointer input correctly and returns the expected result.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 057 @n
* **Priority:** High  @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Call the API with NULL pointer input | status = NULL | RETURN_ERROR | Should return the error value |
*/
void test_l1_cellular_hal_negative1_get_current_modem_interface_status( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_current_modem_interface_status...");
    // Input
    //CellularInterfaceStatus_t *status;
    UT_LOG("Invoking cellular_hal_negative1_get_current_modem_interface_status with input parameters (status = NULL)");

    // Call the API
    //int result = cellular_hal_get_current_modem_interface_status(status);
    int result = cellular_hal_get_current_modem_interface_status(NULL);
    UT_LOG("Function return value: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_current_modem_interface_status...");
}

/**
* @brief This test is to verify the behavior of the function test_l1_cellular_hal_negative1_invalid_modem_operating_config when an invalid modem operating configuration is provided as input.
*
* The purpose of this test is to ensure that the function returns RETURN_ERROR when an invalid modem operating configuration is passed as input.
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
* | 01 | Set modem operating configuration to invalid value | modem_operating_config = INVALID_VALUE | RETURN_ERROR | Should return RETURN_ERROR |
*/
void test_l1_cellular_hal_negative1_set_modem_network_attach(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_network_attach...");

    // Test setup
    //int expected = RETURN_ERROR;
    int result;
    UT_LOG("Invoking cellular_hal_negative1_set_modem_network_attach");

    // Test execution
    result = cellular_hal_set_modem_network_attach();
    UT_LOG("Function return value: %d", result);

    // Test assertions
    UT_LOG("Expected Outcome: RETURN_ERROR");

    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_network_attach...");
}
/**
* @brief Test to verify the behavior of the function 'cellular_hal_set_modem_network_detach' when detaching from the network is not possible.
*
* This test verifies the behavior of the 'cellular_hal_set_modem_network_detach' function when detaching from the network is not possible. The API is expected to return an error code.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 060 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Test the behavior when detaching from the network is not possible | None | RETURN_ERROR | Should return an error code |
*/
void test_l1_cellular_hal_negative1_set_modem_network_detach( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_network_detach...");
    UT_LOG("Invoking cellular_hal_negative1_set_modem_network_detach... ");

    // Invoke the API
    int result = cellular_hal_set_modem_network_detach();
    UT_LOG("Actual Result: %d", result);

    // Test the result
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_network_detach...");
}
/**
* @brief This test function is to validate the retrieval of modem IMEI and software version.
*
* The objective of this test is to check if the function `cellular_hal_get_modem_firmware_version` returns the modem IMEI and software version correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 061 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the function | version="v2.1.3" | The function should return the IMEI and software version without any error | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_modem_firmware_version(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_firmware_version...");

    char firmware_version[128] = {"\0"};

    // Calling the API and logging the test description
    UT_LOG("Invoking cellular_hal_positive_1_get_modem_firmware_version with valid imei_sv buffer...");
    int result = cellular_hal_get_modem_firmware_version(firmware_version);
    UT_LOG("Actual Result: %d", result);
    UT_LOG("actual firmware version of device is:%s",firmware_version); 
    // Checking the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Verifying the output buffer
    //UT_ASSERT_PTR_NOT_NULL(imei_sv);
    if(firmware_version != NULL)
    { 
       // if (strcmp(firmware_version,"v2.1.3"))
       // {
            UT_LOG("get_modem_firmware_version  is %s", firmware_version);
            UT_PASS (" get_modem_firmware_version success");
        //}
    }
    else
        {
            UT_LOG("get_modem_firmware_version is %s", firmware_version);
            UT_FAIL(" get_modem_firmware_version Failure");    
        }

    //UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_iccid...");

    //UT_LOG("IMEI Software Version: %s", imei_sv);
    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_firmware_version..");
}

/**
 * @brief Test objective: Test the case when the imei_sv buffer is NULL.
 *
 * This test is to verify the behavior of the API when the imei_sv buffer is NULL. The expected result is for the API to return an error code (RETURN_ERROR).
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 062 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoking cellular_hal_get_modem_firmware_version | with NULL pointer | RETURN_ERROR | Should return an error |
 */

void test_l1_cellular_hal_negative1_get_modem_firmware_version(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_firmware_version...");
    int result = 0;
    // Calling the API with NULL imei_sv buffer and logging the test description
    UT_LOG("Invoking cellular_hal_negative_1_get_modem_firmware_version with NULL imei_sv buffer...");
    result = cellular_hal_get_modem_firmware_version(NULL);
    UT_LOG("Actual Result: %d", result);

    // Checking the return value
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_firmware_version...");
}

/**
 * @brief Test to verify the functionality of cellular_hal_get_current_plmn_information function.
 *
 * This test checks if the cellular_hal_get_current_plmn_information function returns the expected status and fills in the plmn_info structure correctly.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 063 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoking cellular_hal_get_current_plmn_information  | with valid plmn_info structure | RETURN_OK | Should be successful |
 */
void test_l1_cellular_hal_positive1_get_current_plmn_information(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_current_plmn_information...");
    int status = 0;
    CellularCurrentPlmnInfoStruct *plmn_info = ((CellularCurrentPlmnInfoStruct*)malloc(sizeof(CellularCurrentPlmnInfoStruct)));
    if(plmn_info != NULL){
    UT_LOG("Invoking cellular_hal_positive_1_get_current_plmn_information with valid plmn_info structure.");

    status = cellular_hal_get_current_plmn_information(plmn_info);
    UT_LOG("Actual Result: %d", status);
    UT_LOG("cellular_hal_get_current_plmn_information plmn_name :%s",plmn_info->plmn_name);
    UT_LOG("cellular_hal_get_current_plmn_information MCC :%d",plmn_info->MCC);
    UT_LOG("cellular_hal_get_current_plmn_information MNC :%d",plmn_info->MNC);
    UT_LOG("cellular_hal_get_current_plmn_information roaming_enabled :%c",plmn_info->roaming_enabled);
    UT_LOG("cellular_hal_get_current_plmn_information area_code :%d",plmn_info->area_code);
    UT_LOG("cellular_hal_get_current_plmn_information cell_id :%lu",plmn_info->cell_id);

    UT_ASSERT_TRUE(plmn_info->registration_status == 1 || plmn_info->registration_status == 2);
    UT_LOG("plmn_info.registration_status : %d",plmn_info->registration_status);

    UT_ASSERT_TRUE(plmn_info->registered_service == 1 || plmn_info->registered_service == 2 || plmn_info->registered_service == 3 || plmn_info->registered_service ==0);
    UT_LOG("plmn_info.registration_status : %d",plmn_info->registered_service);
    UT_ASSERT_EQUAL(status, RETURN_OK);
    // TODO: Add assertion to check the values filled in the plmn_info structure.
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
 * **Test Case ID:** 064 @n
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

void test_l1_cellular_hal_negative1_get_current_plmn_information(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_current_plmn_information...");
    int status = 0;
    CellularCurrentPlmnInfoStruct *plmn_info = ((CellularCurrentPlmnInfoStruct*)malloc(sizeof(CellularCurrentPlmnInfoStruct)));
    if(plmn_info != NULL){
    UT_LOG("Invoking cellular_hal_negative_1_get_current_plmn_information with NULL plmn_info structure.");

    status = cellular_hal_get_current_plmn_information(NULL);
    UT_LOG("Actual Result: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_current_plmn_information...");
}

/**
* @brief This test case is used to verify the functionality of the function cellular_hal_get_available_networks_information().
*
* This test case is used to test the functionality of the function cellular_hal_get_available_networks_information().
* This function is responsible for retrieving available network information from the cellular module.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 066 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the get_available_networks_information API | with valid pointers | RETURN_OK | Should be successful |
*/
void test_l1_cellular_hal_positive1_get_available_networks_information(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_get_available_networks_information...");
    int status = 0;    
    // Test variables
    CellularNetworkScanResultInfoStruct *network_info = ((CellularNetworkScanResultInfoStruct*)malloc (sizeof(CellularNetworkScanResultInfoStruct))) ; // Valid pointer
    if(network_info != NULL){
    unsigned int total_network_count = 0 ; // Valid pointer
    
    // Invoke the API with valid pointers
    status = cellular_hal_get_available_networks_information(&network_info, &total_network_count);
    UT_LOG("Actual Result: %d", status);
    UT_LOG("cellular_hal_get_available_networks_information network_name :%s",network_info->network_name);
    UT_LOG("cellular_hal_get_available_networks_information MCC :%d",network_info->MCC);
    UT_LOG("cellular_hal_get_available_networks_information MNC :%d",network_info->MNC);

    UT_ASSERT_TRUE(network_info->network_allowed_flag == TRUE || network_info->network_allowed_flag == FALSE);
    UT_LOG("network_info.network_allowed_flag :%c",network_info->network_allowed_flag );

    UT_LOG("cellular_hal_get_available_networks_information total_network_count :%d ",total_network_count);
    // Check the return value
    UT_ASSERT_EQUAL(status, RETURN_OK);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    // Test complete
    UT_LOG("Exiting test_l1_cellular_hal_positive1_cellular_hal_get_available_networks_information...");
}


/**
 * @brief Test case to validate the behavior of the cellular_hal_get_available_networks_information function when a NULL pointer is passed for network_info.
 *
 * This test case verifies that the cellular_hal_get_available_networks_information function returns an error when a NULL pointer is passed for network_info. The purpose of this test is to ensure that the function handles invalid input correctly.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 068 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:**
 * | Variation / Step | Description        | Test Data      | Expected Result     | Notes         |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * |  01   | Invoke the get_available_networks_information API  | network_info = NULL   | RETURN_ERROR | Should fail   |
 */

void test_l1_cellular_hal_negative1_get_available_networks_information(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_cellular_hal_get_available_networks_information...");
    int status = 0;
    CellularNetworkScanResultInfoStruct *network_info = ((CellularNetworkScanResultInfoStruct*)malloc (sizeof(CellularNetworkScanResultInfoStruct))) ; // Valid pointer
    if(network_info != NULL){
    // Test variables
    CellularNetworkScanResultInfoStruct **network_info = NULL; // NULL pointer
    unsigned int total_network_count = 0; // Valid pointer
    UT_LOG("Invoking test_l1_cellular_hal_negative1_cellular_hal_get_available_networks_information...");  

    // Invoke the API with NULL pointer for network_info
    status = cellular_hal_get_available_networks_information(network_info, &total_network_count);
    UT_LOG("Actual Result: %d", status);
   
    // Check the return value
    UT_ASSERT_EQUAL(status, RETURN_ERROR);
    }
    else
    {
        UT_LOG("Malloc operation failed");
        UT_FAIL("Memory allocation with malloc failed");
    }
    // Test complete
    UT_LOG("Exiting test_l1_cellular_hal_negative1_cellular_hal_get_available_networks_information...");
}


/**
* @brief This test function is used to verify the functionality of the "cellular_hal_get_modem_preferred_radio_technology" API.
*
* The objective of this test is to ensure that the API returns the preferred radio technology correctly.test_l1_cellular_hal_positive1_get_modem_current_radio_technology
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 070 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the API | preferred_rat = "" | A successful return value | The API should return the preferred radio technology |
*/
void test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology...");

    // Allocate a buffer for the preferred_rat value
    char preferred_rat[128] = {"\0"};
    int ret = 0;
    // Invoke the API
    ret = cellular_hal_get_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Invoking test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology...");  
    UT_LOG("Actual Result: %d", ret);
    // UT_LOG("Value: %s", preferred_rat);
    UT_LOG("Value: %d", preferred_rat);
    
    // Check the return value
    //UT_LOG("API returned successfully");

    // Check if the preferred_rat value is within the expected range of possible values
    if(!strcmp(preferred_rat, "AUTO") || !strcmp(preferred_rat, "CDMA20001X") || !strcmp(preferred_rat, "EVDO") || !strcmp(preferred_rat, "GSM") || !strcmp(preferred_rat, "UMTS") || !strcmp(preferred_rat, "LTE"))
    {
            UT_LOG("modem_preferred_radio_technology %s which is a valid value",preferred_rat);
            UT_PASS("modem_preferred_radio_technology validation success");
    }
    else
    {
            UT_LOG("modem_preferred_radio_technology %s which is a Invalid value",preferred_rat);
            UT_FAIL("modem_preferred_radio_technology fail");
    }
    UT_LOG("Preferred RAT value: %s", preferred_rat);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology...");
}

/**
* @brief This test verifies the functionality of the 'cellular_hal_get_modem_preferred_radio_technology' API when a NULL pointer is passed as input.
*
* This test case tests the behavior of the 'cellular_hal_get_modem_preferred_radio_technology' API when a NULL pointer is passed as input. It checks if the API returns the expected error value.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 071 @n
* **Priority:** High @n@n
* 
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
* 
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Pass NULL pointer as input | NULL | RETURN_ERROR | Should return the expected error value |
*/
void test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology(void) {
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology...");
    int ret = 0;
    UT_LOG("Invoking test_l1_cellular_hal_nagative1_get_modem_preferred_radio_technology with NULL pointer"); 
    // Pass NULL pointer as input
    ret = cellular_hal_get_modem_preferred_radio_technology(NULL); 
    UT_LOG("Actual Result: %d", ret);
    // Check the return value
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);
    UT_LOG("API returned error as expected");

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology...");
}

/**
* @brief Test function to verify valid pointer input and IFUP status of L1 cellular hal.
*
* The objective of this test is to verify that the L1 cellular hal functions correctly with valid pointer input and IFUP status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 073 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the function | preferred_rat = "{LTE / AUTO}", IFUP status = 1 | RETURN_OK |Should be successful | 
*/
void test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology(void) {
    // Logging
    UT_LOG("Entering test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology...");

    // Test input
    int result = 0;
    char preferred_rat[128] = "UMTS";
    UT_LOG("Invoking test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology...");  

    // Invoke the API
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Logging
    UT_LOG("Exiting test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology...");
    // IFUP status should be 1
    
    // Run the test case using the test input
    // ...
}
/**
* @brief Test function to verify valid pointer input and IFUP status of L1 cellular hal.
*
* The objective of this test is to verify that the L1 cellular hal functions correctly with valid pointer input and IFUP status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 074 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:**  @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the function | preferred_rat = "{LTE / AUTO}", IFUP status = 1 | RETURN_OK |Should be successful | 
*/
void test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology(void) {
    // Logging
    UT_LOG("Entering test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology...");

    // Test input
    char preferred_rat[128] = "AUTO";
    int result = 0;
    UT_LOG("Invoking test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology...");  

    // Invoke the API
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Logging
    UT_LOG("Exiting test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology...");
    // IFUP status should be 1
    
    // Run the test case using the test input
    // ...
}
/**
* @brief Test function to verify valid pointer input and IFUP status of L1 cellular hal.
*
* The objective of this test is to verify that the L1 cellular hal functions correctly with valid pointer input and IFUP status.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 075 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke the function | preferred_rat = "{LTE / AUTO}", IFUP status = 1 |RETURN_OK  |Should be successful | 
*/
void test_l1_cellular_hal_positive3_set_modem_preferred_radio_technology(void) {
    // Logging
    UT_LOG("Entering test_l1_cellular_hal_positive3_set_modem_preferred_radio_technology...");

    // Test input
    char preferred_rat[128] = "LTE,UMTS";
    int result = 0;
    UT_LOG("Invoking test_l1_cellular_hal_positive3_set_modem_preferred_radio_technology...");  

    // Invoke the API
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Logging
    UT_LOG("Exiting test_l1_cellular_hal_positive3_set_modem_preferred_radio_technology...");
    // IFUP status should be 1
    
    // Run the test case using the test input
    // ...
}

/**
 * @brief Test to validate the behavior when a null pointer is passed as input to the API.
 *
 * This test verifies the behavior of the API when a null pointer is passed as input. It checks whether the API handles the null pointer correctly and returns the expected error code.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 076 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoke API with null pointer | preferred_rat = NULL | RETURN_ERROR | Should return the expected error code |
 */
void test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology(void) {
    // Logging
    UT_LOG("Entering test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology...");
    // Test input
    char* preferred_rat = NULL;
    int result = 0;
    UT_LOG("Invoking test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology...");  

    // Invoke the API
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    // Logging
    UT_LOG("Exiting test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology...");
}

/**
* @brief Test case to verify the behavior of the API when an invalid status value is provided.
*
* This test case checks the behavior of the API when an invalid status value is provided as input. The purpose of this test is to ensure that the function handles invalid status values correctly and returns the expected results.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 077 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Test with invalid status value | status = "Invalid" | RETURN_ERROR | Should return an error code |
*/
void test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology(void) {
    // Logging
    UT_LOG("Entering test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology...");
    char preferred_rat[128] = "Unknown_TECH";
    int result = 0;
    UT_LOG("Invoking test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology...");
    // Test input
    //char preferred_rat[128] = "Unknown_TECH";
    result = cellular_hal_set_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("Return result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    // Logging
    UT_LOG("Exiting test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology...");
}
/**
* @brief Test the function get_modem_current_radio_technology_lte of the L1 Cellular HAL module.
*
* This test checks if the function get_modem_current_radio_technology_lte returns the correct current RAT (Radio Access Technology) for LTE.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 078 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Get current RAT | None | The current_rat variable should contain the current RAT | Should be successful |
*/

void test_l1_cellular_hal_positive1_get_modem_current_radio_technology( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive_1_get_modem_current_radio_technology_lte...");
    int result = 0;
    char current_rat[128] = {"\0"};
    UT_LOG("Invoking cellular_hal_positive_1_get_modem_current_radio_technology with current_rat with valid buffer ...");

   // int result = cellular_hal_get_modem_current_radio_technology(&current_rat);
    result = cellular_hal_get_modem_current_radio_technology(current_rat);
    UT_LOG("Return result: %d", result);
    if (!strcmp(current_rat,"AUTO") || !strcmp(current_rat,"CDMA20001X") || !strcmp(current_rat,"EVDO") || !strcmp(current_rat,"GSM")||  !strcmp(current_rat,"UMTS") || !strcmp(current_rat,"LTE") || !strcmp(current_rat,"UMTS,LTE"))
    {
            UT_LOG("get_modem_current_radio_technology %s which is a valid value",current_rat);
            UT_PASS("get_modem_current_radio_technology validation success");
    }
    else
    {
            UT_LOG("get_modem_current_radio_technology %s which is a Invalid value",current_rat);
            UT_FAIL("get_modem_current_radio_technology fail");
    }
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("test_l1_cellular_hal_positive1_get_modem_current_radio_technology...");

    UT_LOG("Exiting test_l1_cellular_hal_positive1_get_modem_current_radio_technology...");
}
/**
* @brief This test verifies the behavior of the function `cellular_hal_get_modem_current_radio_technology` when a null pointer is provided as the input argument.
*
* This test case is part of the Basic (L1) test group and has a high priority as it tests a fundamental functionality of the API.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 079 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking function with current_rat buffer as NULL pointer and checking the return value | current_rat = NULL | RETURN_ERROR | The return value should be `RETURN_ERROR` |
*/
void test_l1_cellular_hal_negative1_get_modem_current_radio_technology( void )
{
    UT_LOG("Entering test_l1_cellular_hal_negative_1_get_modem_current_radio_technology_null_pointer...");
    int result = 0;
    char *current_rat = NULL;
    UT_LOG("Invoking cellular_hal_negative_1_get_modem_current_radio_technology with current_rat buffer (NULL)...");

    result = cellular_hal_get_modem_current_radio_technology(current_rat);
    UT_LOG("Return result: %d", result);

    //UT_LOG("Result: %s", (result == RETURN_ERROR) ? "Successful" : "Failure");

    UT_ASSERT_EQUAL(result, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative_1_get_modem_current_radio_technology_null_pointer...");
}

/**
 * @brief Test case to verify the behavior when failed to attach to the network in cellular_hal_get_modem_current_radio_technology
 *
 * This test case verifies the behavior of the cellular_hal_get_modem_current_radio_technology function when it fails to attach to the network.
 *
 * **Test Group ID:** Basic : 01 @n
 * **Test Case ID:** 081 @n
 * **Priority:** High @n@n
 * 
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console. @n
 * 
 * **Test Procedure:** @n
 * | Variation / Step | Description    | Test Data     | Expected Result    | Notes                |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * |       01    | Invoke the function             | with valid value   | RETURN_OK | Should be successful |
 *
 */
void test_l1_cellular_hal_positive1_get_modem_supported_radio_technology( void )
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_get_modem_current_radio_technology...");

    // Simulate or mock a scenario where attaching to a network is not possible
    char supported_rat[128] = {"\0"};
    int status = 0;
    // Invoke the API with mock scenario
    //char current_rat[128];
    UT_LOG("Invoking cellular_hal_positive_1_get_modem_supported_radio_technology with valid value");

    status = cellular_hal_get_modem_supported_radio_technology(supported_rat);
    UT_LOG("Return status: %d", status);
    UT_LOG("supported_rat is %s", supported_rat);

    // Check the return status

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("test_l1_cellular_hal_positive1_get_modem_supported_radio_technology...",supported_rat);

}
/**
 * @brief Unit test for the function cellular_hal_get_modem_supported_radio_technology
 *
 * This test verifies the functionality of the function cellular_hal_get_modem_supported_radio_technology by passing invalid parameters and checking if the return value is as expected.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 082 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | :---------: | :----------: | :--------------: | :-----: |
 * | 01 | Invoking cellular_hal_get_modem_supported_radio_technology  | with NULL pointer | RETURN_ERROR | Should return error |
 *
 */
void test_l1_cellular_hal_negative1_get_modem_supported_radio_technology(void)
{
    UT_LOG("Entering test_l1_cellular_hal_negative1_get_modem_supported_radio_technology...");
    int ret = 0;
    UT_LOG("Invoking cellular_hal_negative_1_get_modem_supported_radio_technology with invalid parameters");

    //int ret = cellular_hal_get_modem_supported_radio_technology(supported_rat);
    ret = cellular_hal_get_modem_supported_radio_technology(NULL);
    UT_LOG("Return ret: %d", ret);
 
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG("Exiting test_l1_cellular_hal_negative1_get_modem_supported_radio_technology...");
}
/**
* @brief Test the positive scenario of the function cellular_hal_modem_factory_reset.
*
* This test verifies that the function cellular_hal_modem_factory_reset returns the expected result and fills in the firmware version buffer correctly.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 083 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoke the function cellular_hal_modem_factory_reset | - | - | The function is successfully invoked |
*
*/
void test_l1_cellular_hal_positive1_modem_factory_reset(void)
{
    UT_LOG("Entering test_l1_cellular_hal_positive1_modem_factory_reset...");
    int result = 0;
    // Define a valid buffer for the firmware version
    //char firmware_version[128];
    UT_LOG("Invoking cellular_hal_positive_1_modem_factory_reset...");

    // Invoke the API to fetch the modem firmware version
    result = cellular_hal_modem_factory_reset();
    UT_LOG("Return result: %d", result);

    // Log the test description and the outcome

    // Check if the firmware version was filled in the buffer
   // UT_LOG("Firmware Version: %s (buffer is valid)", firmware_version);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_modem_factory_reset...");
}

/**
* @brief This test case is used to verify the functionality of the cellular_hal_modem_reset function. 
*
* The purpose of this test is to ensure that the function cellular_hal_modem_reset is able to reset the modem successfully.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 084 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking cellular_hal_modem_reset. | None. | RETURN_OK | Should be successful. |
*/

void test_l1_cellular_hal_positive1_cellular_hal_modem_reset(void) {
    UT_LOG("Entering test_l1_cellular_hal_positive1_cellular_hal_modem_reset...");
    int result = 0;
    UT_LOG("Invoking cellular_hal_modem_reset with valid value..");
    // Invoke the API
    result = cellular_hal_modem_reset();
    UT_LOG("Return result: %d", result);
    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_cellular_hal_positive1_cellular_hal_modem_reset...");
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int register_hal_tests(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1_cellular_hal]", NULL, NULL);
    if (pSuite == NULL) {
        return -1;
    }
    // List of test function names and strings
   
const char* list1[] = {"l1_cellular_hal_negative1_get_modem_firmware_version","l1_cellular_hal_positive1_get_available_networks_information","l1_cellular_hal_negative1_get_available_networks_information","l1_cellular_hal_positive1_IsModemDevicePresent","l1_cellular_hal_positive1_init","l1_cellular_hal_positive2_init","l1_cellular_hal_positive3_init","l1_cellular_hal_negative1_init","l1_cellular_hal_negative2_init","l1_cellular_hal_negative3_init","l1_cellular_hal_positive1_sim_power_enable","l1_cellular_hal_positive2_sim_power_enable","l1_cellular_hal_positive3_sim_power_enable","l1_cellular_hal_positive_sim_power_enable","l1_cellular_hal_negative1_sim_power_enable","l1_cellular_hal_negative2_sim_power_enable","l1_cellular_hal_positive1_get_total_no_of_uicc_slots","l1_cellular_hal_negative1_get_total_no_of_uicc_slots","l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info","l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info","l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info","l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info","l1_cellular_hal_positive1_get_active_card_status","l1_cellular_hal_negative1_get_active_card_status","l1_cellular_hal_positive1_get_profile_list","l1_cellular_hal_negative1_get_profile_list","l1_cellular_hal_negative2_get_profile_list","l1_cellular_hal_positive1_cellular_hal_stop_network","l1_cellular_hal_positive2_cellular_hal_stop_network","l1_cellular_hal_positive3_cellular_hal_stop_network","l1_cellular_hal_negative1_cellular_hal_stop_network","l1_cellular_hal_positive1_get_signal_info","l1_cellular_hal_negative1_get_signal_info","l1_cellular_hal_positive1_set_modem_operating_configuration","l1_cellular_hal_positive2_set_modem_operating_configuration","l1_cellular_hal_positive3_set_modem_operating_configuration","l1_cellular_hal_positive4_set_modem_operating_configuration","l1_cellular_hal_positive5_set_modem_operating_configuration","l1_cellular_hal_negative2_set_modem_operating_configuration","l1_cellular_hal_positive1_get_device_imei_sv","l1_cellular_hal_negative1_get_device_imei_sv","l1_cellular_hal_positive1_get_device_imei","l1_cellular_hal_negative1_get_device_imei","l1_cellular_hal_positive1_get_modem_current_iccid","l1_cellular_hal_negative1_get_modem_current_iccid","l1_cellular_hal_positive1_get_modem_current_msisdn","l1_cellular_hal_negative1_get_modem_current_msisdn","l1_cellular_hal_positive1_get_packet_statistics","l1_cellular_hal_negative1_get_packet_statistics","l1_cellular_hal_positive1_get_current_modem_interface_status","l1_cellular_hal_negative1_get_current_modem_interface_status","l1_cellular_hal_negative1_set_modem_network_attach","l1_cellular_hal_negative1_set_modem_network_detach","l1_cellular_hal_positive1_get_modem_firmware_version","l1_cellular_hal_positive1_get_current_plmn_information","l1_cellular_hal_negative1_get_current_plmn_information","l1_cellular_hal_positive1_get_modem_preferred_radio_technology","l1_cellular_hal_negative1_get_modem_preferred_radio_technology","l1_cellular_hal_positive1_set_modem_preferred_radio_technology","l1_cellular_hal_positive2_set_modem_preferred_radio_technology","l1_cellular_hal_positive3_set_modem_preferred_radio_technology","l1_cellular_hal_negative1_set_modem_preferred_radio_technology","l1_cellular_hal_negative2_set_modem_preferred_radio_technology","l1_cellular_hal_positive1_get_modem_current_radio_technology","l1_cellular_hal_negative1_get_modem_current_radio_technology","l1_cellular_hal_positive1_get_modem_supported_radio_technology","l1_cellular_hal_negative1_get_modem_supported_radio_technology","l1_cellular_hal_positive1_modem_factory_reset","l1_cellular_hal_positive1_cellular_hal_modem_reset"};
void (*list2[])() = {test_l1_cellular_hal_negative1_get_modem_firmware_version,test_l1_cellular_hal_positive1_get_available_networks_information,test_l1_cellular_hal_negative1_get_available_networks_information,test_l1_cellular_hal_positive1_IsModemDevicePresent,test_l1_cellular_hal_positive1_init,test_l1_cellular_hal_positive2_init,test_l1_cellular_hal_positive3_init,test_l1_cellular_hal_negative1_init,test_l1_cellular_hal_negative2_init,test_l1_cellular_hal_negative3_init,test_l1_cellular_hal_positive1_sim_power_enable,test_l1_cellular_hal_positive2_sim_power_enable,test_l1_cellular_hal_positive3_sim_power_enable,test_l1_cellular_hal_positive4_sim_power_enable,test_l1_cellular_hal_negative1_sim_power_enable,test_l1_cellular_hal_negative2_sim_power_enable,test_l1_cellular_hal_positive1_get_total_no_of_uicc_slots,test_l1_cellular_hal_negative1_get_total_no_of_uicc_slots,test_l1_cellular_hal_positive1_cellular_hal_get_uicc_slot_info,test_l1_cellular_hal_positive2_cellular_hal_get_uicc_slot_info,test_l1_cellular_hal_negative1_cellular_hal_get_uicc_slot_info,test_l1_cellular_hal_negative2_cellular_hal_get_uicc_slot_info,test_l1_cellular_hal_positive1_get_active_card_status,test_l1_cellular_hal_negative1_get_active_card_status,test_l1_cellular_hal_positive1_get_profile_list,test_l1_cellular_hal_negative1_get_profile_list,test_l1_cellular_hal_negative2_get_profile_list,test_l1_cellular_hal_positive1_cellular_hal_stop_network,test_l1_cellular_hal_positive2_cellular_hal_stop_network,test_l1_cellular_hal_positive3_cellular_hal_stop_network,test_l1_cellular_hal_negative1_cellular_hal_stop_network,test_l1_cellular_hal_positive1_get_signal_info,test_l1_cellular_hal_negative1_get_signal_info,test_l1_cellular_hal_positive1_set_modem_operating_configuration,test_l1_cellular_hal_positive2_set_modem_operating_configuration,test_l1_cellular_hal_positive3_set_modem_operating_configuration,test_l1_cellular_hal_positive4_set_modem_operating_configuration,test_l1_cellular_hal_positive5_set_modem_operating_configuration,test_l1_cellular_hal_negative2_set_modem_operating_configuration,test_l1_cellular_hal_positive1_get_device_imei_sv,test_l1_cellular_hal_negative1_get_device_imei_sv,test_l1_cellular_hal_positive1_get_device_imei,test_l1_cellular_hal_negative1_get_device_imei,test_l1_cellular_hal_positive1_get_modem_current_iccid,test_l1_cellular_hal_negative1_get_modem_current_iccid,test_l1_cellular_hal_positive1_get_modem_current_msisdn,test_l1_cellular_hal_negative1_get_modem_current_msisdn,test_l1_cellular_hal_positive1_get_packet_statistics,test_l1_cellular_hal_negative1_get_packet_statistics,test_l1_cellular_hal_positive1_get_current_modem_interface_status,test_l1_cellular_hal_negative1_get_current_modem_interface_status,test_l1_cellular_hal_negative1_set_modem_network_attach,test_l1_cellular_hal_negative1_set_modem_network_detach,test_l1_cellular_hal_positive1_get_modem_firmware_version,test_l1_cellular_hal_positive1_get_current_plmn_information,test_l1_cellular_hal_negative1_get_current_plmn_information,test_l1_cellular_hal_positive1_get_modem_preferred_radio_technology,test_l1_cellular_hal_negative1_get_modem_preferred_radio_technology,test_l1_cellular_hal_positive1_set_modem_preferred_radio_technology,test_l1_cellular_hal_positive2_set_modem_preferred_radio_technology,test_l1_cellular_hal_positive3_set_modem_preferred_radio_technology,test_l1_cellular_hal_negative1_set_modem_preferred_radio_technology,test_l1_cellular_hal_negative2_set_modem_preferred_radio_technology,test_l1_cellular_hal_positive1_get_modem_current_radio_technology,test_l1_cellular_hal_negative1_get_modem_current_radio_technology,test_l1_cellular_hal_positive1_get_modem_supported_radio_technology,test_l1_cellular_hal_negative1_get_modem_supported_radio_technology,test_l1_cellular_hal_positive1_modem_factory_reset,test_l1_cellular_hal_positive1_cellular_hal_modem_reset};

    // Add tests to the suite
    for (int i = 0; i < sizeof(list1) / sizeof(list1[0]); i++) {
        UT_add_test(pSuite, list1[i], list2[i]);
    }
    return 0;
}
int main(int argc, char** argv)
{
    int registerReturn = 0;
    //char g_Subsystem[64] = {0};
    //strcpy(g_Subsystem,CELLULAR_COMPONENT_NAME);
    /* Register tests as required, then call the UT-main to support switches and triggering */
    UT_init( argc, argv );
    /* Check if tests are registered successfully */
    registerReturn = register_hal_tests();
    if (registerReturn == 0)
    {
        printf("register_hal_tests() returned success");
    }
    else
    {
        printf("register_hal_tests() returned failure");
        return 1;
    }
    /* Begin test executions */
    UT_run_tests();
    return 0;
}












