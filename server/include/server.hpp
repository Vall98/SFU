#pragma once

namespace sfu {

    const int SERVER_PORT_DEFAULT = 10000;

	class Server {
		public:
		Server(int port);
		~Server();

        /// @brief Stops the server after closing the opened ports.
        /// @return 1 on error, 0 otherwise.
        int stop();

        /// @brief Check if the server is running.
        /// @return true if the server is running, false otherwise.
        bool isRunning();

		private:
		bool m_running { false };
        void run();
	};
}