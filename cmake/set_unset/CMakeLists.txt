cmake_minimum_required( VERSION 3.20.1 )

project( set_unset )

set(HELLO vitya)

message( "hello: " ${HELLO} )

unset(HELLO)

message( "hello: " ${HELLO} )
