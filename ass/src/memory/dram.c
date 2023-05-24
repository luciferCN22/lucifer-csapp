#include "memory/dram.h"
#include "cpu/register.h"
#include "cpu/mmu.h"
#include<stdio.h>
#define SRAM_CACHE_SETTING 0

uint64_t read64bits_dram(uint64_t paddr)
{
    if(SRAM_CACHE_SETTING == 1){
        return;
    }

    uint64_t val =0x0;
    val += ( ((uint64_t)mm[paddr + 0]) << 0);
    val += ( ((uint64_t)mm[paddr + 1]) << 8);
    val += ( ((uint64_t)mm[paddr + 2]) << 16);
    val += ( ((uint64_t)mm[paddr + 3]) << 24);
    val += ( ((uint64_t)mm[paddr + 4]) << 32);
    val += ( ((uint64_t)mm[paddr + 5]) << 40);
    val += ( ((uint64_t)mm[paddr + 6]) << 48);
    val += ( ((uint64_t)mm[paddr + 7]) << 56);

    return val;
}


void write64bits_dram(uint64_t paddr, uint64_t data)
{
    if(SRAM_CACHE_SETTING == 1){
        return;
    }

    mm[paddr + 0]= (data >> 0) & 0xff;
    mm[paddr + 1]= (data >> 1) & 0xff;
    mm[paddr + 2]= (data >> 2) & 0xff;
    mm[paddr + 3]= (data >> 3) & 0xff;
    mm[paddr + 4]= (data >> 4) & 0xff;
    mm[paddr + 5]= (data >> 5) & 0xff;
    mm[paddr + 6]= (data >> 6) & 0xff;
    mm[paddr + 7]= (data >> 7) & 0xff;

}


void print_register(){
    printf("rax = %16lx\t rbx = %16lx\t rcx = %16lx\t rdx = %16lx\n", 
    reg.rax, reg.rbx, reg.rcx, reg.rdx);
    printf("rsi = %16lx\t rdi = %16lx\t rbp = %16lx\t rsp = %16lx\n", 
    reg.rsi, reg.rdi, reg.rbp, reg.rsp);
    printf("rip = %16lx\n",reg.rip);
}

void printf_stack(){
    int n =10;
    uint64_t *high = (uint64_t *)&mm[va2pa(reg.rsp)];
    high = &high[n];

    uint64_t rsp_start = reg.rsp +n*8;
    for (int i=0; i<2*n;++i)
    {
        uint64_t *ptr = (uint64_t*)(high-i);
        printf("0x%016lx : %16lx", rsp_start, (uint64_t)*ptr);

        if(i==n){
            printf(" <== rsp");
        }

        rsp_start = rsp_start -8;
        printf("\n");
    }
}