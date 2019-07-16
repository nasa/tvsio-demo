#ifndef __PROTOBETTER_CORE_H__
#define __PROTOBETTER_CORE_H__

/*
 *  Protobetter Core - the "meat and potatoes" of the protobetter serialization library.
 *  
 *  @author - Danrae Pray
 * 
 */

#include <string.h>
#include <stdint.h>

/*
 *  Summary: this function packs bits from the 'source' bit-field into the 'destination' word
 *  
 *  Params:
 *      
 *      - destination: non-bit field target to pack bits into
 *      - source: bit-field from which the bits will be copied
 *      - bitOffset: amount by which to shift the source bits for packing
 *      - packingMask: mask used to ensure the right bits in destination are zeroed out
 */
#define PACK_BIT_FIELD(destination, source, bitOffset, packingMask)\
{\
	(destination) = ((destination) & (packingMask)) | ((source) << (bitOffset));\
}

/*
 *  Summary: this function unpacks bits from the 'source' word into the 'destination' word
 *  
 *  Params:
 *      
 *      - destination: bit field target to unpack bits into
 *      - source: non-bit field target from which the bits will be copied
 *      - bitOffset: amount by which to shift unpacked bits by before copying into destination
 *      - packingMask: mask that was used to pack the bits
 */
#define UNPACK_BIT_FIELD(destination, source, bitOffset, packingMask)\
{\
	(destination) = ((source) & ~(packingMask)) >> (bitOffset);\
}

/*
 *  Summary: macro function that packs 1 byte from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to byte buffer
 *      - source: reference to a uint8
 */
#define PACK_UINT8(destination, source)\
{\
	memcpy((destination), (source), 1);\
}

/*
 *  Summary: macro function that unpacks 1 byte from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to uint8
 *      - source: pointer to byte buffer
 */
#define UNPACK_UINT8(destination, source)\
{\
	memcpy((destination), (source), 1);\
}

/*
 *  Summary: macro function that packs a byte array from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to start of byte array
 *      - source: pointer to start of byte array
 */
#define PACK_UINT8_ARRAY(destination, source, length)\
{\
	memcpy((destination), (source), (length));\
}

/*
 *  Summary: Same as PACK_UINT8_ARRAY, but named differently for
 *              readability in generated code.
 *  
 *  Params:
 *      
 *      - destination: pointer to start of byte array
 *      - source: pointer to start of byte array
 */
#define UNPACK_UINT8_ARRAY(destination, source, length)\
{\
	memcpy((destination), (source), (length));\
}

/*
 *  Summary: macro function that packs 2 bytes from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to byte buffer
 *      - source: reference to a uint16
 */
#ifdef SOFTWARE_BIG_BIT_ORDER
#define PACK_UINT16(destination, source)\
{\
    memcpy((destination), (source), 2);\
}
#define PACK_UINT16_ARRAY(destination, source, num)\
{\
    memcpy((destination), (source), 2*(num));\
}
#else
#define PACK_UINT16(destination, source)\
{\
    uint8_t * dest = (uint8_t *)(destination);\
    uint8_t * src = (uint8_t *)(source);\
    dest[1] = src[0];\
    dest[0] = src[1];\
}
#define PACK_UINT16_ARRAY(destination, source, num)\
{\
    unsigned int ii, jj;\
    uint8_t * da = (uint8_t *)(destination);\
    uint8_t * sa = (uint8_t *)(source);\
    for(ii = 0, jj = 0; ii < (num); ++ii, jj += 2) {\
       PACK_UINT16((da)+jj, (sa)+jj);\
    }\
}
#endif

/*
 *  Summary: macro function that unpacks 2 bytes from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to uint16
 *      - source: pointer to byte buffer
 */
#define UNPACK_UINT16       PACK_UINT16
#define UNPACK_UINT16_ARRAY PACK_UINT16_ARRAY

/*
 *  Summary: macro function that packs 4 bytes from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to byte buffer
 *      - source: reference to a uint32
 */
#ifdef SOFTWARE_BIG_BIT_ORDER
#define PACK_UINT32(destination, source)\
{\
    memcpy((destination), (source), 4);\
}
#define PACK_UINT32_ARRAY(destination, source, num)\
{\
    memcpy((destination), (source), 4*(num));\
}
#else
#define PACK_UINT32(destination, source)\
{\
    uint8_t * dest = (uint8_t *)(destination);\
    uint8_t * src = (uint8_t *)(source);\
    dest[3] = src[0];\
    dest[2] = src[1];\
    dest[1] = src[2];\
    dest[0] = src[3];\
}
#define PACK_UINT32_ARRAY(destination, source, num)\
{\
    unsigned int ii, jj;\
    uint8_t * da = (uint8_t *)(destination);\
    uint8_t * sa = (uint8_t *)(source);\
    for(ii = 0, jj = 0; ii < (num); ++ii, jj += 4) {\
       PACK_UINT32((da)+jj, (sa)+jj);\
    }\
}
#endif

/*
 *  Summary: macro function that unpacks 4 bytes from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to uint32
 *      - source: pointer to byte buffer
 */
#define UNPACK_UINT32       PACK_UINT32
#define UNPACK_UINT32_ARRAY PACK_UINT32_ARRAY


/*
 *  Summary: macro function that packs 8 bytes from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to byte buffer
 *      - source: reference to a uint64
 */
#ifdef SOFTWARE_BIG_BIT_ORDER
#define PACK_UINT64(destination, source)\
{\
    memcpy((destination), (source), 8);\
}
#define PACK_UINT64_ARRAY(destination, source, num)\
{\
    memcpy((destination), (source), 8*(num));\
}
#else
#define PACK_UINT64(destination, source)\
{\
    uint8_t * dest = (uint8_t *)(destination);\
    uint8_t * src = (uint8_t *)(source);\
    dest[7] = src[0];\
    dest[6] = src[1];\
    dest[5] = src[2];\
    dest[4] = src[3];\
    dest[3] = src[4];\
    dest[2] = src[5];\
    dest[1] = src[6];\
    dest[0] = src[7];\
}
#define PACK_UINT64_ARRAY(destination, source, num)\
{\
    unsigned int ii, jj;\
    uint8_t * da = (uint8_t *)(destination);\
    uint8_t * sa = (uint8_t *)(source);\
    for(ii = 0, jj = 0; ii < (num); ++ii, jj += 8) {\
       PACK_UINT64((da)+jj, (sa)+jj);\
    }\
}
#endif

/*
 *  Summary: macro function that unpacks 8 bytes from source into destination
 *  
 *  Params:
 *      
 *      - destination: pointer to uint64
 *      - source: pointer to byte buffer
 */
#define UNPACK_UINT64       PACK_UINT64
#define UNPACK_UINT64_ARRAY PACK_UINT64_ARRAY

/*
 *  Summary: macro function that packs a float into a byte buffer
 *  
 *  Params:
 *      
 *      - destination: pointer to byte buffer
 *      - source: pointer to (char*) - must cast (float*) to (char*)
 */
#define PACK_FLOAT       PACK_UINT32
#define PACK_FLOAT_ARRAY PACK_UINT32_ARRAY

/*  Summary: macro function that unpacks a float from a byte buffer
 *  
 *  Params:
 *      
 *      - destination: pointer to (char*) - must cast (float*) to (char*)
 *      - source: pointer to byte buffer
 */
#define UNPACK_FLOAT       UNPACK_UINT32
#define UNPACK_FLOAT_ARRAY UNPACK_UINT32_ARRAY

/*
 *  Summary: macro function that packs a double into a byte buffer
 *  
 *  Params:
 *      
 *      - destination: pointer to byte buffer
 *      - source: pointer to (char*) - must cast (double*) to (char*)
 */
#define PACK_DOUBLE       PACK_UINT64
#define PACK_DOUBLE_ARRAY PACK_UINT64_ARRAY

/*  Summary: macro function that unpacks a double from a byte buffer
 *  
 *  Params:
 *      
 *      - destination: pointer to (char*) - must cast (double*) to (char*)
 *      - source: pointer to byte buffer
 */
#define UNPACK_DOUBLE       UNPACK_UINT64
#define UNPACK_DOUBLE_ARRAY UNPACK_UINT64_ARRAY

#endif // __PROTOBETTER_CORE_H__
