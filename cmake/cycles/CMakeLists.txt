cmake_minimum_required( VERSION 3.20.1 )

project( cycles )

set( VAR 0 )
while( NOT ${VAR} EQUAL 10 )
  MATH(EXPR VAR "${VAR} + 1")
  message("var: " ${VAR} )
endwhile()
