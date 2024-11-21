#include "cli.hpp"

#include <csignal>
#include <iostream>

using namespace sfu;

bool CLI::m_sigint = false;

CLI::CLI(Server &t_server, const char* const name): m_server(t_server), m_app(name) {
    signal(SIGINT, signalHandler);
}

CLI::~CLI() {
    stop();
}

// Dictionary of functions to call in relation to the command entered.
const std::unordered_map<std::string, std::function<int(CLI&)>> CLI::m_funcMap = {
    {"stop", &CLI::stop},
};

int CLI::stop() {
    return m_server.stop();
}

void CLI::help() {
    std::cout << "stop\tStops the server." << std::endl;
}

int CLI::run() {
    std::string input;
    std::cout << "Enter \"stop\" to stop the server." << std::endl;
    while (!CLI::m_sigint && m_server.isRunning() && !std::cin.eof()) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input.length() > 0) {
            try {
                m_funcMap.at(input)(*this);
            } catch (std::out_of_range _) {
                help();
            }
        }
    }
    return 0;
}

void CLI::signalHandler(int t_signal) {
    std::cout << t_signal << std::endl;
    CLI::m_sigint = true;
}