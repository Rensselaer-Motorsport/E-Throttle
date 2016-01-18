# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\Potentiometer-Test-BLE.cydsn\Potentiometer-Test-BLE.cyprj
# Date: Wed, 30 Dec 2015 22:26:41 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {ADC_SAR_Seq_1_intClock(FFB)} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/ff_div_6}]]
create_clock -name {UART_1_SCBCLK(FFB)} -period 8687.5 -waveform {0 4343.75} [list [get_pins {ClockBlock/ff_div_1}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFCLK} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 5 9} [list]
create_generated_clock -name {ADC_SAR_Seq_1_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 33} [list]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 417 835} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\Potentiometer-Test-BLE.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\Potentiometer-Test-BLE.cydsn\Potentiometer-Test-BLE.cyprj
# Date: Wed, 30 Dec 2015 22:26:39 GMT
