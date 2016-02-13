# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\E-Throttle.cydsn\E-Throttle.cyprj
# Date: Sat, 13 Feb 2016 05:26:37 GMT
#set_units -time ns
create_clock -name {BRAKE_ADC_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {TPS_ADC_IntClock(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {APPS_ADC_IntClock(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_clock -name {BRAKE_ADC_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {BRAKE_ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 11 23} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {BRAKE_ADC_theACLK(fixed-function)} -period 458.33333333333331 -waveform {0 229.166666666667} [get_pins {ClockBlock/aclk_glb_ff_0}]
create_generated_clock -name {TPS_ADC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 15 31} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {APPS_ADC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 15 31} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 53 105} -nominal_period 2166.6666666666665 [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {timer_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 751 1501} [list [get_pins {ClockBlock/dclk_glb_4}]]
create_clock -name {timer_clock(fixed-function)} -period 31250 -waveform {0 41.6666666666667} [get_pins {ClockBlock/dclk_glb_ff_4}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\E-Throttle.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\E-Throttle.cydsn\E-Throttle.cyprj
# Date: Sat, 13 Feb 2016 05:26:03 GMT