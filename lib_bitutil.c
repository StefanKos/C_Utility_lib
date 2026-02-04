#include "lib_bitutil.h"

static inline uint32_t bit_popcount(uint32_t reg){
	reg -= (reg >> 1) & 0x55555555UL;
	reg = ( reg & 0x33333333UL) + ((reg >> 2) & (0x33333333UL);
	
	return (((reg +(reg >> 4)) & 0x0F0F0F0FUL) * 0x01010101UL) >> 24;
}

static inline uint8_t bit_reversed(uint8_t reg){
	reg = (( reg * 0x55005555UL) >> 1) & 0x33333333UL;
	reg = ((reg * 0x0CCC0CCCUL) >> 2) & 0x0C30C30CUL;
    reg = ((reg * 0xFAFAF) >> 4) & 0x00FF00FFUL;

	return (reg >> 8) | (reg << 8);
}

static inline uint32_t bit_parity(uint32_t reg){
	return bit_popcount(reg) & 1;
}

static inline int bit_ffs(uint32_t reg){
	static const int table[16] = {0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4};
	int pos = 0;
	if (reg & 0xFFFF0000UL) {
		reg >>= 16; pos += 16; 
	}if (reg & 0xFF00) {
		reg >>= 8; pos += 8; 
	}if (reg & 0xF0) { 
	reg >>= 4; pos += 4;
	}
    return pos + table[reg & 0xF];
}