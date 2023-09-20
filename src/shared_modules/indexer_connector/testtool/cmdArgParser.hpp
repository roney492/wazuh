/*
 * Wazuh cmdLineParser
 * Copyright (C) 2015, Wazuh Inc.
 * September 12, 2023.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#ifndef _CMD_ARGS_PARSER_HPP_
#define _CMD_ARGS_PARSER_HPP_

#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Class to parse command line arguments.
 */
class CmdLineArgs
{
public:
    /**
     * @brief Constructor for CmdLineArgs.
     * @param argc Number of arguments.
     * @param argv Arguments.
     */
    explicit CmdLineArgs(const int argc, const char* argv[])
        : m_configurationFilePath {paramValueOf(argc, argv, "-c")}
        , m_templateFilePath {paramValueOf(argc, argv, "-t")}
        , m_eventsFilePath {paramValueOf(argc, argv, "-e", std::make_pair(false, ""))}
        , m_autoGenerated {paramValueOf(argc, argv, "-a", std::make_pair(false, ""))}
        , m_numberOfEvents {paramValueOf(argc, argv, "-n", std::make_pair(false, ""))}
    {
    }

    /**
     * @brief Gets the configuration file path.
     * @return Configuration file path.
     */
    const std::string& getConfigurationFilePath() const
    {
        return m_configurationFilePath;
    }

    /**
     * @brief Gets the template file path.
     * @return Template file path.
     */
    const std::string& getTemplateFilePath() const
    {
        return m_templateFilePath;
    }

    /**
     * @brief Gets the events file path.
     * @return Events file path.
     */
    const std::string& getEventsFilePath() const
    {
        return m_eventsFilePath;
    }

    /**
     * @brief Gets the auto generated flag.
     * @return Auto generated flag.
     */
    bool getAutoGenerated() const
    {
        return m_autoGenerated.compare("true") == 0;
    }

    /**
     * @brief Gets the number of events.
     * @return Number of events.
     */

    uint64_t getNumberOfEvents() const
    {
        return std::stoull(m_numberOfEvents);
    }

    /**
     * @brief Shows the help to the user.
     */
    static void showHelp()
    {
        std::cout << "\nUsage: indexer_connector_testtool <option(s)> SOURCES \n"
                  << "Options:\n"
                  << "\t-h \t\t\tShow this help message\n"
                  << "\t-c CONFIG_FILE\tSpecifies the configuration file.\n"
                  << "\t-t TEMPLATE_FILE\tSpecifies the template file.\n"
                  << "\t-e EVENTS_FILE\tSpecifies the events file.\n"
                  << "\t-a AUTO_GENERATED\tSpecifies if the events are auto generated.\n"
                  << "\t-n NUMBER_OF_EVENTS\tSpecifies the number of events to generate.\n"
                  << "\nExample:"
                  << "\n\t./indexer_connector_testtool -c config.json -t template.json\n"
                  << "\n\t./indexer_connector_testtool -c config.json -t template.json -e events.json\n"
                  << "\n\t./indexer_connector_testtool -c config.json -t template.json -a true -n 10000\n"
                  << std::endl;
    }

private:
    static std::string paramValueOf(const int argc,
                                    const char* argv[],
                                    const std::string& switchValue,
                                    const std::pair<bool, std::string>& required = std::make_pair(true, ""))
    {
        for (int i = 1; i < argc; ++i)
        {
            const std::string currentValue {argv[i]};

            if (currentValue == switchValue && i + 1 < argc)
            {
                // Switch found
                return argv[i + 1];
            }
        }

        if (required.first)
        {
            throw std::runtime_error {"Switch value: " + switchValue + " not found."};
        }

        return required.second;
    }
    const std::string m_templateFilePath;
    const std::string m_configurationFilePath;
    const std::string m_eventsFilePath;
    const std::string m_numberOfEvents;
    const std::string m_autoGenerated;
};

#endif // _CMD_ARGS_PARSER_HPP_
