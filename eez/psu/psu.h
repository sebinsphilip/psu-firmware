/*
 * EEZ PSU Firmware
 * Copyright (C) 2015-present, Envox d.o.o.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "eez/app/conf.h"

#if defined(EEZ_PLATFORM_ARDUINO_DUE)
#include "eez_psu.h"
#endif

#include <scpi-parser.h>

#include "eez/psu/ontime.h"

#if CONF_SERIAL_USE_NATIVE_USB_PORT
#define SERIAL_PORT SerialUSB
#else
#define SERIAL_PORT Serial
#endif

/// Namespace for the everything from the EEZ.
namespace eez {
/// PSU firmware.
namespace psu {

enum TestResult {
    TEST_FAILED = 0,
    TEST_OK = 1,
    TEST_SKIPPED = 2,
    TEST_WARNING = 3
};

void boot();

extern bool g_isBooted;

bool powerUp();
void powerDown();
bool isPowerUp();
bool changePowerState(bool up);
void schedulePowerDown();
void powerDownBySensor();

bool reset();

bool test();

void onProtectionTripped();

void tick();
bool criticalTick(int pageId);

void regSet(scpi_reg_name_t name, scpi_reg_val_t val);

void setEsrBits(int bit_mask);
void setQuesBits(int bit_mask, bool on);
void setOperBits(int bit_mask, bool on);

void generateError(int16_t error);

const char *getCpuModel();
const char *getCpuType();
const char *getCpuEthernetType();

enum MaxCurrentLimitCause {
    MAX_CURRENT_LIMIT_CAUSE_NONE,
    MAX_CURRENT_LIMIT_CAUSE_FAN,
    MAX_CURRENT_LIMIT_CAUSE_TEMPERATURE
};
bool isMaxCurrentLimited();
MaxCurrentLimitCause getMaxCurrentLimitCause();
void limitMaxCurrent(MaxCurrentLimitCause cause);
void unlimitMaxCurrent();

extern ontime::Counter g_powerOnTimeCounter;
extern volatile bool g_insideInterruptHandler;

#if defined(EEZ_PLATFORM_ARDUINO_DUE)
void SPI_usingInterrupt(uint8_t interruptNumber);
void SPI_beginTransaction(SPISettings &settings);
void SPI_endTransaction();
#endif

enum RLState {
    RL_STATE_LOCAL = 0,
    RL_STATE_REMOTE = 1,
    RL_STATE_RW_LOCK = 2
};

extern RLState g_rlState;

extern bool g_rprogAlarm;

bool isFrontPanelLocked();

}
} // namespace eez::psu

#include "eez/mw/mw.h"
#include "eez/mw/util.h"
using namespace eez::mw;

#include "eez/psu/debug.h"
#include "eez/psu/util.h"
#include "eez/psu/unit.h"
#include "eez/psu/channel.h"

#if defined(EEZ_PLATFORM_ARDUINO_DUE)
void PSU_boot();
void PSU_tick();
#endif