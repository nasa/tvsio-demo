#ifndef __PROTOBETTER_TEST_B_H__
#define __PROTOBETTER_TEST_B_H__

#include <stdio.h>
#include <stdint.h>

extern "C" {
	#include "protobetter_generated.h"
}

TEST(ProtobetterTestB, MultiByteBitfields)
{
	Bittylicious_b mystruct;
	Bittylicious_b mystruct2;

	unsigned char buffer[STRUCT_BITTYLICIOUS_B_PACKED_SIZE];

	mystruct.a = -4;
	mystruct.b = 4;
	mystruct.c = 29;
	for (int i = 0; i < 5; ++i)
		mystruct.d[i] = 14 + i;
	mystruct.e = 42.69f;
    mystruct.f = -16;
    mystruct.g = -12345.67891011;
    mystruct.h = -3200500700;

	mystruct.lilBitty.a = -987.654;
	mystruct.lilBitty.b = 10;
	mystruct.lilBitty.c = 20;
	mystruct.lilBitty.d = 30;
	mystruct.lilBitty.e = 40;
	for (int i = 0; i < 12; ++i)
		mystruct.lilBitty.f[i] = 50 + i * 2;

	mystruct2.a = 1;
	mystruct2.b = 2;
	mystruct2.c = 3;
	mystruct2.e = 1.0f;
	for (int i = 0; i < 5; ++i)
		mystruct2.d[i] = 14 + i;
    mystruct2.f = 2;
    mystruct2.g = 20.2;
    mystruct2.h = 12;

	mystruct2.lilBitty.a = 1;
	mystruct2.lilBitty.b = 2;
	mystruct2.lilBitty.c = 3;
	mystruct2.lilBitty.d = 4;
	mystruct2.lilBitty.e = 40;
	for (int i = 0; i < 12; ++i)
		mystruct2.lilBitty.f[i] = -1;


   	PackBittylicious_b(buffer, &mystruct);
	UnpackBittylicious_b(&mystruct2, buffer);
	
	ASSERT_EQ(mystruct.a, mystruct2.a);
	ASSERT_EQ(mystruct.b, mystruct2.b);
	ASSERT_EQ(mystruct.c, mystruct2.c);

	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(mystruct.d[i], mystruct2.d[i]);

	ASSERT_EQ(mystruct.e, mystruct2.e);

	ASSERT_EQ(mystruct.lilBitty.a, mystruct2.lilBitty.a);
	ASSERT_EQ(mystruct.lilBitty.b, mystruct2.lilBitty.b);
	ASSERT_EQ(mystruct.lilBitty.c, mystruct2.lilBitty.c);
	ASSERT_EQ(mystruct.lilBitty.d, mystruct2.lilBitty.d);
	ASSERT_EQ(mystruct.lilBitty.e, mystruct2.lilBitty.e);

	for (int i = 0; i < 12; ++i)
		ASSERT_EQ(mystruct.lilBitty.f[i], mystruct2.lilBitty.f[i]);
}

#endif /* __PROTOBETTER_TEST_B_H__ */