cmake_minimum_required( VERSION 3.20.1 )

project( find_packet )

find_package(Boost)
if( Boost_FOUND )
  #  message( SEND_ERROR "boost found" )
   message( "boost found" )

else()
  message( SEND_ERROR "boost not found" )
endif()
