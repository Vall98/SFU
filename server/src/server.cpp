#include "server.hpp"

#include <iostream>
#include <thread>

using namespace sfu;

// Starts the server on specified port, default 10000.
// @param port the port to listen to.
Server::Server() {
    // Set logging settings
    m_wsServer.set_error_channels(websocketpp::log::elevel::all);
    m_wsServer.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);

    // Initialize Asio
    m_wsServer.init_asio();
}

Server::~Server() {
	this->stop();
}

void Server::run(int port) {
    if (port <= 0) {
		port = SERVER_PORT_DEFAULT;
	}
    m_wsServer.listen(port);
    m_wsServer.start_accept();
    m_wsThread = std::thread([this]() {
        m_wsServer.run();
    });

    m_running = true;
    std::cout << "Running on " << port << "." << std::endl;
}

int Server::stop() {
    if (!m_running) {
        return 0;
    }
    for (auto& conn : m_connections) {
        m_wsServer.close(conn, websocketpp::close::status::normal, "Server shutting down.");
    }
    m_wsServer.get_io_service().stop();
    m_wsThread.join();
    m_running = false;
    std::cout << "Server stopped." << std::endl;
    return 0;
}

bool Server::isRunning() { 
    return m_running;
}