# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\ExampleProject1\Lab Solutions\Lab 1 Blink.cydsn\Lab 1 Blink.cyprj
# Date: Sat, 14 Nov 2015 21:12:09 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]


# Component constraints for C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\ExampleProject1\Lab Solutions\Lab 1 Blink.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mitchell\Documents\fsae\E-Throttle\E-Throttle\ExampleProject1\Lab Solutions\Lab 1 Blink.cydsn\Lab 1 Blink.cyprj
# Date: Sat, 14 Nov 2015 21:12:03 GMT
