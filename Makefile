# *
# * If not stated otherwise in this file or this component's LICENSE file the
# * following copyright and licenses apply:
# *
# * Copyright 2023 RDK Management
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# * http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *

AM_CFLAGS = -D_ANSC_LINUX
AM_CFLAGS += -D_ANSC_USER
AM_LDFLAGS = -lccsp_common
AM_LDFLAGS +=

AM_LDFLAGS += -lulog
AM_CPPFLAGS = -Wall -Werror
ACLOCAL_AMFLAGS = -I m4
hardware_platform = i686-linux-gnu
if CELLULAR_MGR_LITE
bin_PROGRAMS = cellularmanagerlite
cellularmanagerlite_CPPFLAGS = -I$(top_srcdir)/source/TR-181/include                   \
        -I$(top_srcdir)/../hal/include                                                \
        -I$(top_srcdir)/../CcspCommonLibrary/source/cosa/include/                  \
        -I$(top_srcdir)/../CcspCommonLibrary/source/ccsp/components/include/       \
        -I$(top_srcdir)/source/TR-181/middle_layer_src $(CPPFLAGS) \
        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rbus \
        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage

cellularmanagerlite_DEPENDENCIES= \
    $(EXTRA_DEPENDENCIES) \
    ${top_builddir}/source/TR-181/middle_layer_src/libcellularmanager_middle_layer_src.la

cellularmanagerlite_CFLAGS = $(SYSTEMD_CFLAGS) $(NONROOT_CFLAGS)

cellularmanagerlite_SOURCES = cellularmgr_cellular_apis.c cellularmgr_cellular_internal.c cellularmgr_ssp_action.c cellularmgr_ssp_internal.h cellularmgr_main.c cellularmgr_messagebus_interface.c cellular_hal_utils.c cellular_hal.c cellularmgr_bus_utils.c dm_pack_datamodel.c
cellularmanagerlite_LDFLAGS = -lccsp_common -ldl $(SYSTEMD_LDFLAGS) -lrdkloggers -lsyscfg -lnanomsg -lsysevent -lwebconfig_framework -lmsgpackc -lcurl -ltrower-base64 -lsecure_wrapper
cellularmanagerlite_LDADD =  $(cellularmanagerlite_DEPENDENCIES)
else
bin_PROGRAMS = cellularmanager
lib_LTLIBRARIES = cellular_manager.la

cellularmanager_CPPFLAGS = -I$(top_srcdir)/source/TR-181/include                   \
        -I$(top_srcdir)/../hal/include                                                \
        -I$(top_srcdir)/../CcspCommonLibrary/source/cosa/include/                  \
        -I$(top_srcdir)/../CcspCommonLibrary/source/ccsp/components/include/       \
        -I$(top_srcdir)/source/TR-181/middle_layer_src $(CPPFLAGS) \
        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rbus \
        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage

cellular_manager_la_CPPFLAGS = -I$(top_srcdir)/source/TR-181/include                   \
        -I$(top_srcdir)/../hal/include                                                \
        -I$(top_srcdir)/../CcspCommonLibrary/source/cosa/include/                  \
        -I$(top_srcdir)/../CcspCommonLibrary/source/ccsp/components/include/       \
        -I$(top_srcdir)/source/TR-181/middle_layer_src $(CPPFLAGS) \
        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rbus \
        -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/rtmessage
		
cellularmanager_DEPENDENCIES= \
    $(EXTRA_DEPENDENCIES) \
    ${top_builddir}/source/TR-181/middle_layer_src/libcellularmanager_middle_layer_src.la

cellular_manager_la_DEPENDENCIES= \
    $(EXTRA_DEPENDENCIES) \
    ${top_builddir}/source/TR-181/middle_layer_src/libcellularmanager_middle_layer_src.la
	
cellularmanager_CFLAGS = $(SYSTEMD_CFLAGS) $(NONROOT_CFLAGS)
cellular_manager_la_CFLAGS = $(SYSTEMD_CFLAGS) $(NONROOT_CFLAGS)

cellularmanager_SOURCES = cellularmgr_sm.c cellularmgr_cellular_apis.c cellularmgr_cellular_internal.c cellularmgr_ssp_action.c cellularmgr_ssp_internal.h cellularmgr_main.c cellularmgr_messagebus_interface.c cellular_hal_utils.c cellular_hal_qmi_apis.c cellular_hal.c cellularmgr_bus_utils.c dm_pack_datamodel.c
cellularmanager_LDFLAGS = -lccsp_common -ldl $(SYSTEMD_LDFLAGS) -lrdkloggers -lsyscfg -lnanomsg -lsysevent -lwebconfig_framework -lmsgpackc -lcurl -ltrower-base64 -lsecure_wrapper
cellularmanager_LDADD =  $(cellularmanager_DEPENDENCIES)

cellular_manager_la_SOURCES = cellularmgr_sm.c cellularmgr_cellular_apis.c cellularmgr_cellular_internal.c cellularmgr_ssp_action.c cellularmgr_ssp_internal.h cellularmgr_messagebus_interface.c cellular_hal_utils.c cellular_hal_qmi_apis.c cellular_hal.c cellularmgr_bus_utils.c dm_pack_datamodel.c
cellular_manager_la_LDFLAGS = -lccsp_common -ldl $(SYSTEMD_LDFLAGS) -lrdkloggers -lsyscfg -lnanomsg -lsysevent -lwebconfig_framework -lmsgpackc -lcurl -ltrower-base64 -lsecure_wrapper
cellular_manager_la_LDADD =  $(cellular_manager_la_DEPENDENCIES)

endif
