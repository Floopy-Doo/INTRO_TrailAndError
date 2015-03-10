/**
 * \file
 * \brief LED C++ driver implementation.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements an example of a LED driver in C++.
 */

#include "Platform.h"
#include "LEDcpp.h"
#include "BitIoLdd3.h"

#if PL_IS_FRDM /* only implemented for FRDM for now */

class LED {
private:
  FGPIO_MemMapPtr basePtr;
  uint32_t mask;
public:
  LED(FGPIO_MemMapPtr basePtr, unsigned int mask) {
    this->basePtr = basePtr;
    this->mask = mask;
  }
  void On(void)  { GPIO_PDD_ClearPortDataOutputMask(this->basePtr, this->mask); }
  void Off(void) { GPIO_PDD_SetPortDataOutputMask(this->basePtr, this->mask); }
  void Neg(void) { GPIO_PDD_TogglePortDataOutputMask(this->basePtr, this->mask); }
};

static LED led1(BitIoLdd3_MODULE_BASE_ADDRESS, BitIoLdd3_PORT_MASK);

void LEDcpp_Test(void) {
  LED led2(BitIoLdd3_MODULE_BASE_ADDRESS, BitIoLdd3_PORT_MASK);

  led2.On();
  led2.Off();

  led1.On();
  led2.Off();
}

#endif /* PL_IS_FRDM */
