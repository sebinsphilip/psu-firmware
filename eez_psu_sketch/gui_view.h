/*
 * EEZ PSU Firmware
 * Copyright (C) 2015 Envox d.o.o.
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

#pragma pack(push, 1)

#define SMALL_FONT 1
#define MEDIUM_FONT 2
#define LARGE_FONT 3
#define STYLE_FLAGS_BORDER 1
#define STYLE_FLAGS_HORZ_ALIGN 6
#define STYLE_FLAGS_HORZ_ALIGN_LEFT 0
#define STYLE_FLAGS_HORZ_ALIGN_RIGHT 2
#define STYLE_FLAGS_HORZ_ALIGN_CENTER 4
#define STYLE_FLAGS_VERT_ALIGN 24
#define STYLE_FLAGS_VERT_ALIGN_TOP 0
#define STYLE_FLAGS_VERT_ALIGN_BOTTOM 8
#define STYLE_FLAGS_VERT_ALIGN_CENTER 16
#define WIDGET_TYPE_NONE 0
#define WIDGET_TYPE_CONTAINER 1
#define WIDGET_TYPE_VERTICAL_LIST 2
#define WIDGET_TYPE_SELECT 3
#define WIDGET_TYPE_DISPLAY 4
#define WIDGET_TYPE_DISPLAY_STRING 5
#define WIDGET_TYPE_DISPLAY_STRING_SELECT 6
#define WIDGET_TYPE_THREE_STATE_INDICATOR 7
#define WIDGET_TYPE_VERTICAL_SLIDER 8
#define DISPLAY_POSITION_OR_SIZE_FIELD_MULTIPLIER 2
#define DATA_ID_CHANNELS 1
#define DATA_ID_OUTPUT_STATE 2
#define DATA_ID_OUTPUT_MODE 3
#define DATA_ID_MON_VALUE 4
#define DATA_ID_VOLT 5
#define DATA_ID_CURR 6
#define DATA_ID_OVP 7
#define DATA_ID_OCP 8
#define DATA_ID_OPP 9
#define DATA_ID_OTP 10
#define DATA_ID_DP 11
#define ACTION_ID_SLIDER 1
#define ACTION_ID_EXIT 2
#define ACTION_ID_TOGGLE_CHANNEL 3

typedef uint16_t OBJ_OFFSET;

struct List {
    uint8_t count;
    OBJ_OFFSET first;
};

struct DisplayStringSelectWidget {
    OBJ_OFFSET style1;
    OBJ_OFFSET text1;
    OBJ_OFFSET style2;
    OBJ_OFFSET text2;
};

struct SelectWidget {
    List widgets;
};

struct Document {
    List styles;
    List pages;
};

struct ContainerWidget {
    List widgets;
};

struct Widget {
    uint8_t type;
    uint8_t data;
    uint8_t action;
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;
    OBJ_OFFSET style;
    OBJ_OFFSET specific;
};

struct VerticalListWidget {
    OBJ_OFFSET item_widget;
};

struct ThreeStateIndicatorWidget {
    OBJ_OFFSET style1;
    OBJ_OFFSET style2;
    OBJ_OFFSET text;
};

struct Style {
    uint8_t font;
    uint16_t flags;
    uint16_t background_color;
    uint16_t color;
    uint16_t border_color;
    uint16_t padding_horizontal;
    uint16_t padding_vertical;
};

struct DisplayStringWidget {
    OBJ_OFFSET text;
};

#pragma pack(pop)

uint8_t document[714] = {
    0x0D, 0x06, 0x00, 0x02, 0xAF, 0x00, 0x02, 0x14, 0x00, 0xBA, 0x55, 0xE0, 0xFF, 0x9A, 0xD6, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x14, 0x00, 0xBA, 0x55, 0xE0, 0xFF, 0x9A, 0xD6, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x12, 0x00, 0xBA, 0x55, 0xE0, 0xFF, 0x9A, 0xD6, 0x0C, 0x00, 0x00, 0x00, 0x03, 0x12, 0x00,
    0xBA, 0x55, 0x00, 0xF8, 0x9A, 0xD6, 0x0C, 0x00, 0x00, 0x00, 0x02, 0x12, 0x00, 0xBA, 0x55, 0xE0,
    0xFF, 0x9A, 0xD6, 0x0C, 0x00, 0x00, 0x00, 0x02, 0x12, 0x00, 0xBA, 0x55, 0x00, 0xF8, 0x9A, 0xD6,
    0x0C, 0x00, 0x00, 0x00, 0x03, 0x14, 0x00, 0xBA, 0x55, 0xE0, 0xFF, 0x9A, 0xD6, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x14, 0x00, 0xBA, 0x55, 0xE0, 0xFF, 0x9A, 0xD6, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10,
    0x00, 0xBA, 0x55, 0x10, 0x84, 0x9A, 0xD6, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0xBA, 0x55,
    0x00, 0x04, 0x9A, 0xD6, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0xBA, 0x55, 0x00, 0xF8, 0x9A,
    0xD6, 0x00, 0x00, 0x00, 0x00, 0x01, 0x14, 0x00, 0xBA, 0x55, 0xFF, 0xFF, 0x9A, 0xD6, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x10, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x9A, 0xD6, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x78, 0xA0, 0x06, 0x00, 0xC5, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x78,
    0xA0, 0x06, 0x00, 0xC8, 0x00, 0x02, 0xCB, 0x00, 0x03, 0xE1, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x78, 0xA0, 0x06, 0x00, 0x02, 0x01, 0x05, 0x00, 0x00, 0x00, 0x8A, 0x78, 0x16, 0x95, 0x00, 0x04,
    0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x1E, 0xA0, 0xA2, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x1E,
    0x00, 0x5A, 0xA0, 0x06, 0x00, 0x06, 0x01, 0x05, 0x00, 0x02, 0x1E, 0x8A, 0x5A, 0x16, 0x95, 0x00,
    0x08, 0x01, 0x0A, 0x01, 0x15, 0x01, 0x29, 0x01, 0x34, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x78,
    0x45, 0x06, 0x00, 0x39, 0x01, 0x4D, 0x61, 0x69, 0x6E, 0x20, 0x7C, 0x20, 0x4F, 0x66, 0x66, 0x20,
    0x7C, 0x20, 0x52, 0x65, 0x6D, 0x6F, 0x74, 0x65, 0x00, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x5A, 0x45,
    0x06, 0x00, 0x3C, 0x01, 0x45, 0x78, 0x69, 0x74, 0x00, 0x08, 0x3F, 0x01, 0x08, 0x97, 0x01, 0x07,
    0x07, 0x00, 0x00, 0x00, 0x16, 0x0D, 0x6E, 0x00, 0xEF, 0x01, 0x07, 0x08, 0x00, 0x16, 0x00, 0x16,
    0x0D, 0x6E, 0x00, 0xF5, 0x01, 0x07, 0x09, 0x00, 0x2C, 0x00, 0x16, 0x0D, 0x6E, 0x00, 0xFB, 0x01,
    0x07, 0x0A, 0x00, 0x42, 0x00, 0x16, 0x0D, 0x6E, 0x00, 0x01, 0x02, 0x06, 0x0B, 0x00, 0x58, 0x00,
    0x20, 0x0D, 0x06, 0x00, 0x07, 0x02, 0x03, 0x02, 0x03, 0x00, 0x0D, 0x78, 0x24, 0x06, 0x00, 0x0F,
    0x02, 0x04, 0x05, 0x01, 0x00, 0x31, 0x3C, 0x14, 0x06, 0x00, 0x00, 0x00, 0x04, 0x06, 0x01, 0x3C,
    0x31, 0x3C, 0x14, 0x06, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x1E, 0x00, 0x10, 0x0D, 0x6E, 0x00,
    0x12, 0x02, 0x07, 0x08, 0x00, 0x2E, 0x00, 0x10, 0x0D, 0x6E, 0x00, 0x18, 0x02, 0x07, 0x09, 0x00,
    0x3E, 0x00, 0x10, 0x0D, 0x6E, 0x00, 0x1E, 0x02, 0x07, 0x0A, 0x00, 0x4E, 0x00, 0x10, 0x0D, 0x6E,
    0x00, 0x24, 0x02, 0x06, 0x0B, 0x00, 0x5E, 0x00, 0x1A, 0x0D, 0x06, 0x00, 0x2A, 0x02, 0x03, 0x02,
    0x00, 0x1E, 0x0D, 0x5A, 0x24, 0x06, 0x00, 0x32, 0x02, 0x04, 0x05, 0x00, 0x1E, 0x31, 0x2D, 0x14,
    0x13, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00, 0x4B, 0x31, 0x2D, 0x14, 0x13, 0x00, 0x00, 0x00, 0x7B,
    0x00, 0x88, 0x00, 0x35, 0x02, 0x7B, 0x00, 0x88, 0x00, 0x39, 0x02, 0x7B, 0x00, 0x88, 0x00, 0x3D,
    0x02, 0x7B, 0x00, 0x88, 0x00, 0x41, 0x02, 0x7B, 0x00, 0x45, 0x02, 0x6E, 0x00, 0x4B, 0x02, 0x02,
    0x52, 0x02, 0x7B, 0x00, 0x88, 0x00, 0x68, 0x02, 0x7B, 0x00, 0x88, 0x00, 0x6A, 0x02, 0x7B, 0x00,
    0x88, 0x00, 0x6C, 0x02, 0x7B, 0x00, 0x88, 0x00, 0x6E, 0x02, 0x7B, 0x00, 0x70, 0x02, 0x6E, 0x00,
    0x73, 0x02, 0x02, 0x76, 0x02, 0x4F, 0x56, 0x50, 0x00, 0x4F, 0x43, 0x50, 0x00, 0x4F, 0x50, 0x50,
    0x00, 0x4F, 0x54, 0x50, 0x00, 0x44, 0x50, 0x20, 0x6F, 0x6E, 0x00, 0x44, 0x50, 0x20, 0x6F, 0x66,
    0x66, 0x00, 0x05, 0x00, 0x03, 0x00, 0x0D, 0x78, 0x24, 0x54, 0x00, 0x8C, 0x02, 0x03, 0x03, 0x03,
    0x00, 0x0D, 0x78, 0x24, 0x06, 0x00, 0x8E, 0x02, 0x56, 0x00, 0x43, 0x00, 0x50, 0x00, 0x54, 0x00,
    0x44, 0x50, 0x00, 0x44, 0x50, 0x00, 0x05, 0x00, 0x00, 0x1E, 0x0D, 0x5A, 0x24, 0x61, 0x00, 0x91,
    0x02, 0x03, 0x03, 0x00, 0x1E, 0x0D, 0x5A, 0x24, 0x06, 0x00, 0x93, 0x02, 0x96, 0x02, 0x02, 0x9A,
    0x02, 0xB0, 0x02, 0x02, 0xB4, 0x02, 0x4F, 0x46, 0x46, 0x00, 0x04, 0x04, 0x03, 0x00, 0x0D, 0x78,
    0x24, 0x20, 0x00, 0x00, 0x00, 0x04, 0x04, 0x03, 0x00, 0x0D, 0x78, 0x24, 0x2D, 0x00, 0x00, 0x00,
    0x4F, 0x46, 0x46, 0x00, 0x04, 0x04, 0x00, 0x1E, 0x0D, 0x5A, 0x24, 0x3A, 0x00, 0x00, 0x00, 0x04,
    0x04, 0x00, 0x1E, 0x0D, 0x5A, 0x24, 0x47, 0x00, 0x00, 0x00
};
