#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>

#include "iphelper.h"

int main()
{
    try
    {        
        IpHelper::IpV4Pool ipV4_pool; // compare - lexicographically

        for( std::string line; std::getline(std::cin, line); )
        {
            ipV4_pool.insert( IpHelper::toIpV4( IpHelper::getIp( line ) ) );
        }

        IpHelper::printIpV4Pool( ipV4_pool );

        IpHelper::printIpV4Pool( ipV4_pool, 1 );

        IpHelper::printIpV4Pool( ipV4_pool, 46, 70 );

        IpHelper::printIpV4Any( ipV4_pool, 46 );
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
