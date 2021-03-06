#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu {
  // TODO
  // PC
  // registers (array)
  // ram (array)
  unsigned char PC;           // program counter points to next program
  unsigned char FL;           // FL bits: 00000LGE used by CMP
                              // L Less-than: during a CMP, set to 1 if registerA is less than registerB, zero otherwise.
                              // G Greater-than: during a CMP, set to 1 if registerA is greater than registerB, zero otherwise.
                              // E Equal: during a CMP, set to 1 if registerA is equal to registerB, zero otherwise.
  unsigned char registers[8]; // 8 registers  
  unsigned char ram[256];     // ram size
};

// ALU operations
enum alu_op {
  ALU_MUL,
  ALU_ADD
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI 0b10000010
// TODO: more instructions here. These can be used in cpu_run().
#define PRN  0b01000111
#define HLT  0b00000001
#define MUL  0b10100010
#define ADD  0b10100000
#define CALL 0b01010000
#define PUSH 0b01000101
#define POP  0b01000110
#define RET  0b00010001
#define ST   0b10000100
#define JMP  0b01010100
#define LD   0b10000011
#define PRA  0b01001000
#define IRET 0b00010011
#define CMP  0b10100111
#define JEQ  0b01010101
#define JNE  0b01010110

// Function declarations

#define IM 5 // R5 is reserved as the interrupt mask (IM)
#define IS 6 // R6 is reserved as the interrupt status (IS)
#define SP 7 // R7 is reserved as the stack pointer (SP)

#define EMPTY_STACK 0xEA
#define KEY_PRESSED 0xF4
#define KEYBOARD_INTERRUPT_ADDRESS 0xF9
#define NON_BREAKING_CODE 0xFF
#define CLEAR_FLAG 0x00
#define FLAG_EQUAL 0x01   // 0b00000001
#define FLAG_LESS 0x02    // 0b00000010
#define FLAG_GREATER 0x04 // 0b00000100


// extern void cpu_load(struct cpu *cpu);
extern void cpu_load(struct cpu *cpu, char *filename);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);
extern int io_bus_emulator(void);

#endif