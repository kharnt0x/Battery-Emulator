#ifndef TESLA_MODEL_3_BATTERY_H
#define TESLA_MODEL_3_BATTERY_H
#include <Arduino.h>
#include "../../USER_SETTINGS.h"
#include "../devboard/config.h"  // Needed for all defines
#include "../lib/miwagner-ESP32-Arduino-CAN/ESP32CAN.h"

#define BATTERY_SELECTED

#define RAMPDOWN_SOC 900             // 90.0 SOC% to start ramping down from max charge power towards 0 at 100.00%
#define FLOAT_MAX_POWER_W 200        // W, what power to allow for top balancing battery
#define FLOAT_START_MV 20            // mV, how many mV under overvoltage to start float charging
#define MAXCHARGEPOWERALLOWED 15000  // 15000W we use a define since the value supplied by Tesla is always 0
#define MAXDISCHARGEPOWERALLOWED \
  60000  // 60000W we need to cap this value to max 60kW, most inverters overflow otherwise

// These parameters need to be mapped for the inverter
extern uint32_t system_capacity_Wh;                        //Wh,  0-150000Wh
extern uint32_t system_remaining_capacity_Wh;              //Wh,  0-150000Wh
extern int16_t system_temperature_min_dC;                  //C+1, -50.0 - 50.0
extern int16_t system_temperature_max_dC;                  //C+1, -50.0 - 50.0
extern int16_t system_active_power_W;                      //W, -32000 to 32000
extern int16_t system_battery_current_dA;                  //A+1, -1000 - 1000
extern uint16_t system_battery_voltage_dV;                 //V+1,  0-500.0 (0-5000)
extern uint16_t system_max_design_voltage_dV;              //V+1,  0-500.0 (0-5000)
extern uint16_t system_min_design_voltage_dV;              //V+1,  0-500.0 (0-5000)
extern uint16_t system_scaled_SOC_pptt;                    //SOC%, 0-100.00 (0-10000)
extern uint16_t system_real_SOC_pptt;                      //SOC%, 0-100.00 (0-10000)
extern uint16_t system_SOH_pptt;                           //SOH%, 0-100.00 (0-10000)
extern uint16_t system_max_discharge_power_W;              //W,    0-65000
extern uint16_t system_max_charge_power_W;                 //W,    0-65000
extern uint16_t system_cell_max_voltage_mV;                //mV, 0-5000, Stores the highest cell millivolt value
extern uint16_t system_cell_min_voltage_mV;                //mV, 0-5000, Stores the minimum cell millivolt value
extern uint16_t system_cellvoltages_mV[MAX_AMOUNT_CELLS];  //Array with all cell voltages in mV
extern uint8_t system_number_of_cells;                     //Total number of cell voltages, set by each battery
extern uint8_t system_bms_status;                          //Enum 0-5
extern bool batteryAllowsContactorClosing;                 //Bool, 1=true, 0=false
extern bool inverterAllowsContactorClosing;                //Bool, 1=true, 0=false
extern bool system_LFP_Chemistry;                          //Bool, 1=true, 0=false

extern bool forceOpenContactors;  // This is used to force the contactors open, used for testing

extern uint32_t total_discharge;
extern uint32_t total_charge;
extern uint16_t volts;
extern int16_t amps;
extern int16_t power;
extern uint16_t raw_amps;
extern int16_t max_temp;
extern int16_t min_temp;
extern uint16_t energy_buffer;
extern uint16_t energy_to_charge_complete;
extern uint16_t expected_energy_remaining;
extern uint8_t full_charge_complete;
extern uint16_t ideal_energy_remaining;
extern uint16_t nominal_energy_remaining;
extern uint16_t nominal_full_pack_energy;
extern uint16_t bat_beginning_of_life;
extern uint16_t battery_charge_time_remaining;
extern uint16_t regenerative_limit;
extern uint16_t discharge_limit;
extern uint16_t max_heat_park;
extern uint16_t hvac_max_power;
extern uint16_t max_discharge_current;
extern uint16_t max_charge_current;
extern uint16_t bms_max_voltage;
extern uint16_t bms_min_voltage;
extern uint16_t high_voltage;
extern uint16_t low_voltage;
extern uint16_t output_current;
extern uint16_t soc_min;
extern uint16_t soc_max;
extern uint16_t soc_vi;
extern uint16_t soc_ave;
extern uint16_t cell_max_v;
extern uint16_t cell_min_v;
extern uint16_t cell_deviation_mV;
extern uint8_t max_vno;
extern uint8_t min_vno;
extern uint8_t contactor;
extern uint8_t hvil_status;
extern uint8_t packContNegativeState;
extern uint8_t packContPositiveState;
extern uint8_t packContactorSetState;
extern uint8_t packCtrsClosingAllowed;
extern uint8_t pyroTestInProgress;
extern uint8_t send221still;

void printFaultCodesIfActive();
void printDebugIfActive(uint8_t symbol, const char* message);
void print_int_with_units(char* header, int value, char* units);
void print_SOC(char* header, int SOC);
void setup_battery(void);

#endif
