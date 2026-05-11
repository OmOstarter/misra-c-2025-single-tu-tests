/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define Sum(x, y) ((x) + (y))
#define low_pressure_turbine_temperature_1 1

int main(void)
{
    int Sum = 2; /* Non-compliant */
    static int low_pressure_turbine_temperature_2; /* Non-compliant */
    return Sum + low_pressure_turbine_temperature_2;
}
