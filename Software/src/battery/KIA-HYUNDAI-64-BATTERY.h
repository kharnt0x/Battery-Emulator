#ifndef KIA_HYUNDAI_64_BATTERY_H
#define KIA_HYUNDAI_64_BATTERY_H
#include <Arduino.h>
#include "../include.h"

#define BATTERY_SELECTED
#define MAX_CELL_DEVIATION_MV 150

void setup_battery(void);
void update_number_of_cells();
void transmit_can(CAN_frame* tx_frame, int interface);

#endif
