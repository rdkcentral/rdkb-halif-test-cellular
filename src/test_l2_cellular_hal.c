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
* @file test_l2_cellular_hal.c
* @page cellular_hal Level 2 Tests
*
* ## Module's Role
* This module includes Level 2 functional tests (success and failure scenarios).
* This is to ensure that the cellular_hal APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include<string.h>
#include "cellular_hal.h"


/**
 * @brief Verify the output of the function test_l2_cellular_hal_get_modem_preferred_radio_technology.
 *
 * This test case is used to verify the output of the cellular_hal_get_modem_preferred_radio_technology function.
 * The function is called and the return status and output are verified.
 *
 * **Test Group ID:** 02
 * **Test Case ID:** 001
 *
 * **Test Procedure:**
 * Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
 */
void test_l2_cellular_hal_get_set_modem_preferred_radio_technology(void) 
{
    UT_LOG("Entering test_l2_cellular_hal_get_set_modem_preferred_radio_technology...");
    char preferred_rat[128] = {'\0'};
    char new_rat[128] = "AUTO";
    int status = 0;
    
    UT_LOG("invoking  cellular_hal_get_modem_preferred_radio_technology with valid output buffer");   
    status = cellular_hal_get_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("return status : %d preferred radio technology :  %s ",status,preferred_rat);
    if(status == RETURN_OK)
    {
        UT_LOG("return status of cellular_hal_get_modem_preferred_radio_technology = %d",status);
        UT_PASS("valid return status of cellular_hal_get_modem_preferred_radio_technology");
    }
    else
    {
        UT_LOG("return status of cellular_hal_get_modem_preferred_radio_technology = %d",status);
        UT_FAIL("invalid return status of cellular_hal_get_modem_preferred_radio_technology ");
    }

    if(preferred_rat == NULL || preferred_rat[0] == '\0')
    {
        UT_LOG("preferred radio technology is empty string");
        UT_FAIL("preferred radio technology is empty string");
    }
    else if(!strcmp(preferred_rat,"LTE") || !strcmp(preferred_rat,"AUTO") || !strcmp(preferred_rat,"CDMA20001X") || !strcmp(preferred_rat,"EVDO") || !strcmp(preferred_rat,"GSM") || !strcmp(preferred_rat,"UMTS"))
    {
        UT_LOG("preferred radio technology is valid ");
        UT_PASS("preferred radio technology is valid");    
    }
    else
    {
        UT_LOG("preferred radio technology is invalid string");
        UT_FAIL("preferred radio technology is invalid string");  
    }      
    
    if(!strcmp(preferred_rat,"AUTO"))
    {
        memset(new_rat,0,sizeof(new_rat));
        strcpy(new_rat,"LTE");
    }
    
    UT_LOG("invoking  cellular_hal_set_modem_preferred_radio_technology with valid input : %s ",new_rat);
    status = cellular_hal_set_modem_preferred_radio_technology(new_rat);
    UT_LOG("return status : %d ",status);
    if(status == RETURN_OK)
    {
        UT_LOG("return status of cellular_hal_set_modem_preferred_radio_technology = %d",status);
        UT_PASS("valid return status of cellular_hal_set_modem_preferred_radio_technology");
    }
    else
    {
        UT_LOG("return status of cellular_hal_set_modem_preferred_radio_technology = %d",status);
        UT_FAIL("invalid return status of cellular_hal_set_modem_preferred_radio_technology ");
    }

    memset(preferred_rat,0,sizeof(preferred_rat));    
    UT_LOG("invoking  cellular_hal_get_modem_preferred_radio_technology with valid output buffer");   
    status = cellular_hal_get_modem_preferred_radio_technology(preferred_rat);
    UT_LOG("return status : %d preferred radio technology :  %s ",status,preferred_rat);
    if(status == RETURN_OK)
    {
        UT_LOG("return status of cellular_hal_get_modem_preferred_radio_technology = %d",status);
        UT_PASS("valid return status of cellular_hal_get_modem_preferred_radio_technology");
    }
    else
    {
        UT_LOG("return status of cellular_hal_get_modem_preferred_radio_technology = %d",status);
        UT_FAIL("invalid return status of cellular_hal_get_modem_preferred_radio_technology ");
    }

    if(preferred_rat == NULL || preferred_rat[0] == '\0')
    {
        UT_LOG("preferred radio technology is empty string .");
        UT_FAIL("preferred radio technology is empty string");
    }
    else if(!strcmp(preferred_rat,new_rat))
    {
        UT_LOG("cellular_hal_set_modem_preferred_radio_technology is successful");
        UT_PASS("cellular_hal_set_modem_preferred_radio_technology is successful");    
    }
    else
    {
        UT_LOG("cellular_hal_set_modem_preferred_radio_technology is failed");
        UT_FAIL("cellular_hal_set_modem_preferred_radio_technology is failed");         
    }                
    
    UT_LOG("Exiting test_l2_cellular_hal_get_set_modem_preferred_radio_technology...");    
}


static UT_test_suite_t * pSuite = NULL;


int test_cellular_hal_l2_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L2 cellular_hal]", NULL, NULL);
    if (pSuite == NULL) {
        return -1;
    }

    UT_add_test(pSuite, "l2_cellular_hal_get_set_modem_preferred_radio_technology", test_l2_cellular_hal_get_set_modem_preferred_radio_technology);

    return 0;
}

