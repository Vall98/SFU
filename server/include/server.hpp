#pragma once

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <vector>

namespace sfu {

    const int SERVER_PORT_DEFAULT = 8000;

    typedef websocketpp::server<websocketpp::config::asio> server;

	class Server {
		public:
		Server();
		~Server();

        /// @brief Stops the server after closing the opened ports.
        /// @return 1 on error, 0 otherwise.
        int stop();

        /// @brief Check if the server is running.
        /// @return true if the server is running, false otherwise.
        bool isRunning();

        void run(int port);

		private:
		bool m_running { false };
        server m_wsServer;
        std::vector<websocketpp::connection_hdl> m_connections;
        std::thread m_wsThread;
	};
}