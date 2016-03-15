// ======================================================================
// PSoC_Eye.v generated from TopDesign.cysch
// 07/04/2013 at 11:46
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC4A 2
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PANTHER 3
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 17
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4A 2
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_5B 4
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_FAMILY_USED 2
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 17
// TCPWM_P4_v1_0(PWMCompare=0, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=600, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=0, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=0, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=0, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=false, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=false, TCCaptureMode=0, TCCapturePresent=false, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=3, TCCountPresent=false, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=false, TCRunMode=0, TCStartMode=0, TCStartPresent=false, TCStopMode=0, TCStopPresent=false, CY_COMPONENT_NAME=TCPWM_P4_v1_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PAN, CY_INSTANCE_SHORT_NAME=PAN, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PAN, )
module TCPWM_P4_v1_0_0 (
    stop,
    count,
    reload,
    start,
    capture,
    interrupt,
    ov,
    un,
    cc,
    clock,
    line,
    line_n);
    input       stop;
    input       count;
    input       reload;
    input       start;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    input       clock;
    output      line;
    output      line_n;

    parameter PWMCountMode = 3;
    parameter PWMReloadMode = 0;
    parameter PWMReloadPresent = 0;
    parameter PWMStartMode = 0;
    parameter PWMStopMode = 0;
    parameter PWMSwitchMode = 0;
    parameter QuadIndexMode = 0;
    parameter QuadPhiAMode = 3;
    parameter QuadPhiBMode = 3;
    parameter QuadStopMode = 0;
    parameter TCCaptureMode = 0;
    parameter TCCountMode = 3;
    parameter TCReloadMode = 0;
    parameter TCStartMode = 0;
    parameter TCStopMode = 0;


    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(capture),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(count),
        .reload(reload),
        .stop(stop),
        .start(start),
        .clock(clock));



endmodule

// TCPWM_P4_v1_0(PWMCompare=0, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=600, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=0, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=0, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=0, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=false, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=false, TCCaptureMode=0, TCCapturePresent=false, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=3, TCCountPresent=false, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=false, TCRunMode=0, TCStartMode=0, TCStartPresent=false, TCStopMode=0, TCStopPresent=false, CY_COMPONENT_NAME=TCPWM_P4_v1_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=TILT, CY_INSTANCE_SHORT_NAME=TILT, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=TILT, )
module TCPWM_P4_v1_0_1 (
    stop,
    count,
    reload,
    start,
    capture,
    interrupt,
    ov,
    un,
    cc,
    clock,
    line,
    line_n);
    input       stop;
    input       count;
    input       reload;
    input       start;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    input       clock;
    output      line;
    output      line_n;

    parameter PWMCountMode = 3;
    parameter PWMReloadMode = 0;
    parameter PWMReloadPresent = 0;
    parameter PWMStartMode = 0;
    parameter PWMStopMode = 0;
    parameter PWMSwitchMode = 0;
    parameter QuadIndexMode = 0;
    parameter QuadPhiAMode = 3;
    parameter QuadPhiBMode = 3;
    parameter QuadStopMode = 0;
    parameter TCCaptureMode = 0;
    parameter TCCountMode = 3;
    parameter TCReloadMode = 0;
    parameter TCStartMode = 0;
    parameter TCStopMode = 0;


    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(capture),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(count),
        .reload(reload),
        .stop(stop),
        .start(start),
        .clock(clock));



endmodule

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// SCB_P4_v1_0(BitWidthReplacementStringRx=uint8, BitWidthReplacementStringTx=uint8, Cond=#, EndCond=#endif, I2cAcceptAddress=false, I2cClkFreqDes=6400, I2cClockFromTerm=false, I2cDataRate=400, I2cIsSlaveAddressHex=true, I2cIsSlaveAddressMaskHex=true, I2cMedianFilterEnable=true, I2cMode=2, I2cOvsFactor=16, I2cOvsFactorHigh=8, I2cOvsFactorLow=8, I2cSlaveAddress=8, I2cSlaveAddressMask=254, I2cWakeEnable=false, RemoveI2cPins=false, RemoveMisoSdaTx=true, RemoveMosiSclRx=true, RemoveMosiSclRxWake=true, RemoveScbClk=false, RemoveScbIrq=false, RemoveSpiMasterPins=true, RemoveSpiMasterSs0Pin=true, RemoveSpiMasterSs1Pin=true, RemoveSpiMasterSs2Pin=true, RemoveSpiMasterSs3Pin=true, RemoveSpiSclk=true, RemoveSpiSlavePins=true, RemoveSpiSs0=true, RemoveSpiSs1=true, RemoveSpiSs2=true, RemoveSpiSs3=true, RemoveUartRxPin=true, RemoveUartRxTxPin=true, RemoveUartRxWake=true, RemoveUartRxWakeupIrq=true, RemoveUartTxPin=true, ScbClkFreqDes=6400, ScbClockSelect=1, ScbClockTermEnable=false, ScbInterruptTermEnable=false, ScbMisoSdaTxEnable=true, ScbMode=1, ScbModeHw=0, ScbMosiSclRxEnable=true, ScbRxWakeIrqEnable=false, ScbSclkEnable=false, ScbSs0Enable=false, ScbSs1Enable=false, ScbSs2Enable=false, ScbSs3Enable=false, SpiBitRate=1000, SpiBitsOrder=1, SpiClkFreqDes=16000, SpiClockFromTerm=false, SpiInterruptMode=1, SpiIntrMasterSpiDone=false, SpiIntrRxFull=false, SpiIntrRxNotEmpty=false, SpiIntrRxOverflow=false, SpiIntrRxTrigger=false, SpiIntrRxUnderflow=false, SpiIntrSlaveBusError=false, SpiIntrTxEmpty=false, SpiIntrTxNotFull=false, SpiIntrTxOverflow=false, SpiIntrTxTrigger=false, SpiIntrTxUnderflow=false, SpiLateMisoSampleEnable=false, SpiMedianFilterEnable=false, SpiMode=0, SpiNumberOfRxDataBits=8, SpiNumberOfSelectLines=1, SpiNumberOfTxDataBits=8, SpiOvsFactor=16, SpiRxBufferSize=8, SpiRxIntrMask=0, SpiRxTriggerLevel=7, SpiSclkMode=0, SpiSubMode=0, SpiTransferSeparation=1, SpiTxBufferSize=8, SpiTxIntrMask=0, SpiTxTriggerLevel=0, SpiWakeEnable=false, UartClkFreqDes=1382.4, UartClockFromTerm=false, UartDataRate=115200, UartDirection=3, UartDropOnFrameErr=false, UartDropOnParityErr=false, UartInterruptMode=0, UartIntrRxFrameErr=false, UartIntrRxFull=false, UartIntrRxNotEmpty=true, UartIntrRxOverflow=false, UartIntrRxParityErr=false, UartIntrRxTrigger=false, UartIntrRxUnderflow=false, UartIntrTxEmpty=false, UartIntrTxNotFull=false, UartIntrTxOverflow=false, UartIntrTxTrigger=false, UartIntrTxUartDone=false, UartIntrTxUartLostArb=false, UartIntrTxUartNack=false, UartIntrTxUnderflow=false, UartIrdaLowPower=false, UartIrdaPolarity=0, UartMedianFilterEnable=false, UartMpEnable=false, UartMpRxAcceptAddress=false, UartMpRxAddress=2, UartMpRxAddressMask=255, UartNumberOfDataBits=8, UartNumberOfStopBits=2, UartOvsFactor=12, UartParityType=2, UartRxBufferSize=8, UartRxEnable=true, UartRxIntrMask=4, UartRxTriggerLevel=7, UartSmCardRetryOnNack=false, UartSubMode=0, UartTxBufferSize=8, UartTxEnable=true, UartTxIntrMask=0, UartTxTriggerLevel=0, UartWakeEnable=false, CY_COMPONENT_NAME=SCB_P4_v1_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=I2CM, CY_INSTANCE_SHORT_NAME=I2CM, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=I2CM, )
module SCB_P4_v1_0_2 (
    sclk,
    interrupt,
    clock);
    output      sclk;
    output      interrupt;
    input       clock;


          wire [3:0] ss;
          wire  Net_88;
          wire  Net_84;
          wire  Net_149;
          wire  Net_150;
          wire  Net_152;
          wire  Net_453;
          wire  uncfg_rx_irq;
          wire  Net_427;
          wire  Net_436;
          wire  Net_449;
          wire  Net_433;
          wire  Net_373;
          wire  Net_452;
          wire  Net_459;
          wire  Net_458;
          wire  Net_430;
          wire  Net_237;
          wire  Net_413;
          wire  Net_244;
          wire  Net_422;
          wire  rx_irq;
          wire  Net_379;
          wire  Net_409;
          wire  Net_246;
          wire  Net_252;
          wire  Net_245;
          wire  Net_243;
          wire  Net_89;
          wire  Net_284;
          wire  Net_416;
          wire  Net_387;
          wire  Net_151;
          wire  Net_410;

    cy_m0s8_scb_v1_0 SCB (
        .rx(Net_244),
        .miso_m(Net_410),
        .clock(Net_237),
        .select_m(ss[3:0]),
        .sclk_m(Net_88),
        .mosi_s(Net_89),
        .select_s(Net_430),
        .sclk_s(Net_413),
        .mosi_m(Net_84),
        .scl(Net_149),
        .sda(Net_150),
        .tx(Net_151),
        .miso_s(Net_152),
        .interrupt(interrupt));
    defparam SCB.scb_mode = 0;


	cy_isr_v1_0
		#(.int_type(2'b10))
		SCB_IRQ
		 (.int_signal(interrupt));



	cy_clock_v1_0
		#(.id("1ec6effd-8f31-4dd5-a825-0c49238d524e/29084e80-7594-46a9-94af-639e276dfc5f"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("156250000"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_284));



    assign sclk = Net_284 | Net_427;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_427));

	wire [0:0] tmpOE__scl_net;
	wire [0:0] tmpFB_0__scl_net;
	wire [0:0] tmpINTERRUPT_0__scl_net;
	electrical [0:0] tmpSIOVREF__scl_net;

	cy_psoc3_pins_v1_10
		#(.id("1ec6effd-8f31-4dd5-a825-0c49238d524e/22863ebe-a37b-476f-b252-6e49a8c00b12"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		scl
		 (.oe(tmpOE__scl_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__scl_net[0:0]}),
		  .io({Net_149}),
		  .siovref(tmpSIOVREF__scl_net),
		  .interrupt({tmpINTERRUPT_0__scl_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__scl_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__sda_net;
	wire [0:0] tmpFB_0__sda_net;
	wire [0:0] tmpINTERRUPT_0__sda_net;
	electrical [0:0] tmpSIOVREF__sda_net;

	cy_psoc3_pins_v1_10
		#(.id("1ec6effd-8f31-4dd5-a825-0c49238d524e/5382e105-1382-4a2e-b9f4-3bb2feba71e0"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		sda
		 (.oe(tmpOE__sda_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__sda_net[0:0]}),
		  .io({Net_150}),
		  .siovref(tmpSIOVREF__sda_net),
		  .interrupt({tmpINTERRUPT_0__sda_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__sda_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	// miso_m_VM (cy_virtualmux_v1_0)
	assign Net_410 = Net_436;

	// mosi_s_VM (cy_virtualmux_v1_0)
	assign Net_89 = Net_449;

	// sclk_s_VM (cy_virtualmux_v1_0)
	assign Net_413 = Net_433;

	// clock_VM (cy_virtualmux_v1_0)
	assign Net_237 = Net_284;

	// rx_wake_VM (cy_virtualmux_v1_0)
	assign Net_373 = uncfg_rx_irq;

	// rx_VM (cy_virtualmux_v1_0)
	assign Net_244 = Net_452;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_433));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_436));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_449));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_452));

	// select_s_VM (cy_virtualmux_v1_0)
	assign Net_430 = Net_459;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_459));



endmodule

// Component: cy_tff_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_tff_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_tff_v1_0\cy_tff_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_tff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_tff_v1_0\cy_tff_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// PSoC_4_Pioneer_Kit(ShowPins=true, CY_COMPONENT_NAME=PSoC_4_Pioneer_Kit, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PSoC_4_Pioneer_Kit, CY_INSTANCE_SHORT_NAME=PSoC_4_Pioneer_Kit, CY_MAJOR_VERSION=0, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PSoC_4_Pioneer_Kit, )
module PSoC_4_Pioneer_Kit_3 (
    Terminal_1,
    Terminal_2,
    Terminal_3,
    Terminal_4,
    Terminal_5,
    Terminal_6,
    Terminal_7,
    Terminal_8,
    Terminal_9,
    Terminal_10,
    Terminal_11,
    Terminal_12,
    Terminal_13,
    Terminal_14,
    Terminal_15,
    Terminal_16,
    Terminal_17,
    Terminal_18,
    Terminal_19,
    Terminal_20,
    Terminal_21,
    Terminal_22,
    Terminal_23,
    Terminal_24,
    Terminal_25,
    Terminal_26,
    Terminal_27,
    Terminal_28,
    Terminal_29,
    Terminal_30,
    Terminal_31,
    Terminal_32,
    Terminal_33,
    Terminal_34,
    Terminal_35,
    Terminal_36,
    Terminal_37,
    Terminal_38,
    Terminal_39,
    Terminal_40,
    Terminal_41,
    Terminal_42,
    Terminal_43,
    Terminal_44,
    Terminal_45,
    Terminal_46,
    Terminal_47,
    Terminal_48,
    Terminal_49,
    Terminal_50,
    Terminal_51,
    Terminal_52,
    Terminal_53,
    Terminal_54,
    Terminal_55,
    Terminal_56,
    Terminal_57,
    Terminal_58,
    Terminal_59,
    Terminal_60,
    Terminal_61,
    Terminal_62,
    Terminal_63,
    Terminal_64,
    Terminal_65,
    Terminal_66,
    Terminal_67,
    Terminal_68);
    inout       Terminal_1;
    electrical  Terminal_1;
    inout       Terminal_2;
    electrical  Terminal_2;
    inout       Terminal_3;
    electrical  Terminal_3;
    inout       Terminal_4;
    electrical  Terminal_4;
    inout       Terminal_5;
    electrical  Terminal_5;
    inout       Terminal_6;
    electrical  Terminal_6;
    inout       Terminal_7;
    electrical  Terminal_7;
    inout       Terminal_8;
    electrical  Terminal_8;
    inout       Terminal_9;
    electrical  Terminal_9;
    inout       Terminal_10;
    electrical  Terminal_10;
    inout       Terminal_11;
    electrical  Terminal_11;
    inout       Terminal_12;
    electrical  Terminal_12;
    inout       Terminal_13;
    electrical  Terminal_13;
    inout       Terminal_14;
    electrical  Terminal_14;
    inout       Terminal_15;
    electrical  Terminal_15;
    inout       Terminal_16;
    electrical  Terminal_16;
    inout       Terminal_17;
    electrical  Terminal_17;
    inout       Terminal_18;
    electrical  Terminal_18;
    inout       Terminal_19;
    electrical  Terminal_19;
    inout       Terminal_20;
    electrical  Terminal_20;
    inout       Terminal_21;
    electrical  Terminal_21;
    inout       Terminal_22;
    electrical  Terminal_22;
    inout       Terminal_23;
    electrical  Terminal_23;
    inout       Terminal_24;
    electrical  Terminal_24;
    inout       Terminal_25;
    electrical  Terminal_25;
    inout       Terminal_26;
    electrical  Terminal_26;
    inout       Terminal_27;
    electrical  Terminal_27;
    inout       Terminal_28;
    electrical  Terminal_28;
    inout       Terminal_29;
    electrical  Terminal_29;
    inout       Terminal_30;
    electrical  Terminal_30;
    inout       Terminal_31;
    electrical  Terminal_31;
    inout       Terminal_32;
    electrical  Terminal_32;
    inout       Terminal_33;
    electrical  Terminal_33;
    inout       Terminal_34;
    electrical  Terminal_34;
    inout       Terminal_35;
    electrical  Terminal_35;
    inout       Terminal_36;
    electrical  Terminal_36;
    inout       Terminal_37;
    electrical  Terminal_37;
    inout       Terminal_38;
    electrical  Terminal_38;
    inout       Terminal_39;
    electrical  Terminal_39;
    inout       Terminal_40;
    electrical  Terminal_40;
    inout       Terminal_41;
    electrical  Terminal_41;
    inout       Terminal_42;
    electrical  Terminal_42;
    inout       Terminal_43;
    electrical  Terminal_43;
    inout       Terminal_44;
    electrical  Terminal_44;
    inout       Terminal_45;
    electrical  Terminal_45;
    inout       Terminal_46;
    electrical  Terminal_46;
    inout       Terminal_47;
    electrical  Terminal_47;
    inout       Terminal_48;
    electrical  Terminal_48;
    inout       Terminal_49;
    electrical  Terminal_49;
    inout       Terminal_50;
    electrical  Terminal_50;
    inout       Terminal_51;
    electrical  Terminal_51;
    inout       Terminal_52;
    electrical  Terminal_52;
    inout       Terminal_53;
    electrical  Terminal_53;
    inout       Terminal_54;
    electrical  Terminal_54;
    inout       Terminal_55;
    electrical  Terminal_55;
    inout       Terminal_56;
    electrical  Terminal_56;
    inout       Terminal_57;
    electrical  Terminal_57;
    inout       Terminal_58;
    electrical  Terminal_58;
    inout       Terminal_59;
    electrical  Terminal_59;
    inout       Terminal_60;
    electrical  Terminal_60;
    inout       Terminal_61;
    electrical  Terminal_61;
    inout       Terminal_62;
    electrical  Terminal_62;
    inout       Terminal_63;
    electrical  Terminal_63;
    inout       Terminal_64;
    electrical  Terminal_64;
    inout       Terminal_65;
    electrical  Terminal_65;
    inout       Terminal_66;
    electrical  Terminal_66;
    inout       Terminal_67;
    electrical  Terminal_67;
    inout       Terminal_68;
    electrical  Terminal_68;





endmodule

// top
module top ;

    electrical  Net_272;
    electrical  Net_271;
    electrical  Net_270;
    electrical  Net_269;
    electrical  Net_268;
    electrical  Net_267;
    electrical  Net_266;
    electrical  Net_265;
    electrical  Net_264;
    electrical  Net_263;
    electrical  Net_262;
    electrical  Net_261;
    electrical  Net_256;
    electrical  Net_232;
    electrical  Net_231;
    electrical  Net_230;
    electrical  Net_229;
    electrical  Net_228;
    electrical  Net_227;
    electrical  Net_226;
    electrical  Net_225;
    electrical  Net_224;
    electrical  Net_223;
    electrical  Net_222;
    electrical  Net_221;
    electrical  Net_220;
    electrical  Net_219;
    electrical  Net_218;
    electrical  Net_217;
    electrical  Net_216;
    electrical  Net_213;
    electrical  Net_212;
    electrical  Net_211;
    electrical  Net_210;
    electrical  Net_209;
    electrical  Net_208;
    electrical  Net_207;
    electrical  Net_206;
    electrical  Net_205;
    electrical  Net_204;
    electrical  Net_203;
    electrical  Net_202;
    electrical  Net_201;
    electrical  Net_200;
    electrical  Net_199;
    electrical  Net_198;
    electrical  Net_197;
    electrical  Net_153;
    electrical  Net_152;
    electrical  Net_151;
    electrical  Net_150;
    electrical  Net_149;
    electrical  Net_148;
    electrical  Net_147;
    electrical  Net_146;
    electrical  Net_145;
    electrical  Net_144;
    electrical  Net_143;
    electrical  Net_142;
    electrical  Net_141;
    electrical  Net_140;
    electrical  Net_139;
    electrical  Net_138;
    electrical  Net_137;
    electrical  Net_136;
    electrical  Net_135;
    electrical  Net_134;
    electrical  Net_133;
    electrical  Net_132;
    electrical  Net_131;
    electrical  Net_130;
    electrical  Net_129;
    electrical  Net_128;
    electrical  Net_127;
    electrical  Net_126;
    electrical  Net_125;
    electrical  Net_124;
    electrical  Net_123;
    electrical  Net_122;
    electrical  Net_121;
    electrical  Net_120;
    electrical  Net_119;
    electrical  Net_118;
    electrical  Net_117;
    electrical  Net_116;
    electrical  Net_115;
    electrical  Net_114;
    electrical  Net_113;
    electrical  Net_112;
    electrical  Net_111;
    electrical  Net_110;
    electrical  Net_109;
    electrical  Net_108;
    electrical  Net_107;
    electrical  Net_106;
    electrical  Net_105;
    electrical  Net_104;
    electrical  Net_103;
    electrical  P2_4;
    electrical  Net_102;
    electrical  Net_101;
    electrical  Net_100;
    electrical  Net_99;
    electrical  Net_98;
    electrical  Net_97;
    electrical  Net_96;
    electrical  Net_95;
    electrical  Net_94;
    electrical  Net_93;
    electrical  Net_92;
    electrical  Net_91;
    electrical  Net_90;
    electrical  Net_89;
          wire  Net_88;
          wire  Net_82;
          wire  Net_81;
          wire  Net_80;
          wire  Net_78;
          wire  Net_77;
          wire  Net_76;
          wire  Net_72;
          wire  Net_59;
          wire  Net_58;
          wire  Net_57;
          wire  Net_56;
          wire  Net_55;
          wire  Net_54;
          wire  Net_53;
          wire  Net_52;
          wire  Net_51;
          wire  Net_50;
          wire  Net_49;
          wire  Net_35;
          wire  Net_34;
          wire  Net_33;
          wire  Net_32;
          wire  Net_31;
    electrical  P1_0;
          wire  Net_30;
          wire  Net_29;
          wire  Net_28;
          wire  Net_27;
          wire  Net_26;
          wire  Net_25;
    electrical  Net_284;
    electrical  Net_283;
    electrical  Net_214;
    electrical  Net_215;
    electrical  Net_195;
    electrical  Net_194;
    electrical  Net_729;
    electrical  Net_728;
          wire  Net_60;
    electrical  P3_0;
    electrical  P2_7;
    electrical  P3_1;
    electrical  P1_3;

    TCPWM_P4_v1_0_0 PAN (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_30),
        .ov(Net_31),
        .un(Net_32),
        .cc(Net_33),
        .line(Net_34),
        .line_n(Net_35),
        .clock(Net_60));
    defparam PAN.PWMCountMode = 3;
    defparam PAN.PWMReloadMode = 0;
    defparam PAN.PWMReloadPresent = 0;
    defparam PAN.PWMStartMode = 0;
    defparam PAN.PWMStopMode = 0;
    defparam PAN.PWMSwitchMode = 0;
    defparam PAN.QuadIndexMode = 0;
    defparam PAN.QuadPhiAMode = 3;
    defparam PAN.QuadPhiBMode = 3;
    defparam PAN.QuadStopMode = 0;
    defparam PAN.TCCaptureMode = 0;
    defparam PAN.TCCountMode = 3;
    defparam PAN.TCReloadMode = 0;
    defparam PAN.TCStartMode = 0;
    defparam PAN.TCStopMode = 0;

    TCPWM_P4_v1_0_1 TILT (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_54),
        .ov(Net_55),
        .un(Net_56),
        .cc(Net_57),
        .line(Net_58),
        .line_n(Net_59),
        .clock(Net_60));
    defparam TILT.PWMCountMode = 3;
    defparam TILT.PWMReloadMode = 0;
    defparam TILT.PWMReloadPresent = 0;
    defparam TILT.PWMStartMode = 0;
    defparam TILT.PWMStopMode = 0;
    defparam TILT.PWMSwitchMode = 0;
    defparam TILT.QuadIndexMode = 0;
    defparam TILT.QuadPhiAMode = 3;
    defparam TILT.QuadPhiBMode = 3;
    defparam TILT.QuadStopMode = 0;
    defparam TILT.TCCaptureMode = 0;
    defparam TILT.TCCountMode = 3;
    defparam TILT.TCReloadMode = 0;
    defparam TILT.TCStartMode = 0;
    defparam TILT.TCStopMode = 0;


	cy_clock_v1_0
		#(.id("5355e027-4959-4c81-86c5-1ce67311ef91"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("16666666666.6667"),
		  .is_direct(0),
		  .is_digital(0))
		H100
		 (.clock_out(Net_60));


	wire [0:0] tmpOE__PAN_O_net;
	wire [0:0] tmpFB_0__PAN_O_net;
	wire [0:0] tmpIO_0__PAN_O_net;
	wire [0:0] tmpINTERRUPT_0__PAN_O_net;
	electrical [0:0] tmpSIOVREF__PAN_O_net;

	cy_psoc3_pins_v1_10
		#(.id("52f31aa9-2f0a-497d-9a1f-1424095e13e6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PAN_O
		 (.oe(tmpOE__PAN_O_net),
		  .y({Net_34}),
		  .fb({tmpFB_0__PAN_O_net[0:0]}),
		  .io({tmpIO_0__PAN_O_net[0:0]}),
		  .siovref(tmpSIOVREF__PAN_O_net),
		  .interrupt({tmpINTERRUPT_0__PAN_O_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PAN_O_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__TILT_O_net;
	wire [0:0] tmpFB_0__TILT_O_net;
	wire [0:0] tmpIO_0__TILT_O_net;
	wire [0:0] tmpINTERRUPT_0__TILT_O_net;
	electrical [0:0] tmpSIOVREF__TILT_O_net;

	cy_psoc3_pins_v1_10
		#(.id("785a7a8e-3597-4d83-8242-d4fb25745323"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		TILT_O
		 (.oe(tmpOE__TILT_O_net),
		  .y({Net_58}),
		  .fb({tmpFB_0__TILT_O_net[0:0]}),
		  .io({tmpIO_0__TILT_O_net[0:0]}),
		  .siovref(tmpSIOVREF__TILT_O_net),
		  .interrupt({tmpINTERRUPT_0__TILT_O_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TILT_O_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SCB_P4_v1_0_2 I2CM (
        .sclk(Net_76),
        .interrupt(Net_77),
        .clock(1'b0));

	wire [0:0] tmpOE__RESET_net;
	wire [0:0] tmpFB_0__RESET_net;
	wire [0:0] tmpIO_0__RESET_net;
	wire [0:0] tmpINTERRUPT_0__RESET_net;
	electrical [0:0] tmpSIOVREF__RESET_net;

	cy_psoc3_pins_v1_10
		#(.id("ede4d5ed-3c39-4d18-a992-1336008d1b17"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		RESET
		 (.oe(tmpOE__RESET_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__RESET_net[0:0]}),
		  .io({tmpIO_0__RESET_net[0:0]}),
		  .siovref(tmpSIOVREF__RESET_net),
		  .interrupt({tmpINTERRUPT_0__RESET_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RESET_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- TFF Start --
    reg  cy_tff_1;
    always @(posedge Net_81)
    begin
        cy_tff_1 <= Net_80^Net_82;
    end
    assign Net_82 = cy_tff_1;
    // -- TFF End --

    assign Net_80 = 1'h1;

	wire [0:0] tmpOE__CLOCK_net;
	wire [0:0] tmpFB_0__CLOCK_net;
	wire [0:0] tmpIO_0__CLOCK_net;
	wire [0:0] tmpINTERRUPT_0__CLOCK_net;
	electrical [0:0] tmpSIOVREF__CLOCK_net;

	cy_psoc3_pins_v1_10
		#(.id("8e73ab69-db97-45dd-9f35-8fed3817374c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		CLOCK
		 (.oe(tmpOE__CLOCK_net),
		  .y({Net_82}),
		  .fb({tmpFB_0__CLOCK_net[0:0]}),
		  .io({tmpIO_0__CLOCK_net[0:0]}),
		  .siovref(tmpSIOVREF__CLOCK_net),
		  .interrupt({tmpINTERRUPT_0__CLOCK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CLOCK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("30d64708-18a7-40bb-adb2-833d1dcf7229"),
		  .source_clock_id("413DE2EF-D9F2-4233-A808-DFAF137FD877"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(0))
		HFCLK_Freq
		 (.clock_out(Net_81));


    PSoC_4_Pioneer_Kit_3 PSoC_4_Pioneer_Kit (
        .Terminal_20(Net_89),
        .Terminal_21(Net_729),
        .Terminal_22(Net_729),
        .Terminal_23(Net_90),
        .Terminal_24(Net_728),
        .Terminal_25(Net_91),
        .Terminal_26(Net_92),
        .Terminal_27(Net_93),
        .Terminal_18(Net_94),
        .Terminal_34(Net_95),
        .Terminal_35(Net_96),
        .Terminal_36(Net_97),
        .Terminal_37(Net_98),
        .Terminal_38(Net_99),
        .Terminal_39(Net_100),
        .Terminal_40(Net_101),
        .Terminal_41(Net_102),
        .Terminal_42(Net_103),
        .Terminal_43(Net_104),
        .Terminal_44(Net_105),
        .Terminal_45(Net_106),
        .Terminal_46(Net_107),
        .Terminal_47(Net_108),
        .Terminal_48(Net_109),
        .Terminal_49(Net_110),
        .Terminal_50(Net_111),
        .Terminal_57(Net_112),
        .Terminal_59(Net_113),
        .Terminal_61(Net_114),
        .Terminal_63(Net_115),
        .Terminal_65(Net_116),
        .Terminal_67(Net_117),
        .Terminal_68(Net_118),
        .Terminal_66(Net_119),
        .Terminal_64(Net_120),
        .Terminal_62(Net_121),
        .Terminal_60(Net_122),
        .Terminal_58(Net_123),
        .Terminal_33(Net_124),
        .Terminal_32(Net_125),
        .Terminal_31(Net_126),
        .Terminal_30(Net_127),
        .Terminal_29(Net_128),
        .Terminal_28(Net_129),
        .Terminal_19(Net_130),
        .Terminal_17(Net_131),
        .Terminal_14(Net_132),
        .Terminal_16(Net_133),
        .Terminal_15(Net_134),
        .Terminal_13(Net_135),
        .Terminal_10(Net_136),
        .Terminal_12(Net_137),
        .Terminal_11(Net_138),
        .Terminal_9(Net_139),
        .Terminal_6(Net_140),
        .Terminal_8(Net_141),
        .Terminal_7(Net_142),
        .Terminal_5(Net_143),
        .Terminal_2(Net_144),
        .Terminal_4(Net_145),
        .Terminal_3(Net_146),
        .Terminal_1(Net_147),
        .Terminal_55(Net_148),
        .Terminal_56(Net_149),
        .Terminal_54(Net_150),
        .Terminal_53(Net_151),
        .Terminal_51(Net_152),
        .Terminal_52(Net_153));

    cy_annotation_universal_v1_0 PWR_3 (
        .connect({
            Net_728
        })
    );
    defparam PWR_3.comp_name = "Power_v1_0";
    defparam PWR_3.port_names = "T1";
    defparam PWR_3.width = 1;

    cy_annotation_universal_v1_0 GND_5 (
        .connect({
            Net_729
        })
    );
    defparam GND_5.comp_name = "Gnd_v1_0";
    defparam GND_5.port_names = "T1";
    defparam GND_5.width = 1;

    cy_annotation_universal_v1_0 P_2 (
        .connect({
            Net_195,
            Net_203,
            Net_204,
            Net_205,
            Net_206,
            Net_207,
            Net_208,
            Net_209,
            Net_210,
            Net_211,
            Net_212,
            P2_4,
            Net_213,
            Net_194,
            Net_197,
            Net_198,
            Net_199,
            Net_200,
            Net_201,
            Net_202
        })
    );
    defparam P_2.comp_name = "Connector20_v1_0";
    defparam P_2.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_2.width = 20;

    cy_annotation_universal_v1_0 PWR_2 (
        .connect({
            Net_194
        })
    );
    defparam PWR_2.comp_name = "Power_v1_0";
    defparam PWR_2.port_names = "T1";
    defparam PWR_2.width = 1;

    cy_annotation_universal_v1_0 GND_4 (
        .connect({
            Net_195
        })
    );
    defparam GND_4.comp_name = "Gnd_v1_0";
    defparam GND_4.port_names = "T1";
    defparam GND_4.width = 1;

    cy_annotation_universal_v1_0 P_1 (
        .connect({
            Net_214,
            Net_222,
            Net_223,
            Net_224,
            Net_225,
            Net_226,
            Net_227,
            Net_228,
            Net_229,
            Net_230,
            Net_231,
            P1_0,
            Net_232,
            Net_215,
            Net_216,
            Net_217,
            Net_218,
            Net_219,
            Net_220,
            Net_221
        })
    );
    defparam P_1.comp_name = "Connector20_v1_0";
    defparam P_1.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_1.width = 20;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_215
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_214
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 P_3 (
        .connect({
            Net_283,
            Net_262,
            Net_263,
            Net_264,
            Net_265,
            Net_266,
            Net_267,
            Net_268,
            Net_269,
            Net_270,
            Net_271,
            Net_284,
            Net_272,
            Net_284,
            Net_256,
            P3_0,
            P3_1,
            P2_7,
            P1_3,
            Net_261
        })
    );
    defparam P_3.comp_name = "Connector20_v1_0";
    defparam P_3.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_3.width = 20;

    cy_annotation_universal_v1_0 PWR_4 (
        .connect({
            Net_283
        })
    );
    defparam PWR_4.comp_name = "Power_v1_0";
    defparam PWR_4.port_names = "T1";
    defparam PWR_4.width = 1;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_283,
            P3_1
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_283,
            P3_0
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_284
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;



endmodule

