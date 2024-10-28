#include "Scale.h"
#include <HX711.h>
#include "soc/rtc.h"

Scale::Scale(int doutPin, int sckPin)
        : LOADCELL_DOUT_PIN(doutPin), 
          LOADCELL_SCK_PIN(sckPin)
{
    // HX711 circuit wiring
    rtc_cpu_freq_config_t config;
    rtc_clk_cpu_freq_get_config(&config);
    rtc_clk_cpu_freq_to_config(RTC_CPU_FREQ_80M, &config);
    rtc_clk_cpu_freq_set_config_fast(&config);
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

bool Scale::is_ready()
{
    return scale.is_ready();
}