#include <stdio.h>

void f(int u, int c, int r, int s, int p, int t) {
    if (u <= 0) {
        printf("Planet %d: Fuel Remaining = %d litres\n", p, 0);
        printf("Journey Failed: Fuel exhausted.\n");
        return;
    }
    
    if (p > t) {
        printf("Journey Complete: All planets visited.\n");
        return;
    }

    int next_u = u - c;

    if (p % 2 != 0) {
        next_u += r;
    }

    if (p % 4 == 0) {
        next_u += s;
    }
    
    printf("Planet %d: Fuel Remaining = %d\n", p, next_u);

    if (next_u <= 0 && p < t) {
        printf("Journey Failed: Fuel exhausted.\n");
        return;
    }
    
    f(next_u, c, r, s, p + 1, t);
}

int main() {
    int start_fuel = 150;
    int consumption = 25;
    int recharge = 10;
    int solar_bonus = 30;
    int total_planets = 8;
    
    printf("--- Spacecraft Fuel Simulation ---\n");
    f(start_fuel, consumption, recharge, solar_bonus, 1, total_planets);
    
    return 0;
}
