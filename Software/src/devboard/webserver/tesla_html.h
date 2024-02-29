#ifndef TESLA_HTML_H
#define TESLA_HTML_H

#include <Arduino.h>
#include <stdint.h>

/**
 * @brief Replaces placeholder with content section in web page
 *
 * @param[in] var
 *
 * @return String
 */
String tesla_processor(const String& var);

void force_open_contactors(const uint8_t value);

void clear_cell_faults();

#endif
