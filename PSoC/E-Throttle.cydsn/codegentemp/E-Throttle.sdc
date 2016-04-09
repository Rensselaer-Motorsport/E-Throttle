# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\PSoC\E-Throttle.cydsn\E-Throttle.cyprj
# Date: Wed, 16 Mar 2016 20:59:37 GMT
#set_units -time ns
create_clock -name {BRAKE_ADC_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {TPS_ADC_IntClock(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {APPS_ADC_IntClock(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {BRAKE_ADC_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {TPS_ADC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 15 31} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {APPS_ADC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 15 31} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {pwm_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 25 49} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_clock -name {pwm_clock(fixed-function)} -period 1000 -waveform {0 41.6666666666667} [get_pins {ClockBlock/dclk_glb_ff_3}]
create_generated_clock -name {UART_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {BRAKE_ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 53 105} -nominal_period 2166.6666666666665 [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {BRAKE_ADC_theACLK(fixed-function)} -period 2166.6666666666665 -waveform {0 1083.33333333333} -nominal_period 2166.6666666666665 [get_pins {ClockBlock/aclk_glb_ff_0}]
create_generated_clock -name {timer_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 751 1501} [list [get_pins {ClockBlock/dclk_glb_5}]]
create_clock -name {timer_clock(fixed-function)} -period 31250 -waveform {0 41.6666666666667} [get_pins {ClockBlock/dclk_glb_ff_5}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\mitchell\Documents\fsae\E-Throttle\PSoC\E-Throttle.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\PSoC\E-Throttle.cydsn\E-Throttle.cyprj
# Date: Wed, 16 Mar 2016 20:59:07 GMT
