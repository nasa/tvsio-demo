#ifndef __PROTOBETTER_TEST_C_H__
#define __PROTOBETTER_TEST_C_H__

#include <stdio.h>
#include <stdint.h>

extern "C" {
#include "protobetter_generated.h"
}

void InitVector_cWithExpectedValues(Vector_c *v)
{
	v->id = 15;
	v->x = 1.2345;
	v->y = 97865.4321;
	v->z = 867.5309;
}

void InitVector_cWithBogusValues(Vector_c *v)
{
	v->id = 0;
	v->x = -42.0;
	v->y = -42.0;
	v->z = -42.0;
}

static void AssertVector_cEqual(Vector_c *a, Vector_c *b)
{
	ASSERT_EQ(a->id, b->id);
	ASSERT_EQ(a->x, b->x);
	ASSERT_EQ(a->y, b->y);
	ASSERT_EQ(a->z, b->z);	
}

void InitLilBity_cWithExpectedValues(LilBity_c *lilBitty)
{
	lilBitty->a = 123.123;
	lilBitty->b = 134217728;
	lilBitty->c = 1;
	lilBitty->d = 7;
	InitVector_cWithExpectedValues(&lilBitty->e[0]);
	InitVector_cWithExpectedValues(&lilBitty->e[1]);
	InitVector_cWithExpectedValues(&lilBitty->e[2]);
	lilBitty->f = 25867;
}

void InitLilBity_cWithBogusValues(LilBity_c *lilBitty)
{
	lilBitty->a = -42.0;
	lilBitty->b = 0;
	lilBitty->c = 0;
	lilBitty->d = 0;
	InitVector_cWithExpectedValues(&lilBitty->e[0]);
	InitVector_cWithExpectedValues(&lilBitty->e[1]);
	InitVector_cWithExpectedValues(&lilBitty->e[2]);
	lilBitty->f = -1;
}

void AssertLilBity_cEqual(LilBity_c *a, LilBity_c *b)
{
	ASSERT_EQ(a->a, b->a);
	ASSERT_EQ(a->b, b->b);
	ASSERT_EQ(a->c, b->c);
	ASSERT_EQ(a->d, b->d);

	for (int i = 0; i < 3; ++i)
		AssertVector_cEqual(&(a->e[i]), &(b->e[i]));

	ASSERT_EQ(a->f, b->f);
}

void AssertBittylicious_cEqual(Bittylicious_c *a, Bittylicious_c *b)
{
	ASSERT_EQ(a->a, b->a);

	for (int i = 0; i < 2; ++i)
		AssertLilBity_cEqual(&(a->b[i]), &(b->b[i]));

	for (int i = 0; i < 3; ++i)
		ASSERT_EQ(a->c[i], b->c[i]);

	AssertVector_cEqual(&(a->d), &(b->d));

	ASSERT_EQ(a->e, b->e);
}

TEST(ProtobetterTestC, NestedArraysOfComplexTypes)
{
	Bittylicious_c mystruct;
	Bittylicious_c mystruct2;

	unsigned char buffer[STRUCT_BITTYLICIOUS_C_PACKED_SIZE];

	// initialize mystruct w/ expected values and mystruct2 with bogus values
	mystruct.a = 42.123456;
	InitLilBity_cWithExpectedValues(&mystruct.b[0]);
	InitLilBity_cWithExpectedValues(&mystruct.b[1]);
	mystruct.c[0] = 12;
	mystruct.c[1] = 9;
	mystruct.c[2] = 6;
	InitVector_cWithExpectedValues(&mystruct.d);
	mystruct.e = 3;

	mystruct2.a = -1.23;
	InitLilBity_cWithBogusValues(&mystruct2.b[0]);
	InitLilBity_cWithBogusValues(&mystruct2.b[1]);
	mystruct2.c[0] = -1;
	mystruct2.c[1] = -1;
	mystruct2.c[2] = -1;
	InitVector_cWithBogusValues(&mystruct2.d);
	mystruct2.e = -1;

	PackBittylicious_c(buffer, &mystruct);
	UnpackBittylicious_c(&mystruct2, buffer);

	AssertBittylicious_cEqual(&mystruct, &mystruct2);
}

#endif /* __PROTOBETTER_TEST_C_H__ */
