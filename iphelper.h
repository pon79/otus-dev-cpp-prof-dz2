#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <set>

namespace IpHelper {

    struct IpV4 {
        unsigned char octet1{0};
        unsigned char octet2{0};
        unsigned char octet3{0};
        unsigned char octet4{0};
    };


    // lexicographically
    auto compare(){
        return [](const IpHelper::IpV4 &l, const IpHelper::IpV4 &r) {

            if( l.octet1 > r.octet1 )
                return true;
            else if( l.octet1 < r.octet1 )
                return false;

            if( l.octet2 > r.octet2 )
                return true;
            else if( l.octet2 < r.octet2 )
                return false;

            if( l.octet3 > r.octet3 )
                return true;
            else if( l.octet3 < r.octet3 )
                return false;

            if( l.octet4 > r.octet4 )
                return true;
            else if( l.octet4 < r.octet4 )
                return false;

            return true;
        };
    };

    using IpV4Pool = std::set<IpV4, decltype(compare())>;

    std::string getIp( const std::string &line ) {

        std::string ip;

        std::istringstream line_iss{line}; // line: 157.39.22.224	5	6

        line_iss >> ip; // only first word in line: 157.39.22.224

        return ip;        
    }

    IpV4 toIpV4( std::string ip ) {

        // istringstream don't work with '.'
        for (std::string::size_type pos{}; ip.npos != (pos = ip.find('.')); ) {
            ip.replace(pos, 1, " ");
        }

        std::istringstream ip_stream{ ip };

        int octet1{0}, octet2{0}, octet3{0}, octet4{0};
        ip_stream >> octet1 >> octet2 >> octet3 >> octet4;

        return {
            static_cast<unsigned char>(octet1),
            static_cast<unsigned char>(octet2),
            static_cast<unsigned char>(octet3),
            static_cast<unsigned char>(octet4)
        };
    }


    void printIpV4( const IpV4Pool & ipV4Pool ) {

        for( const auto & ipV4 : ipV4Pool ) {
            std::cout << std::to_string( ipV4.octet1 ) << '.'
                      << std::to_string( ipV4.octet2 ) << '.'
                      << std::to_string( ipV4.octet3 ) << '.'
                      << std::to_string( ipV4.octet4 ) << std::endl;
            }
    }


    void printIpV4( const IpV4Pool & ipV4Pool,
                    unsigned char octet1, unsigned char octet2 = 255,
                    unsigned char octet3 = 255 , unsigned char octet4 = 255 ) {

        auto it = std::lower_bound(ipV4Pool.begin(), ipV4Pool.end(), IpV4{ octet1, octet2, octet3, octet4}, compare() );

        for ( ;it != ipV4Pool.end(); ++it ) {
            std::cout << "ip: " << std::to_string( it->octet1 ) << '.'
                      << std::to_string( it->octet2 ) << '.'
                      << std::to_string( it->octet3) << '.'
                      << std::to_string( it->octet4 ) << std::endl;
        }
    }

    void printIpV4Any( const IpV4Pool & ipV4Pool, unsigned char octet ) {

    }

}