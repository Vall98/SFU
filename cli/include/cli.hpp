#pragma once

#include "server.hpp"

#include <unordered_map>
#include <functional>
#include <string>

namespace sfu {
    class CLI {
        public:
        CLI(Server &t_server, const char* const name);
        ~CLI();

        /// @brief Prints the CLI help text in the standard output.
        void help();

        /// @brief Reads the standard input for CLI commands.
        /// @return 1 if the command is not recognized, 0 otherwise.
        int run();

        private:
        static bool m_sigint;
        static void signalHandler(int t_signal);

        Server &m_server;
        std::string m_app;

        // Keeping this dict const is very important to prevent function injections.
        static const std::unordered_map<std::string, std::function<int(CLI&)>> m_funcMap;
        int stop();
    };
}