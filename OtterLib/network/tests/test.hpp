#include "../include/Serializable/Serializable.hpp"

#include <sstream>

struct dtObj : public Otter::Network::Serializable {

    dtObj(){};
    ~dtObj(){};

    boost::archive::binary_oarchive& operator&(boost::archive::binary_oarchive& archive)
    {
        archive& msgCode;
        archive& ss;
        return archive;
    }

    boost::archive::binary_iarchive& operator&(boost::archive::binary_iarchive& archive)
    {
        archive& msgCode;
        archive& ss;
        return archive;
    }

    std::uint32_t msgCode;
    std::string ss;
};

struct msgObj : public Otter::Network::Serializable {
    msgObj(){};
    ~msgObj(){};

    boost::archive::binary_oarchive& operator&(boost::archive::binary_oarchive& archive)
    {
        archive& msg;
        archive& ss;

        return archive;
    }

    boost::archive::binary_iarchive& operator&(boost::archive::binary_iarchive& archive)
    {
        archive& msg;
        archive& ss;
        return archive;
    }

    std::string ss;
    std::uint32_t msg;
};
