# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\myProjects\Hobby\100_day_100_projects\Mine\PSoC_Eye\PSoC_Eye.cydsn\PSoC_Eye.cyprj
# Date: Thu, 04 Jul 2013 06:16:22 GMT
#set_units -time ns
create_clock -name {I2CM_SCBCLK(FFB)} -period 166.66666666666666 -waveform {0 83.3333333333333} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {H100(FFB)} -period 16666.666666666664 -waveform {0 8333.33333333333} [list [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {CyHFCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {I2CM_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 17} [list]
create_generated_clock -name {H100} -source [get_pins {ClockBlock/hfclk}] -edges {1 801 1599} -nominal_period 16666.666666666664 [list]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]


# Component constraints for C:\myProjects\Hobby\100_day_100_projects\Mine\PSoC_Eye\PSoC_Eye.cydsn\TopDesign\TopDesign.cysch
# Project: C:\myProjects\Hobby\100_day_100_projects\Mine\PSoC_Eye\PSoC_Eye.cydsn\PSoC_Eye.cyprj
# Date: Thu, 04 Jul 2013 06:16:19 GMT
