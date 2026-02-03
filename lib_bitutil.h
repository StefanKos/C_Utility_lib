#ifndef LIB_BITUTIL_H  /* Include guard */
#define LIB_BITUTIL_H

//Include Section
#include <stdint.h>
#include <stddef.h>

//Define Section

/* Makro Define Section */

//Single Bit
#define BIT_SET(reg,n)	( (reg) |= (1UL << (n)) )

#define BIT_CLEAR(reg,n) ( (reg) &= ~(1UL <<(n)) )

#define BIT_TOGGLE(reg, n) ( (reg) ^= (1UL << (n)) )

#define BIT_READ(reg, n) ( (reg) & (1UL << (n)) )

#define BIT_WRITE(reg, n, val) ( (val) ? BIT_SET(reg, n) : BIT_CLEAR(reg, n) )

//Multi Bits
#define BITS_SET(reg, mask) ( (reg) |= (mask) ) 

#define BITS_CLEAR(reg, mask) ( (reg) &= ~(mask) )

#define BITS_READ(reg, mask) ( (reg) & (mask) )

#define BITS_WRITE(reg, mask, val) ( (reg) = ( (reg) & ~(mask) ) | ( (val) & (mask) ) ) 

//BITFIELDS
#define EXTRACT_BITFIELD(reg, hi, lo)

#define INSERT_BITFIELD(reg, hi, lo, val)

/*Function Define Section*/

//BIT_POPCOUNT(reg)
//BIT_REVERSE8(reg)
//BIT_PARITY(reg)
//BIT_FFS(reg)

#endif // LIB_BITUTIL_H
