
#include "../include/Deserializer/Deserializer.hpp"
#include "../include/Serializer/Serializer.hpp"
#include "test.hpp"
#include <iostream>
#include <set>
#include <sstream>
#include <string>
/*int main()
{
  std::stringstream ss;
  std::string toto("azer\atoto");
  std::string res;

  ss << toto;
  ss << '\a';
  ss << "tata";

  std::cout << toto << std::endl;
  std::cout << ss.rdbuf() << std::endl;
  res = ss.str();
  std::cout << res << std::endl;
  if (res == toto)
    return 0;
  return 84;
}
*/
/*  Not Work
int main()
{
  std::stringstream ss;
  uint32_t x = 12;
  uint32_t y = 1789456;
  uint32_t z = 0;

  ss << x;
  ss << y;
  ss << z;

  std::cout << ss.str() << std::endl;
  uint32_t xtmp;
  uint32_t ytmp;
  uint32_t ztmp;

  ss >> xtmp;
  ss >> ytmp;
  ss >> ztmp;

  std::cout << xtmp << "|" << ytmp << "|" << ztmp << std::endl;
}
*/
/*
int main()
{
  std::stringstream ss;
  uint32_t x = 12;
  uint32_t y = 1789456;
  uint32_t z = 0;
  Otter::Network::Serializer::saveArchive(ss, x);
  Otter::Network::Serializer::saveArchive(ss, y);
  Otter::Network::Serializer::saveArchive(ss, z);

  std::cout << ss.str() << std::endl;
  uint32_t xtmp;
  uint32_t ytmp;
  uint32_t ztmp;

 xtmp =  Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
  ytmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
  ztmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);

  std::cout << xtmp << "|" << ytmp << "|" << ztmp << std::endl;
  return 0;
}
*/
/*
int main()
{
    std::stringstream ss;
    std::stringstream ss1;    
    uint32_t magic = 12;
    uint32_t seq = 1789456;
    uint32_t id = 0;
    uint8_t len = 48;
    dtObj dt;
    dt.msgCode = 1;
    dt.ss = "toto";
    
    Otter::Network::Serializer::saveArchive(ss1, dt);

    
    Otter::Network::Serializer::saveArchive(ss, magic);
    Otter::Network::Serializer::saveArchive(ss, seq);
    Otter::Network::Serializer::saveArchive(ss, id);
    Otter::Network::Serializer::saveArchive<uint8_t>(ss, len);

    std::cout << ss.str() << std::endl;
    ss << ss1.str();    
    std::cout << ss.str() << std::endl;
   
    uint32_t xtmp;
    uint32_t ytmp;
    uint32_t ztmp;
    uint8_t atmp;
    xtmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
    ytmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
    ztmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
    atmp = Otter::Network::Deserializer::loadArchive<uint8_t>(ss);

    std::cout << xtmp << "|" << ytmp << "|" << ztmp << "|" << atmp << " end" << std::endl;

    dtObj dt_ = Otter::Network::Deserializer::loadArchive<dtObj>(ss);

    std::cout << dt_.msgCode << std::endl;
    std::cout << dt.ss << "|" << std::endl;
    return 0;
}
*/
