# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\Design01.cydsn\Design01.cyprj
# Date: Sat, 14 Nov 2015 21:20:07 GMT
#set_units -time ns
create_clock -name {ADC_intClock(FFB)} -period 666.66666666666663 -waveform {0 333.333333333333} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {UART_SCBCLK(FFB)} -period 13000 -waveform {0 6500} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyRouted1} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 39 79} [list]


# Component constraints for C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\Design01.cydsn\Design01.cyprj
# Date: Sat, 14 Nov 2015 21:20:00 GMT