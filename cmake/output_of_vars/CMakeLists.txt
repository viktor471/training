cmake_minimum_required( VERSION 3.20.1 )

project( output_of_vars )

message( ${PROJECT_NAME} )

message( "project name is: ${PROJECT_NAME}" )
message( "hello" "my" friend ${PROJECT_NAME} )
message( hello;my;friend;${PROJECT_NAME} )
