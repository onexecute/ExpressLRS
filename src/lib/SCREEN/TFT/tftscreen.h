/*
 * This file is part of the ExpressLRS distribution (https://github.com/ExpressLRS/ExpressLRS).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "targets.h"
#include "TFT_eSPI_User_Setup.h"
#include <SPI.h>

#include "screen.h"

class TFTScreen: public Screen
{
private:
    void doRateValueSelect(int action);
    void doPowerValueSelect(int action);
    void doRatioValueSelect(int action);
    void doPowerSavingValueSelect(int action);
    void doSmartFanValueSelect(int action);

    void updateIdleScreen(uint8_t dirtyFlags);
    void updateMainMenuPage();
    void updateSubFunctionPage();
    void updateSubWIFIModePage();
    void updateSubBindConfirmPage();
    void updateSubBindingPage();
    void updateIdleTemperature();

    void displayFontCenter(uint32_t font_start_x, uint32_t font_end_x, uint32_t font_start_y,
                                            int font_size, int font_type, String font_string,
                                            uint16_t fgColor, uint16_t bgColor);

public:

    void init(bool reboot);
    void doTemperatureUpdate(uint8_t temperature);
    void doScreenBackLight(int state);

};
