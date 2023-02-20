
#include "../include/Deserializer/Deserializer.hpp"
#include "../include/Serializer/Serializer.hpp"
#include "test.hpp"

#include <iostream>
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

int main()
{
    std::stringstream ss;
    uint32_t magic = 12;
    uint32_t seq = 1789456;
    uint32_t id = 0;
    Otter::Network::Serializer::saveArchive(ss, magic);
    Otter::Network::Serializer::saveArchive(ss, seq);
    Otter::Network::Serializer::saveArchive(ss, id);

    dtObj dt;
    dt.len = 18;

    msgObj msg;
    msg.ss = "my msg";
    msg.msg = 2;
    std::stringstream tmp;
    Otter::Network::Serializer::saveArchive(tmp, msg);

    dt.ss = tmp.str();
    Otter::Network::Serializer::saveArchive(ss, dt);
    std::cout << ss.str() << std::endl;

    uint32_t xtmp;
    uint32_t ytmp;
    uint32_t ztmp;

    xtmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
    ytmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);
    ztmp = Otter::Network::Deserializer::loadArchive<uint32_t>(ss);

    std::cout << xtmp << "|" << ytmp << "|" << ztmp << std::endl;

    dtObj dt_ = Otter::Network::Deserializer::loadArchive<dtObj>(ss);
    std::stringstream yo(dt_.ss);
    msgObj res = Otter::Network::Deserializer::loadArchive<msgObj>(yo);

    std::cout << dt_.len << std::endl;
    std::cout << res.msg << "|" << res.ss << std::endl;
    return 0;
}
