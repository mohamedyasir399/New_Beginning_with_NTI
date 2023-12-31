#ifndef BIT_MANIPULATION_H_INCLUDED
#define BIT_MANIPULATION_H_INCLUDED

#define SET_BIT(REG,BIT_NUMBER)         REG |= (1<<BIT_NUMBER)
#define CLEAR_BIT(REG,BIT_NUMBER)       REG &= ~(1<<BIT_NUMBER)
#define TOGGLE_BIT(REG,BIT_NUMBER)      REG ^= (1<<BIT_NUMBER)
#define SHIFT_RIGHT(REG,BIT_NUMBER)     REG  = (REG>>BIT_NUMBER)
#define SHIFT_LEFT(REG,BIT_NUMBER)      REG  = (REG<<BIT_NUMBER)

#endif // BIT_MANIPULATION_H_INCLUDED
