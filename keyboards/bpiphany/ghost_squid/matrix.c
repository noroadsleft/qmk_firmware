/*
  Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>
  Copyright 2016 Daniel Svensson <dsvensson@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

static uint8_t debouncing = DEBOUNCE;
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void select_row(uint8_t col);

inline uint8_t matrix_rows(void)
{
  return MATRIX_ROWS;
}

inline uint8_t matrix_cols(void)
{
  return MATRIX_COLS;
}

void matrix_init(void)
{
  /* Column output pins */ 
  DDRD  |=  0b01111110;    
  /* Row input pins */     
  DDRC  &= ~0b00000100;    
  DDRB  &= ~0b01111111;    
  PORTC |=  0b00000100;    
  PORTB |=  0b01111111;
  
  for (uint8_t i=0; i < MATRIX_ROWS; i++)  {
    matrix[i] = 0;
    matrix_debouncing[i] = 0;
  }
  
  matrix_init_quantum();
}

uint8_t matrix_scan(void)
{
  for (uint8_t col = 0; col < MATRIX_COLS; col++) {
    select_row(col);
    wait_us(30);
    matrix_row_t rows = read_cols();
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
      bool prev_bit = matrix_debouncing[row] & ((matrix_row_t)1<<col);
      bool curr_bit = rows & (1<<row);
      if (prev_bit != curr_bit) {
	matrix_debouncing[row] ^= (matrix_row_t) 1 << col;
	debouncing = DEBOUNCE;
      }
    }
  }

  if (debouncing) {
    if (--debouncing) {
      wait_ms(1);
    } else {
      for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
	matrix[i] = matrix_debouncing[i];
      }
    }
  }

  matrix_scan_quantum();

  return 1;
}

bool matrix_is_modified(void)
{
  if (debouncing)
    return false;
  return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
  return matrix[row] & 1 << col;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
  return matrix[row];
}

void matrix_print(void)
{
  print("\nr/c 0123456789ABCDEF\n");
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    phex(row); print(": ");
    pbin_reverse16(matrix_get_row(row));
    print("\n");
  }
}

uint8_t matrix_key_count(void)
{
  uint8_t count = 0;
  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    count += bitpop16(matrix[i]);
  }
  return count;
}

static matrix_row_t read_cols(void)
{
  return
    (PINB&(1<<1) ? 0 : ((matrix_row_t)1<<0)) |
    (PINC&(1<<2) ? 0 : ((matrix_row_t)1<<1)) |
    (PINB&(1<<6) ? 0 : ((matrix_row_t)1<<2)) |
    (PINB&(1<<4) ? 0 : ((matrix_row_t)1<<3)) |
    (PINB&(1<<3) ? 0 : ((matrix_row_t)1<<4)) |
    (PINB&(1<<2) ? 0 : ((matrix_row_t)1<<5)) |
    (PINB&(1<<0) ? 0 : ((matrix_row_t)1<<6)) |
    (PINB&(1<<5) ? 0 : ((matrix_row_t)1<<7)); 
}

static void select_row(uint8_t col)
{
  switch (col) {
  case  0: PORTD = (PORTD & ~0b01111110) | 0b01100010; break;
  case  1: PORTD = (PORTD & ~0b01111110) | 0b01101000; break;
  case  2: PORTD = (PORTD & ~0b01111110) | 0b01101100; break;
  case  3: PORTD = (PORTD & ~0b01111110) | 0b01110000; break;
  case  4: PORTD = (PORTD & ~0b01111110) | 0b01111000; break;
  case  5: PORTD = (PORTD & ~0b01111110) | 0b01100000; break;
  case  6: PORTD = (PORTD & ~0b01111110) | 0b01110100; break;
  case  7: PORTD = (PORTD & ~0b01111110) | 0b01100100; break;
  case  8: PORTD = (PORTD & ~0b01111110) | 0b01111100; break;
  case  9: PORTD = (PORTD & ~0b01111110) | 0b01101010; break;
  case 10: PORTD = (PORTD & ~0b01111110) | 0b00110110; break;
  case 11: PORTD = (PORTD & ~0b01111110) | 0b00010110; break;
  case 12: PORTD = (PORTD & ~0b01111110) | 0b01001110; break;
  case 13: PORTD = (PORTD & ~0b01111110) | 0b00111110; break;
  case 14: PORTD = (PORTD & ~0b01111110) | 0b00011110; break;
  case 15: PORTD = (PORTD & ~0b01111110) | 0b01000110; break;
  case 16: PORTD = (PORTD & ~0b01111110) | 0b00100110; break;
  case 17: PORTD = (PORTD & ~0b01111110) | 0b00101110; break;
  }
}
