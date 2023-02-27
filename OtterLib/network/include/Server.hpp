#ifndef SERVER_H
#define SERVER_H
#include "ServerComponent.hpp"
#include "ClientComponent.hpp"
#include "OtterNetwork.hpp"
/***********************************************************/
namespace Otter::Network::Server {


  /**
   * @brief function for start server
   * 
   */
  void init(Otter::Core::Orchestrator& ref);

    /**
   * @brief function for update the server
   * 
   */
   void update(Otter::Core::Orchestrator& ref);
  

  /**
   * @brief a function that wil compute all msg that need to be send
   * 
   */
    void update_msg(Otter::Core::Orchestrator& ref, int index);

  /**
   * @brief function that chec all new connection
   * @details get all new session of the socket and Chec if the header is righ.
   * 
   */
    void update_session(Otter::Core::Orchestrator& ref, Otter::Network::SocketComponent& soc);

  /**
   * @brief function that chec all msg recieve
   * @details chec all msg receive for all session. and execute them
   */
    void update_recv(Otter::Core::Orchestrator& ref, int index);


    /**
   * @brief function that chec the header
   *
   * @details this function chec of the format is righ, if the sequence is righ and if the id is right
   * @params const stringstream that need to be checked
   * @warning cost more time and power cause he copy the dt
   */
  bool test_header(std::stringstream const& dt, int idRef, int seq);


  /////////////////////bloc function that that test and a new new session////////////////////////////////////////
    std::uint32_t add_toServ(Otter::Network::ServerComponent& serv, udp::endpoint const& endp);
    void add_client(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::uint32_t id);
    std::uint32_t selecId(Otter::Network::ServerComponent& serv);
    int test_connect(Otter::Network::ServerComponent& serv, std::stringstream& dt);
    std::string connectMsg(std::uint32_t id);


  ///////////////////////bloc function for sending msg////////////////
  int tramFillMandatory(std::stringstream& ss, Otter::Network::ClientComponent& cl);
    int tramFill(std::stringstream& ss, Otter::Network::ClientComponent& cl);
    bool tramSending(Otter::Network::Session& session, Otter::Network::ClientComponent& cl);


  ///////////////////////function for compute recived data/////////////////////////////////////////////
    void computeTram(Otter::Core::Orchestrator& ref, Otter::Network::ServerComponent& serv, std::stringstream& ss,
                     int index);
}; // namespace Otter::Network::Server

#endif /* SERVER_H */
