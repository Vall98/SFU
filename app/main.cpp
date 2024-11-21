#include "cli.hpp"
#include "server.hpp"

#include <cstring>
#include <iostream>
#include <memory>
#include <thread>

// Parse the command and perform actions based on the flags.
// Returns 0 if the command is valid, 1 otherwise.
int parseCmd(int argc, char* argv[], int &t_port, bool &t_helpPrinted) {
    if (argc <= 1) {
        return 0;
    }

    // Handle port flag
    if (strcmp(argv[1], "-p") == 0) {
        if (argc >= 3) {
            try {
                t_port = std::stoi(argv[2]);
            } catch (const std::exception&) {
                std::cerr << "Invalid port number: " << argv[2] << std::endl;
                return 1;
            }
            return 0;
        } else {
            std::cerr << "Error: Missing port value after '-p'" << std::endl;
            return 1;
        }
    }

    // Handle help flags
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "?") == 0) {
        std::cout << " [-p port]\tRun the SFU server on the specified port. Default: "
        << sfu::SERVER_PORT_DEFAULT << "." << std::endl;
        std::cout << " [--help | ?]\tShow this help text." << std::endl;
        t_helpPrinted = true;
        return 0;
    }

    // Invalid argument
    std::cerr << "Unknown option: " << argv[1] << std::endl;
    std::cerr << "Use --help or ? for usage instructions." << std::endl;
    return 1;
}

int main(int argc, char* argv[]) {
    int port = sfu::SERVER_PORT_DEFAULT;
    bool helpPrinted = false;
    if (parseCmd(argc, argv, port, helpPrinted) != 0) {
        return 1;
    } else if (helpPrinted) {
        return 0;
    }
    sfu::Server server(port);
    sfu::CLI cli(server, argv[0]);
    return cli.run();
}

// 1- Client connects to the signaling channel
// 2- Client sends SDP offer through the signaling channel
// 3- Server process the SDP offer and generates SDP answer
// 4- Server sends the SDP answer through the signaling channel
// 5- 