#include <iostream>
#include <vector>
using namespace std;
// Define enum for op codes
enum OpCode
{
    HALT,
    ADD,
    SUB,
    LOAD,
    STORE,
    AND,
    OR,
    XOR
};

struct Instruction
{
    OpCode opCode;
    int OP1;
    int OP2;
    Instruction(OpCode opCode = HALT, int operand1 = 0, int operand2 = 0) : opCode(opCode), OP1(operand1), OP2(operand2) {}
};
void printMem(vector<int> &memory, int AX)
{
    cout << "AX: " << AX << endl;
    cout << "Memory contents: " << endl;
    for (int val : memory)
    {
        cout << val << " ";
    }
    cout << endl;
}
// Function to execute an instruction
void executeInstruction(Instruction &instr, int &AX, vector<int> &memory)
{
    switch (instr.opCode)
    {
    case ADD:
        instr.OP2 == 0 ? AX += memory[instr.OP1] : AX = memory[instr.OP1] + memory[instr.OP2];
        break;

    case SUB:
        instr.OP2 == 0 ? AX -= memory[instr.OP1] : AX = memory[instr.OP1] - memory[instr.OP2];
        break;

    case AND:
        instr.OP2 == 0 ? AX &= memory[instr.OP1] : AX = memory[instr.OP1] & memory[instr.OP2];
        break;

    case OR:
        instr.OP2 == 0 ? AX |= memory[instr.OP1] : AX = memory[instr.OP1] | memory[instr.OP2];
        break;

    case XOR:
        instr.OP2 == 0 ? AX ^= memory[instr.OP1] : AX = memory[instr.OP1] ^ memory[instr.OP2];
        break;

    case LOAD:
        AX = memory[instr.OP1];
        break;

    case STORE:
        memory[instr.OP1] = AX;
        break;

    case HALT:
        cout << endl;
        cout << "Halting program." << endl;
        cout << "Final memory state: " << endl;
        printMem(memory, AX);
        exit(0);
    default:
        cout << "Invalid instruction." << endl;
    }
}
void sample1()
{
    vector<int> memory = {LOAD, 9, 0,   // Load value from memory address 9
                          SUB, 10, 0,   // Add value from memory address 10 to register
                          STORE, 11, 0, // Store result in memory address 7
                          25, 10, 0,    // values for the instruction
                          HALT};        // Halt program

    int AX = 0;
    int PC = 0;

    while (true)
    {
        // Fetching the instruction into my structure
        Instruction curr_instr(static_cast<OpCode>(memory[PC]), memory[PC + 1], memory[PC + 2]);

        cout << "Before execution:" << endl;
        printMem(memory, AX);

        // Decode and execute steps
        executeInstruction(curr_instr, AX, memory);

        cout << "After execution:" << endl;
        printMem(memory, AX);

        // Increment program counter
        PC += 3;
        cout << endl;
    }
}
void sample2()
{
    vector<int> memory = {LOAD, 9, 0,   // Load value from memory address 9
                          XOR, 10, 0,   // XOR value from memory address 10 with register
                          STORE, 11, 0, // Store result in memory address 7
                          25, 10, 0,    // values for the instruction
                          HALT};        // Halt program

    int AX = 0;
    int PC = 0;

    while (true)
    {
        // Fetching the instruction into my structure
        Instruction curr_instr(static_cast<OpCode>(memory[PC]), memory[PC + 1], memory[PC + 2]);

        cout << "Before execution:" << endl;
        printMem(memory, AX);

        // Decode and execute steps
        executeInstruction(curr_instr, AX, memory);

        cout << "After execution:" << endl;
        printMem(memory, AX);

        // Increment program counter
        PC += 3;
        cout << endl;
    }
}
int main()
{
    // sample1();
    sample2();
    return 0;
}
