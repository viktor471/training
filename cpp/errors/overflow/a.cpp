#include <cstdint>
#include <stdio.h>
#include <thread>
#include <chrono>

int main()
{
	uint32_t uint32 = 0;
	uint8_t  uint8  = 0;

    while( uint32 != UINT32_MAX )
    {
        printf("uint32: %4d uint8: %4d ", uint32, uint8);

        for( int i = 15; i >= 0; i-- )
        {
            uint16_t i_bit = ( uint32 & (1 << i) ) ? 1 : 0;

            if( !( (i + 1) % 4 ) )
                printf(" ");

            printf("%d",  i_bit);
        }

        printf("\n");

        uint32++;
        uint8++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
