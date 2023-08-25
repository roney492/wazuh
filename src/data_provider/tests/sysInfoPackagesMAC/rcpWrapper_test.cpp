/*
 * Wazuh SysInfo
 * Copyright (C) 2015, Wazuh Inc.
 * August 10, 2023.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#include "rcpWrapper_test.h"
#include "packages/packageMac.h"
#include "packages/rcpWrapper.h"
#include <unistd.h>
#include <iostream>
#include <algorithm>

void RCPWrapperTest::SetUp() {};

void RCPWrapperTest::TearDown() {};

using ::testing::_;
using ::testing::Return;

TEST_F(RCPWrapperTest, Wazuh)
{
    std::string inputPath;
    inputPath += getwd(NULL);
    inputPath += "/input_files/RCPWrapperTest_Wazuh";
    std::string package { "com.wazuh.pkg.wazuh-agent" };

    struct PackageContext ctx
    {
        inputPath, package, ""
    };
    std::shared_ptr<RCPWrapper> wrapper;
    EXPECT_NO_THROW(wrapper = std::make_shared<RCPWrapper>(ctx));
    EXPECT_EQ(wrapper->name(), "");
    EXPECT_EQ(wrapper->version(), "4.4.5-1");
    EXPECT_EQ(wrapper->groups(), UNKNOWN_VALUE);
    EXPECT_EQ(wrapper->description(), UNKNOWN_VALUE);
    EXPECT_EQ(wrapper->architecture(), UNKNOWN_VALUE);
    EXPECT_EQ(wrapper->format(), "rcp");
    EXPECT_EQ(wrapper->osPatch(), "");
    EXPECT_EQ(wrapper->source(), "applications");
    EXPECT_EQ(wrapper->location(), inputPath + "/" + package + ".plist");
    EXPECT_EQ(wrapper->vendor(), UNKNOWN_VALUE);
    EXPECT_EQ(wrapper->priority(), UNKNOWN_VALUE);
    EXPECT_EQ(wrapper->size(), 0);
    EXPECT_EQ(wrapper->install_time(), UNKNOWN_VALUE);
    EXPECT_EQ(wrapper->multiarch(), "");
    EXPECT_EQ(wrapper->installPrefixPath(), "/");
    auto bomPaths = wrapper->bomPaths();
    EXPECT_EQ(bomPaths.size(), (size_t)248);
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/.ssh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/default-firewall-drop"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/disable-account"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/firewall-drop"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/firewalld-drop"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/host-deny"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/ip-customblock"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/ipfw"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/kaspersky"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/kaspersky.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/npf"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/pf"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/restart-wazuh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/restart.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/route-null"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/active-response/bin/wazuh-slack"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/main.exp"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/register_host.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh.exp"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_asa-fwsmconfig_diff"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_foundry_diff"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_generic_diff"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_integrity_check_bsd"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_integrity_check_linux"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_nopass.exp"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/ssh_pixconfig_diff"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/sshlogin.exp"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/agentless/su.exp"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/agent-auth"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/manage_agents"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/wazuh-agentd"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/wazuh-control"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/wazuh-execd"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/wazuh-logcollector"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/wazuh-modulesd"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/bin/wazuh-syscheckd"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/client.keys"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/internal_options.conf"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/local_internal_options.conf"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/localtime"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/ossec.conf"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_apache2224_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_debian_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_mysql5-6_community_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_mysql5-6_enterprise_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_rhel5_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_rhel6_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_rhel7_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_rhel_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_sles11_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_sles12_linux_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_win2012r2_domainL1_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_win2012r2_domainL2_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_win2012r2_memberL1_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/cis_win2012r2_memberL2_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/rootkit_files.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/rootkit_trojans.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/system_audit_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/system_audit_ssh.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/win_applications_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/win_audit_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/shared/win_malware_rcl.txt"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/etc/wpk_root.pem"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib/libdbsync.dylib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib/librsync.dylib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib/libsyscollector.dylib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib/libsysinfo.dylib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib/libwazuhext.dylib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/lib/libwazuhshared.dylib"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/logs"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/logs/active-responses.log"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/logs/ossec.json"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/logs/ossec.log"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/logs/wazuh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/add_localfiles.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/15"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/15/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/16"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/16/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/16/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/17"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/17/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/17/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/18"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/18/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/18/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/19"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/19/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/19/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/20"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/20/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/20/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/21"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/21/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/21/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/22"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/22/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/22/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/localfile-commands.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/localfile-extra.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/sca.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/syscheck.agent.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/syscheck.manager.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/darwin/wodle-syscollector.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/alerts.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/ar-commands.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/ar-definitions.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/auth.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/cluster.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/global-ar.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/global.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/header-comments.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-commands.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs/apache-logs.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs/audit-logs.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs/ossec-logs.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs/pgsql-logs.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs/snort-logs.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/localfile-logs/syslog-logs.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/logging.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/osquery.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/remote-secure.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/rootcheck.agent.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/rootcheck.manager.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/rule_test.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/rules.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/sca.manager.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/sca.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/syscheck.agent.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/syscheck.manager.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/wodle-ciscat.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/wodle-syscollector.template"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/etc/templates/config/generic/wodle-vulnerability-detector.manager.template"),
              bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/gen_ossec.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/15"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/15/cis_apple_macOS_10.11.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/15/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/16"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/16/cis_apple_macOS_10.12.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/16/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/17"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/17/cis_apple_macOS_10.13.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/17/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/18"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/18/cis_apple_macOS_10.14.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/18/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/19"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/19/cis_apple_macOS_10.15.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/19/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/20"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/20/cis_apple_macOS_11.1.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/20/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/21"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/21/cis_apple_macOS_12.0.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/21/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/22"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/22/cis_apple_macOS_13.x.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/darwin/22/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/generic"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/generic/sca.files"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/sca/generic/sca_unix_audit.yml"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/REVISION"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/VERSION"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/adduser.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/darwin-addusers.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/darwin-delete-oldusers.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/darwin-init.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/delete-oldusers.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/dist-detect.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/functions.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/fw-check.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/init.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/inst-functions.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/language.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/pkg_installer.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/pkg_installer_mac.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/register_configure_agent.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/replace_manager_ip.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/shared.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/template-select.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/update.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/wazuh-client.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/wazuh-local.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/wazuh-server.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/packages_files/agent_installation_scripts/src/init/wazuh.sh"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/alerts"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/diff"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/fim"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/fim/db"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/logcollector"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/rids"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/sockets"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/syscollector"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/syscollector/db"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/queue/syscollector/norm_config.json"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/ruleset"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/ruleset/sca"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/tmp"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/var"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/var/incoming"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/var/run"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/var/selinux"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/var/upgrade"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/var/wodles"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/__init__.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/aws"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/aws/aws-s3"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/azure"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/azure/azure-logs"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/azure/orm.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/docker"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/docker/DockerListener"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/buckets"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/buckets/access_logs.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/buckets/bucket.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/exceptions.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/gcloud"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/integration.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/pubsub"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/pubsub/subscriber.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/gcloud/tools.py"), bomPaths.end());
    EXPECT_NE(std::find(bomPaths.begin(), bomPaths.end(), "/Library/Ossec/wodles/utils.py"), bomPaths.end());
}
