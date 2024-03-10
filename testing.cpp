#include <iostream>
using namespace std;

// Define enum for op codes
enum Opcode
{
    ADD = 1,
    SUB = 2,
    LOAD = 3,
    STORE = 4,
    HALT = 5
};

class ExecutionCycle
{
public:
    int pc; // Program counter
    int ac; // Accumulator
    int ir; // Instruction register
    int size = 5;
    int *memoryAddress;
    int *codeSegment;      // Instruction memory
    long int *dataSegment; // Data memory

    ExecutionCycle()
    {
        memoryAddress = new int[size];
        memoryAddress[0] = 3000, memoryAddress[1] = 3001, memoryAddress[2] = 3002, memoryAddress[3] = 3003, memoryAddress[4] = 3004;
        codeSegment = new int[size];
        codeSegment[0] = 1940, codeSegment[1] = 2940, codeSegment[2] = 5324, codeSegment[3] = 6343, codeSegment[4] = 5343;
        dataSegment = new long int[size];
        dataSegment[0] = 2, dataSegment[1] = 3, dataSegment[2] = 4, dataSegment[3] = 5, dataSegment[4] = 6;
    }

    int getOpCode(int instruction)
    {
        return instruction / 1000; // Extract the first digit as op code
    }

    void printState()
    {
        cout << "Program Counter (PC): " << pc << endl;
        cout << "Instruction Register (IR): " << ir << endl;
        cout << "Accumulator (AC): " << ac << endl;
        cout << "Memory Contents:" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "Memory Address " << memoryAddress[i] << ": " << codeSegment[i] << endl;
        }
        cout << "Data Memory Contents:" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "Data Address " << memoryAddress[i] << ": " << dataSegment[i] << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    void fetchDecodeExecute()
    {
        int i = 0;
        pc = memoryAddress[i]; // Start from the beginning of code segment
        ir = codeSegment[pc];

        while (true)
        {
            printState(); // Print state before executing each instruction

            int opCode = getOpCode(ir);
            int operand = ir % 1000; // Extract the operand (last three digits)

            switch (static_cast<Opcode>(opCode))
            {
            case ADD:
                ac += dataSegment[operand];
                break;
            case SUB:
                ac -= dataSegment[operand];
                break;
            case LOAD:
                ac = dataSegment[operand];
                break;
            case STORE:
                dataSegment[operand] = ac;
                break;
            case HALT:
                cout << "HALT instruction encountered. Exiting program." << endl;
                printState(); // Print final state before exiting
                return;

                break;
            default:
                cout << "Invalid opcode detected." << endl;
                break;
            }

            // Move to the next instruction
            i++;
            pc = memoryAddress[i];
            ir = codeSegment[pc];
        }
    }

    ~ExecutionCycle()
    {
        delete[] codeSegment;
        delete[] dataSegment;
    }
};

int main()
{
    ExecutionCycle ec;
    ec.fetchDecodeExecute();

    return 0;
}