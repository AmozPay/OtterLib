#ifndef SERVER_H
#define SERVER_H
#include "OtterNetwork.hpp"

/***********************************************************/
namespace Otter::Network::Server {
    void init(Otter::Core::Orchestrator& ref);
    void update(Otter::Core::Orchestrator& ref);
    void update_msg(Otter::Core::Orchestrator& ref, int index);
    void update_session(Otter::Core::Orchestrator& ref, Otter::Network::SocketComponent& soc);

    bool test_header(std::stringstream const& dt, int idRef, int seq);

    std::uint32_t add_toServ(Otter::Network::ServerComponent& serv, udp::endpoint const& endp);
    void add_client(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::uint32_t id);
    std::uint32_t selecId(Otter::Network::ServerComponent& serv);
    int test_connect(Otter::Network::ServerComponent& serv, std::stringstream& dt);
    std::string connectMsg(std::uint32_t id);

    int tramFillMandatory(std::stringstream& ss, Otter::Network::ClientComponent& cl);
    int tramFill(std::stringstream& ss, Otter::Network::ClientComponent& cl);
    bool tramSending(Otter::Network::Session& session, Otter::Network::ClientComponent& cl);

    void computeTram(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::stringstream& ss,
                     int index);
}; // namespace Otter::Network::Server

#endif /* SERVER_H */
