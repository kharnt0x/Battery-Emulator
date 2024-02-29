#include "tesla_html.h"
#include <Arduino.h>
#include "../../battery/TESLA-MODEL-3-BATTERY.h"
#include "../utils/events.h"

void force_open_contactors(const uint8_t value) {
  forceOpenContactors = value;
}

void clear_cell_faults() {
  clear_event(EVENT_CELL_DEVIATION_HIGH);
  clear_event(EVENT_CELL_OVER_VOLTAGE);
  clear_event(EVENT_CELL_UNDER_VOLTAGE);
}

String tesla_processor(const String& var) {
  if (var == "PLACEHOLDER") {
    String content = "";

    // Page format
    content += "<style>";
    content += "body { background-color: black; color: white; }";
    content += ".container { display: flex; flex-wrap: wrap; justify-content: space-around; }";
    content += ".cell { width: 48%; margin: 1%; padding: 10px; border: 1px solid white; text-align: center; }";
    content += ".low-voltage { color: red; }";              // Style for low voltage text
    content += ".voltage-values { margin-bottom: 10px; }";  // Style for voltage values section
    content += "</style>";

    // Start a new block with a specific background color
    content += "<div style='background-color: #303E47; padding: 10px; margin-bottom: 10px; border-radius: 50px'>";

    // Display all the extern variables
    content += "<div class='voltage-values'>";
    content += "Total Discharge: " + String(total_discharge) + "<br>";
    content += "Total Charge: " + String(total_charge) + "<br>";
    content += "Volts: " + String(volts) + "<br>";
    content += "Amps: " + String(amps) + "<br>";
    content += "Power: " + String(power) + "<br>";
    content += "Raw Amps: " + String(raw_amps) + "<br>";
    content += "Max Temp: " + String(max_temp) + "<br>";
    content += "Min Temp: " + String(min_temp) + "<br>";
    content += "Energy Buffer: " + String(energy_buffer) + "<br>";
    content += "Energy to Charge Complete: " + String(energy_to_charge_complete) + "<br>";
    content += "Expected Energy Remaining: " + String(expected_energy_remaining) + "<br>";
    content += "Full Charge Complete: " + String(full_charge_complete) + "<br>";
    content += "Ideal Energy Remaining: " + String(ideal_energy_remaining) + "<br>";
    content += "Nominal Energy Remaining: " + String(nominal_energy_remaining) + "<br>";
    content += "Nominal Full Pack Energy: " + String(nominal_full_pack_energy) + "<br>";
    content += "Battery Beginning of Life: " + String(bat_beginning_of_life) + "<br>";
    content += "Battery Charge Time Remaining: " + String(battery_charge_time_remaining) + "<br>";
    content += "Regenerative Limit: " + String(regenerative_limit) + "<br>";
    content += "Discharge Limit: " + String(discharge_limit) + "<br>";
    content += "Max Heat Park: " + String(max_heat_park) + "<br>";
    content += "HVAC Max Power: " + String(hvac_max_power) + "<br>";
    content += "Max Discharge Current: " + String(max_discharge_current) + "<br>";
    content += "Max Charge Current: " + String(max_charge_current) + "<br>";
    content += "BMS Max Voltage: " + String(bms_max_voltage) + "<br>";
    content += "BMS Min Voltage: " + String(bms_min_voltage) + "<br>";
    content += "High Voltage: " + String(high_voltage) + "<br>";
    content += "Low Voltage: " + String(low_voltage) + "<br>";
    content += "Output Current: " + String(output_current) + "<br>";
    content += "SOC Min: " + String(soc_min) + "<br>";
    content += "SOC Max: " + String(soc_max) + "<br>";
    content += "SOC VI: " + String(soc_vi) + "<br>";
    content += "SOC Ave: " + String(soc_ave) + "<br>";
    content += "Cell Max V: " + String(cell_max_v) + "<br>";
    content += "Cell Min V: " + String(cell_min_v) + "<br>";
    content += "Cell Deviation mV: " + String(cell_deviation_mV) + "<br>";
    content += "Max VNO: " + String(max_vno) + "<br>";
    content += "Min VNO: " + String(min_vno) + "<br>";
    content += "Contactor: " + String(contactor) + "<br>";
    content += "HVIL Status: " + String(hvil_status) + "<br>";
    content += "Pack Cont Negative State: " + String(packContNegativeState) + "<br>";
    content += "Pack Cont Positive State: " + String(packContPositiveState) + "<br>";
    content += "Pack Contactor Set State: " + String(packContactorSetState) + "<br>";
    content += "Pack Ctrs Closing Allowed: " + String(packCtrsClosingAllowed) + "<br>";
    content += "Pyro Test In Progress: " + String(pyroTestInProgress) + "<br>";
    content += "Send 221 Still: " + String(send221still) + "<br>";
    content += "forceOpenContactors: " + String(forceOpenContactors) + "<br>";
    content += "</div>";

    // Close the block
    content += "</div>";

    content += "<button onclick='goToMainPage()'>Back to main page</button>";
    content += "<button onclick='forceOpenContactors()'>Force Open Contactors</button>";
    content += "<button onclick='clearCellFaults()'>Clear Cell Faults</button>";
    content += "<script>";
    content += "function goToMainPage() { window.location.href = '/'; }";
    content += "function clearCellFaults() {";
    content += "  var xhr = new XMLHttpRequest();";
    content += "  xhr.open('GET', '/tesla_clearcellfaults', true);";
    content += "  xhr.send();";
    content += "}";
    content += "function forceOpenContactors() {";
    content += "var value = prompt('Force Open Contactors? (0 = No, 1 = Yes):');";
    content += "if (value !== null) {";
    content += "  if (value == 0 || value == 1) {";
    content += "    var xhr = new XMLHttpRequest();";
    content += "    xhr.open('GET', '/tesla_updateForceOpenContactors?value=' + value, true);";
    content += "    xhr.send();";
    content += "  } else {";
    content += "    alert('Invalid value. Please enter a value between 0 and 1.');";
    content += "  }";
    content += "}";
    content += "}";
    content += "</script>";
    return content;
  }
  return String();
}
