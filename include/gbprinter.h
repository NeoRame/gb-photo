#ifndef __GBPRINTER_H_INCLUDE__
#define __GBPRINTER_H_INCLUDE__

#include <gbdk/platform.h>
#include <stdint.h>

#include "bankdata.h"
#include "print_frames.h"

#define PALETTE_NORMAL      0b11100100u
#define PALETTE_INVERTED    0b00011011u

#define MAGIC_1             0x88
#define MAGIC_2             0x33

#define COMMAND_INIT        0x01
#define COMMAND_PRINT       0x02
#define COMMAND_DATA        0x04
#define COMMAND_STATUS      0x0F

#define EXPOSURE_LIGHT      0x00
#define EXPOSURE_DEFAULT    0x40
#define EXPOSURE_DARK       0x7F

#define STATUS_LOWBAT       0x80
#define STATUS_ER2          0x40
#define STATUS_ER1          0x20
#define STATUS_ER0          0x10
#define STATUS_UNTRAN       0x08
#define STATUS_FULL         0x04
#define STATUS_BUSY         0x02
#define STATUS_SUM          0x01
#define STATUS_OK           0x00

#define STATUS_MASK_ERRORS  0xF0
#define STATUS_MASK_ANY     0xFF

#define SECONDS(A)          ((A)*60)

extern uint8_t printer_completion;
extern far_ptr_t printer_progress_handler;

uint8_t gbprinter_detect(uint8_t delay) BANKED;
uint8_t gbprinter_print_image(const uint8_t * image, uint8_t image_bank, const frame_desc_t * frame, uint8_t frame_bank) BANKED;

inline void gbprinter_set_handler(void * fn_ofs, uint8_t fn_seg) {
    printer_progress_handler.SEG = fn_seg, printer_progress_handler.OFS = fn_ofs;
}

#endif