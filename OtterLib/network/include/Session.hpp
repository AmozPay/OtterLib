#pragma once
#include <boost/asio.hpp>
#include <memory>

namespace Otter::Network {

    using boost::asio::ip::udp;

    class Socket;

    class Session {
      public:
        friend class Socket;

        Session(const udp::endpoint& endpoint, Socket& socket);

        void send(const std::string& data);
        void recv(std::stringstream& data);

        const udp::endpoint& get_endpoint(void) const;

      protected:
      private:
        Otter::Network::Socket& _socket;
        udp::endpoint _endpoint;
        std::stringstream _data;
        std::shared_ptr<std::mutex> _data_lock;
    };

    typedef std::shared_ptr<Session> SessionPtr;
} // namespace Otter::Network
