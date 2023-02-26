#ifndef DTOBJ_H
#define DTOBJ_H

namespace Otter::Network {
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

} // namespace Otter::Network
#endif /* DTOBJ_H */
