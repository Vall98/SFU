#include "server.hpp"

#include <iostream>
#include <thread>

using namespace sfu;

// Starts the server on specified port, default 10000.
// @param port the port to listen to.
Server::Server(int port) {
	if (port <= 0) {
		port = 10000;
	}
	// TODO new thread
	m_running = true;
    std::cout << "Running on " << port << "." << std::endl;
    //std::thread servTh(run);
	//while (this->m_running) {
	//	
	//}
}

Server::~Server() {
	this->stop();
}

void Server::run() {

}

int Server::stop() {
    if (!m_running) {
        return 0;
    }
    m_running = false;
    std::cout << "Server stopped." << std::endl;
    // TODO close the ports
	// TODO join the threads
    return 0;
}

bool Server::isRunning() { 
    return m_running;
}