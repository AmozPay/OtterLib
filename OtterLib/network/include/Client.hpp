#ifndef CLIENT_H
#define CLIENT_H
#include "ClientComponent.hpp"
#include "ServerComponent.hpp"
#include "OtterNetwork.hpp"
namespace Otter::Network::Client {
  /**
   * @brief function for start client
   *
   */
    void init(Otter::Core::Orchestrator& ref);

    /**
   * @brief function for update client
   *
   */
   void update(Otter::Core::Orchestrator& ref);

    void update_msg(Otter::Core::Orchestrator& ref, int index);
    void update_session(Otter::Core::Orchestrator& ref, int index);
    void update_connection(Otter::Core::Orchestrator& ref, int index);
    void update_recv(Otter::Core::Orchestrator& ref, int index);

    int test_conect(Otter::Network::ServerComponent& serv, std::stringstream& dt);

    int tramFillMandatory(std::stringstream& ss, Otter::Network::ClientComponent& cl);
    int tramFill(std::stringstream& ss, Otter::Network::ClientComponent& cl);
    bool tramSending(Otter::Network::Session& session, Otter::Network::ClientComponent& cl);

    void computeTram(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::stringstream& ss,
                     int index);

} // namespace Otter::Network::Client

#endif /* CLIENT_H */
