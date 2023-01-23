#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef enum
{
    INVALID,
    INCREMENT,
    DECREMENT,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    OUTPUT,
    INPUT,
    CONDITIONAL_START,
    CONDITIONAL_END
} InstructionType;

typedef struct
{
    InstructionType type;
    int repeatCount;
} Instruction;

#endif