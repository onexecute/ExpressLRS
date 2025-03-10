#pragma once

#define REG_LR_FIRMWARE_VERSION_MSB 0x0153 //The address of the register holding the firmware version MSB
#define SX1280_REG_LR_ESTIMATED_FREQUENCY_ERROR_MSB 0x0954
#define SX1280_REG_LR_ESTIMATED_FREQUENCY_ERROR_MASK 0x0FFFFF

#define SX1280_REG_FLRC_CRC_POLY    0x9C6
#define SX1280_REG_FLRC_CRC_SEED    0x9C8
#define SX1280_REG_FLRC_SYNC_WORD   0x9CF

#define SX1280_XTAL_FREQ 52000000
#define FREQ_STEP ((double)(SX1280_XTAL_FREQ / pow(2.0, 18.0)))

typedef enum
{
    SX1280_RF_IDLE = 0x00, //!< The radio is idle
    SX1280_RF_RX_RUNNING,  //!< The radio is in reception state
    SX1280_RF_TX_RUNNING,  //!< The radio is in transmission state
    SX1280_RF_CAD,         //!< The radio is doing channel activity detection
} SX1280_RadioStates_t;

/*!
 * \brief Represents the operating mode the radio is actually running
 */
typedef enum
{
    SX1280_MODE_SLEEP = 0x00, //! The radio is in sleep mode
    SX1280_MODE_CALIBRATION,  //! The radio is in calibration mode
    SX1280_MODE_STDBY_RC,     //! The radio is in standby mode with RC oscillator
    SX1280_MODE_STDBY_XOSC,   //! The radio is in standby mode with XOSC oscillator
    SX1280_MODE_FS,           //! The radio is in frequency synthesis mode
    SX1280_MODE_RX,           //! The radio is in receive mode
    SX1280_MODE_TX,           //! The radio is in transmit mode
    SX1280_MODE_CAD           //! The radio is in channel activity detection mode
} SX1280_RadioOperatingModes_t;

#define SX1280_RX_TX_CONTINUOUS \
    (TickTime_t) { RADIO_TICK_SIZE_0015_US, 0xFFFF }
#define SX1280_RX_TX_SINGLE \
    (TickTime_t) { RADIO_TICK_SIZE_0015_US, 0 }

/*!
 * \brief Declares the oscillator in use while in standby mode
 *
 * Using the STDBY_RC standby mode allow to reduce the energy consumption
 * STDBY_XOSC should be used for time critical applications
 */
typedef enum
{
    SX1280_STDBY_RC = 0x00,
    SX1280_STDBY_XOSC = 0x01,
} SX1280_RadioStandbyModes_t;

/*!
 * \brief Declares the power regulation used to power the device
 *
 * This command allows the user to specify if DC-DC or LDO is used for power regulation.
 * Using only LDO implies that the Rx or Tx current is doubled
 */
typedef enum
{
    SX1280_USE_LDO = 0x00,  //! Use LDO (default value)
    SX1280_USE_DCDC = 0x01, //! Use DCDC
} SX1280_RadioRegulatorModes_t;

/*!
 * \brief Represents the possible packet type (i.e. modem) used
 */
typedef enum
{
    SX1280_PACKET_TYPE_GFSK = 0x00,
    SX1280_PACKET_TYPE_LORA,
    SX1280_PACKET_TYPE_RANGING,
    SX1280_PACKET_TYPE_FLRC,
    SX1280_PACKET_TYPE_BLE,
    SX1280_PACKET_TYPE_NONE = 0x0F,
} SX1280_RadioPacketTypes_t;

//only for GFSK
// typedef enum
// {
//     SX1280_PREAMBLE_LENGTH_04_BITS = 0x00, //!< Preamble length: 04 bits
//     SX1280_PREAMBLE_LENGTH_08_BITS = 0x10, //!< Preamble length: 08 bits
//     SX1280_PREAMBLE_LENGTH_12_BITS = 0x20, //!< Preamble length: 12 bits
//     SX1280_PREAMBLE_LENGTH_16_BITS = 0x30, //!< Preamble length: 16 bits
//     SX1280_PREAMBLE_LENGTH_20_BITS = 0x40, //!< Preamble length: 20 bits
//     SX1280_PREAMBLE_LENGTH_24_BITS = 0x50, //!< Preamble length: 24 bits
//     SX1280_PREAMBLE_LENGTH_28_BITS = 0x60, //!< Preamble length: 28 bits
//     SX1280_PREAMBLE_LENGTH_32_BITS = 0x70, //!< Preamble length: 32 bits
// } SX1280_RadioPreambleLengths_t;

typedef enum
{
    SX1280_LORA_IQ_NORMAL = 0x40,
    SX1280_LORA_IQ_INVERTED = 0x00,
} SX1280_RadioLoRaIQModes_t;

typedef enum
{
    SX1280_RADIO_CRC_OFF = 0x00, //!< No CRC in use
    SX1280_RADIO_CRC_1_BYTES = 0x10,
    SX1280_RADIO_CRC_2_BYTES = 0x20,
    SX1280_RADIO_CRC_3_BYTES = 0x30,
} SX1280_RadioCrcTypes_t;

/*!
 * \brief Represents the ramping time for power amplifier
 */
typedef enum
{
    SX1280_RADIO_RAMP_02_US = 0x00,
    SX1280_RADIO_RAMP_04_US = 0x20,
    SX1280_RADIO_RAMP_06_US = 0x40,
    SX1280_RADIO_RAMP_08_US = 0x60,
    SX1280_RADIO_RAMP_10_US = 0x80,
    SX1280_RADIO_RAMP_12_US = 0xA0,
    SX1280_RADIO_RAMP_16_US = 0xC0,
    SX1280_RADIO_RAMP_20_US = 0xE0,
} SX1280_RadioRampTimes_t;

/*!
 * \brief Represents the number of symbols to be used for channel activity detection operation
 */
typedef enum
{
    SX1280_LORA_CAD_01_SYMBOL = 0x00,
    SX1280_LORA_CAD_02_SYMBOLS = 0x20,
    SX1280_LORA_CAD_04_SYMBOLS = 0x40,
    SX1280_LORA_CAD_08_SYMBOLS = 0x60,
    SX1280_LORA_CAD_16_SYMBOLS = 0x80,
} SX1280_RadioLoRaCadSymbols_t;

/*!
 * \brief Represents the possible spreading factor values in LORA packet types
 */
typedef enum
{
    SX1280_LORA_SF5 = 0x50,
    SX1280_LORA_SF6 = 0x60,
    SX1280_LORA_SF7 = 0x70,
    SX1280_LORA_SF8 = 0x80,
    SX1280_LORA_SF9 = 0x90,
    SX1280_LORA_SF10 = 0xA0,
    SX1280_LORA_SF11 = 0xB0,
    SX1280_LORA_SF12 = 0xC0,
} SX1280_RadioLoRaSpreadingFactors_t;

/*!
 * \brief Represents the bandwidth values for LORA packet type
 */
typedef enum
{
    SX1280_LORA_BW_0200 = 0x34,
    SX1280_LORA_BW_0400 = 0x26,
    SX1280_LORA_BW_0800 = 0x18,
    SX1280_LORA_BW_1600 = 0x0A,
} SX1280_RadioLoRaBandwidths_t;

/*!
 * \brief Represents the coding rate values for LORA packet type
 */
typedef enum
{
    SX1280_LORA_CR_4_5 = 0x01,
    SX1280_LORA_CR_4_6 = 0x02,
    SX1280_LORA_CR_4_7 = 0x03,
    SX1280_LORA_CR_4_8 = 0x04,
    SX1280_LORA_CR_LI_4_5 = 0x05,
    SX1280_LORA_CR_LI_4_6 = 0x06,
    SX1280_LORA_CR_LI_4_7 = 0x07,
} SX1280_RadioLoRaCodingRates_t;

typedef enum
{
    SX1280_LORA_PACKET_VARIABLE_LENGTH = 0x00, //!< The packet is on variable size, header included
    SX1280_LORA_PACKET_FIXED_LENGTH = 0x80,    //!< The packet is known on both sides, no header included in the packet
    SX1280_LORA_PACKET_EXPLICIT = SX1280_LORA_PACKET_VARIABLE_LENGTH,
    SX1280_LORA_PACKET_IMPLICIT = SX1280_LORA_PACKET_FIXED_LENGTH,
} SX1280_RadioLoRaPacketLengthsModes_t;

typedef enum
{
    SX1280_LORA_CRC_ON = 0x20,  //!< CRC activated
    SX1280_LORA_CRC_OFF = 0x00, //!< CRC not used
} SX1280_RadioLoRaCrcModes_t;

/*!
 * \brief Represents the bandwidth values for FLRC packet type
 */
typedef enum
{
    SX1280_FLRC_BR_1_300_BW_1_2 = 0x45,
    SX1280_FLRC_BR_1_000_BW_1_2 = 0x69,
    SX1280_FLRC_BR_0_650_BW_0_6 = 0x86,
    SX1280_FLRC_BR_0_520_BW_0_6 = 0xAA,
    SX1280_FLRC_BR_0_325_BW_0_3 = 0xC7,
    SX1280_FLRC_BR_0_260_BW_0_3 = 0xEB,
} SX1280_RadioFlrcBandwidths_t;

/*!
 * \brief Represents the coding rate values for FLRC packet type
 */
typedef enum
{
    SX1280_FLRC_CR_1_2 = 0x00,
    SX1280_FLRC_CR_3_4 = 0x02,
    SX1280_FLRC_CR_1_0 = 0x04,
} SX1280_RadioFlrcCodingRates_t;

/*!
 * \brief Represents the Gaussian filter value in FLRC packet types
 */
typedef enum
{
    SX1280_FLRC_BT_DIS  = 0x00,
    SX1280_FLRC_BT_1    = 0x10,
    SX1280_FLRC_BT_0_5  = 0x20,
} SX1280_RadioFlrcGaussianFilter_t;

typedef enum
{
    SX1280_FLRC_SYNC_NOSYNC        = 0x00,
    SX1280_FLRC_SYNC_WORD_LEN_P32S = 0x04,
} SX1280_RadioFlrcSyncWordLen_t;

typedef enum
{
    SX1280_FLRC_RX_DISABLE_SYNC_WORD     = 0x00,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_1     = 0x10,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_2     = 0x20,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_1_2   = 0x30,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_3     = 0x40,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_1_3   = 0x50,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_2_3   = 0x60,
    SX1280_FLRC_RX_MATCH_SYNC_WORD_1_2_3 = 0x70,
} SX1280_RadioFlrcSyncWordCombination_t;

typedef enum
{
    SX1280_FLRC_PACKET_FIXED_LENGTH    = 0x00,
    SX1280_FLRC_PACKET_VARIABLE_LENGTH = 0x20,
} SX1280_RadioFlrcPacketType_t;

typedef enum
{
    SX1280_FLRC_CRC_OFF    = 0x00,
    SX1280_FLRC_CRC_1_BYTE = 0x10,
    SX1280_FLRC_CRC_2_BYTE = 0x20,
    SX1280_FLRC_CRC_3_BYTE = 0x30,
} SX1280_RadioFlrcCrc_t;

enum
{
    // Error Packet Status
    SX1280_FLRC_PKT_ERROR_BUSY      = 1 << 0,
    SX1280_FLRC_PKT_ERROR_PKT_RCVD  = 1 << 1,
    SX1280_FLRC_PKT_ERROR_HDR_RCVD  = 1 << 2,
    SX1280_FLRC_PKT_ERROR_ABORT     = 1 << 3,
    SX1280_FLRC_PKT_ERROR_CRC       = 1 << 4,
    SX1280_FLRC_PKT_ERROR_LENGTH    = 1 << 5,
    SX1280_FLRC_PKT_ERROR_SYNC      = 1 << 6,
};

typedef enum RadioCommands_u
{
    SX1280_RADIO_GET_STATUS = 0xC0,
    SX1280_RADIO_WRITE_REGISTER = 0x18,
    SX1280_RADIO_READ_REGISTER = 0x19,
    SX1280_RADIO_WRITE_BUFFER = 0x1A,
    SX1280_RADIO_READ_BUFFER = 0x1B,
    SX1280_RADIO_SET_SLEEP = 0x84,
    SX1280_RADIO_SET_STANDBY = 0x80,
    SX1280_RADIO_SET_FS = 0xC1,
    SX1280_RADIO_SET_TX = 0x83,
    SX1280_RADIO_SET_RX = 0x82,
    SX1280_RADIO_SET_RXDUTYCYCLE = 0x94,
    SX1280_RADIO_SET_CAD = 0xC5,
    SX1280_RADIO_SET_TXCONTINUOUSWAVE = 0xD1,
    SX1280_RADIO_SET_TXCONTINUOUSPREAMBLE = 0xD2,
    SX1280_RADIO_SET_PACKETTYPE = 0x8A,
    SX1280_RADIO_GET_PACKETTYPE = 0x03,
    SX1280_RADIO_SET_RFFREQUENCY = 0x86,
    SX1280_RADIO_SET_TXPARAMS = 0x8E,
    SX1280_RADIO_SET_CADPARAMS = 0x88,
    SX1280_RADIO_SET_BUFFERBASEADDRESS = 0x8F,
    SX1280_RADIO_SET_MODULATIONPARAMS = 0x8B,
    SX1280_RADIO_SET_PACKETPARAMS = 0x8C,
    SX1280_RADIO_GET_RXBUFFERSTATUS = 0x17,
    SX1280_RADIO_GET_PACKETSTATUS = 0x1D,
    SX1280_RADIO_GET_RSSIINST = 0x1F,
    SX1280_RADIO_SET_DIOIRQPARAMS = 0x8D,
    SX1280_RADIO_GET_IRQSTATUS = 0x15,
    SX1280_RADIO_CLR_IRQSTATUS = 0x97,
    SX1280_RADIO_CALIBRATE = 0x89,
    SX1280_RADIO_SET_REGULATORMODE = 0x96,
    SX1280_RADIO_SET_SAVECONTEXT = 0xD5,
    SX1280_RADIO_SET_AUTOTX = 0x98,
    SX1280_RADIO_SET_AUTOFS = 0x9E,
    SX1280_RADIO_SET_LONGPREAMBLE = 0x9B,
    SX1280_RADIO_SET_UARTSPEED = 0x9D,
    SX1280_RADIO_SET_RANGING_ROLE = 0xA3,
} SX1280_RadioCommands_t;

typedef enum
{
    SX1280_IRQ_RADIO_NONE = 0x0000,
    SX1280_IRQ_TX_DONE = 0x0001,
    SX1280_IRQ_RX_DONE = 0x0002,
    SX1280_IRQ_SYNCWORD_VALID = 0x0004,
    SX1280_IRQ_SYNCWORD_ERROR = 0x0008,
    SX1280_IRQ_HEADER_VALID = 0x0010,
    SX1280_IRQ_HEADER_ERROR = 0x0020,
    SX1280_IRQ_CRC_ERROR = 0x0040,
    SX1280_IRQ_RANGING_SLAVE_RESPONSE_DONE = 0x0080,
    SX1280_IRQ_RANGING_SLAVE_REQUEST_DISCARDED = 0x0100,
    SX1280_IRQ_RANGING_MASTER_RESULT_VALID = 0x0200,
    SX1280_IRQ_RANGING_MASTER_TIMEOUT = 0x0400,
    SX1280_IRQ_RANGING_SLAVE_REQUEST_VALID = 0x0800,
    SX1280_IRQ_CAD_DONE = 0x1000,
    SX1280_IRQ_CAD_DETECTED = 0x2000,
    SX1280_IRQ_RX_TX_TIMEOUT = 0x4000,
    SX1280_IRQ_PREAMBLE_DETECTED = 0x8000,
    SX1280_IRQ_RADIO_ALL = 0xFFFF,
} SX1280_RadioIrqMasks_t;

typedef enum
{
    SX1280_RADIO_DIO1 = 0x02,
    SX1280_RADIO_DIO2 = 0x04,
    SX1280_RADIO_DIO3 = 0x08,
} SX1280_RadioDios_t;

typedef enum
{
    SX1280_RADIO_TICK_SIZE_0015_US = 0x00,
    SX1280_RADIO_TICK_SIZE_0062_US = 0x01,
    SX1280_RADIO_TICK_SIZE_1000_US = 0x02,
    SX1280_RADIO_TICK_SIZE_4000_US = 0x03,
} SX1280_RadioTickSizes_t;