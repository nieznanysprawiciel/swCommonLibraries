#include "swCommonLib/External/Catch/catch.hpp"
/**
@file TestMacros.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/Macros/ForEach.h"
#include "swCommonLib/Common/Macros/GenerateOperators.h"

#include "swCommonLib/TestUtils/CatchUtils/ExtendedMacros.h"




#define APPEND_TEST(X) test##X
#define MAKE_STRING(X) #X

// This macro will first evaluate expression, so it can be converted to string.
#define STR(X) MAKE_STRING(X)

// ================================ //
//
TEST_CASE( "Common.Helpers.Macros.FOR_EACH", "[Version]" )
{
    CHECK( STR( FOR_EACH( APPEND_TEST, x, y, z ) ) == "testx,testy,testz" );
    CHECK( STR( FOR_EACH( APPEND_TEST, x, y, z, u, v ) ) == "testx,testy,testz,testu,testv" );
}


//====================================================================================//
//			Equality operators	
//====================================================================================//

struct Test
{
    int x;
    int y;
    int z;
};

GENERATE_EQUALITY_OPERATORS( Test, x, y, z );


// ================================ //
// Test checks if default operator== was generated by macro.
// Test won't compile if macros doesn't work.
TEST_CASE( "Common.Helpers.Macros.GENERATE_EQUAL_OPERATOR", "[Version]" )
{
    Test test1 = { 1, 2, 3 };
    Test test2 = { 1, 2, 3 };

    CHECK( test1 == test2 );
}

// ================================ //
// Test checks if default operator!= was generated by macro.
// Test won't compile if macros doesn't work.
TEST_CASE( "Common.Helpers.Macros.GENERATE_NOT_EQUAL_OPERATOR", "[Version]" )
{
    Test test1 = { 1, 2, 3 };
    Test test2 = { 1, 3, 2 };

    CHECK( test1 != test2 );
}
