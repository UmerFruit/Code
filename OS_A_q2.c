#include <stdio.h>

// Define op codes
typedef enum {
    ADD,
    SUB,
    LOAD,
    STORE,
    HALT
} OpCode;

// Define instruction structure
typedef struct {
    OpCode opCode;
    int operand1;
    int operand2;
    int result;
} Instruction;

// Memory size
#define MEMORY_SIZE 100

// Memory array to hold instructions
Instruction memory[MEMORY_SIZE];

// Function to execute an instruction
void executeInstruction(Instruction instr) {
    switch(instr.opCode) {
        case ADD:
            instr.result = instr.operand1 + instr.operand2;
            break;
        case SUB:
            instr.result = instr.operand1 - instr.operand2;
            break;
        case LOAD:
            instr.result = instr.operand1;
            break;
        case STORE:
            // Store the value of operand1 to a memory address defined by operand2
            memory[instr.operand2] = instr;
            break;
        case HALT:
            printf("Halting the program.\n");
            break;
        default:
            printf("Unknown op code.\n");
    }
}

int main() {
    // Initialize memory with sample programs
    memory[0] = (Instruction){LOAD, 5, 0, 0}; // Load value 5 into result
    memory[1] = (Instruction){STORE, 0, 10, 0}; // Store the value of result to memory address 10
    memory[2] = (Instruction){ADD, 3, 4, 0}; // Add operands 3 and 4 and store the result
    memory[3] = (Instruction){HALT, 0, 0, 0}; // Halt the program
    
    // Program counter
    int pc = 0;

    // Fetch-decode-execute cycle
    while (memory[pc].opCode != HALT) {
        // Fetch
        Instruction currentInstr = memory[pc];

        // Print the state of the computer before executing the instruction
        printf("Before executing instruction %d:\n", pc);
        printf("Memory contents:\n");
        for (int i = 0; i < MEMORY_SIZE; i++) {
            printf("Memory address %d: OpCode %d, Operand1 %d, Operand2 %d, Result %d\n", i, memory[i].opCode, memory[i].operand1, memory[i].operand2, memory[i].result);
        }
        
        // Decode and execute
        executeInstruction(currentInstr);
        printf("Executing instruction %d:\n", pc);
        printf("OpCode: %d, Operand1: %d, Operand2: %d, Result: %d\n", currentInstr.opCode, currentInstr.operand1, currentInstr.operand2, currentInstr.result);

        // Increment program counter
        pc++;

        // Print the state of the computer after executing the instruction
        printf("After executing instruction %d:\n", pc);
        printf("Memory contents:\n");
        for (int i = 0; i < MEMORY_SIZE; i++) {
            printf("Memory address %d: OpCode %d, Operand1 %d, Operand2 %d, Result %d\n", i, memory[i].opCode, memory[i].operand1, memory[i].operand2, memory[i].result);
        }
        printf("\n");
    }

    return 0;
}
