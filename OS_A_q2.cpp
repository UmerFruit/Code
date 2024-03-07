#include <iostream>
#include <vector>
using namespace std;
// Define op codes
enum class OpCode {
    ADD,
    SUB,
    LOAD,
    STORE,
    HALT
};

// Define instruction structure
struct Instruction {
    OpCode opCode;
    int operand1;
    int operand2;
    int result;
};

// Memory size
constexpr int MEMORY_SIZE = 100;

// Memory vector to hold instructions
std::vector<Instruction> memory(MEMORY_SIZE);

// Function to execute an instruction
void executeInstruction(Instruction& instr) {
    switch(instr.opCode) {
        case OpCode::ADD:
            instr.result = instr.operand1 + instr.operand2;
            break;
        case OpCode::SUB:
            instr.result = instr.operand1 - instr.operand2;
            break;
        case OpCode::LOAD:
            instr.result = instr.operand1;
            break;
        case OpCode::STORE:
            // Store the value of operand1 to a memory address defined by operand2
            memory[instr.operand2] = instr;
            break;
        case OpCode::HALT:
            std::cout << "Halting the program." << std::endl;
            break;
        default:
            std::cout << "Unknown op code." << std::endl;
    }
}

int main() {
    // Initialize memory with sample programs
    memory[0] = {OpCode::LOAD, 5, 0, 0}; // Load value 5 into result
    memory[1] = {OpCode::STORE, 0, 10, 0}; // Store the value of result to memory address 10
    memory[2] = {OpCode::ADD, 3, 4, 0}; // Add operands 3 and 4 and store the result
    memory[3] = {OpCode::HALT, 0, 0, 0}; // Halt the program
    
    // Program counter
    int pc = 0;

    // Fetch-decode-execute cycle
    while (memory[pc].opCode != OpCode::HALT) {
        // Fetch
        Instruction currentInstr = memory[pc];

        // Print the state of the computer before executing the instruction
        std::cout << "Before executing instruction " << pc << ":" << std::endl;
        std::cout << "Memory contents:" << std::endl;
        for (int i = 0; i < MEMORY_SIZE; i++) {
            std::cout << "Memory address " << i << ": OpCode " << static_cast<int>(memory[i].opCode) << ", Operand1 " << memory[i].operand1 << ", Operand2 " << memory[i].operand2 << ", Result " << memory[i].result << std::endl;
        }
        
        // Decode and execute
        executeInstruction(currentInstr);
        std::cout << "Executing instruction " << pc << ":" << std::endl;
        std::cout << "OpCode: " << static_cast<int>(currentInstr.opCode) << ", Operand1: " << currentInstr.operand1 << ", Operand2: " << currentInstr.operand2 << ", Result: " << currentInstr.result << std::endl;

        // Increment program counter
        pc++;

        // Print the state of the computer after executing the instruction
        std::cout << "After executing instruction " << pc << ":" << std::endl;
        std::cout << "Memory contents:" << std::endl;
        for (int i = 0; i < MEMORY_SIZE; i++) {
            std::cout << "Memory address " << i << ": OpCode " << static_cast<int>(memory[i].opCode) << ", Operand1 " << memory[i].operand1 << ", Operand2 " << memory[i].operand2 << ", Result " << memory[i].result << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
