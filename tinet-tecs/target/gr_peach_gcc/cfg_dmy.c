#include "MBRZA1H.h"

IRQHandler _kernel_inh_table[Renesas_RZ_A1_IRQ_MAX+1];
uint32_t _kernel_excpt_nest_count = 0;

void _kernel_default_exc_handler()
{
}

void _kernel_irq_handler()
{
}

void _kernel_fiq_handler()
{
}
