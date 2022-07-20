#include <gtest/gtest.h>

#include "iphelper.h"

using namespace IpHelper;

TEST(IpHelperTest, GetIp) {    
    ASSERT_EQ( getIp("113.162.145.156	111	0"), "113.162.145.156" );
    ASSERT_EQ( getIp("11.22"), "11.22" );
    ASSERT_EQ( getIp("11."), "11." );
    ASSERT_EQ( getIp("11"), "11" );
    ASSERT_EQ( getIp(".."), ".." );
    ASSERT_EQ( getIp(""), "" );
}

TEST(IpHelperTest, ToIpV4) {
    ASSERT_FALSE( (toIpV4("113.162.145.156") == IpV4{ 13, 162, 145, 156}) );
    ASSERT_TRUE( (toIpV4("113.162.145.156") == IpV4{ 113, 162, 145, 156}) );
    ASSERT_TRUE( (toIpV4("11.22") == IpV4{ 11, 22, 0, 0}) );
    ASSERT_TRUE( (toIpV4("11.") == IpV4{ 11, 0, 0, 0}) );
    ASSERT_TRUE( (toIpV4("11") == IpV4{ 11, 0, 0, 0}) );
    ASSERT_TRUE( (toIpV4("..") == IpV4{ 0, 0, 0, 0}) );
    ASSERT_TRUE( toIpV4("") == IpV4{} );
}

