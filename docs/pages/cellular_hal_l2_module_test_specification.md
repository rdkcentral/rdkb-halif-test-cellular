### Test 1

|Title|Details|
|--|--|
|Function Name|`test_l2_cellular_hal_get_set_modem_preferred_radio_technology`|
|Description|This test verifies whether the function `test_l2_cellular_hal_get_set_modem_preferred_radio_technology()` is able to successfully retrieve and set the preferred radio technology for the modem properly.|
|Test Group|Module : 02|
|Test Case ID|001|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :** None

**User Interaction :** If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

|Variation / Steps | Description | Test Data | Expected Result | Notes|
|--|--|--|--|--|
| 01 | Invoke the function `test_l2_cellular_hal_get_set_modem_preferred_radio_technology()` with 128 char buffer | preferred_rat = 128 char buffer | Function should execute without causing any error and should successfully retrieve and set the preferred radio technology for the modem. | Should be successful |


