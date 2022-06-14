#include <iostream>
#include <string>

const uint COPPER_VALUE = 1;
const uint SILVER_VALUE = 10;
const uint ELECTRUM_VALUE = 50;
const uint GOLD_VALUE = 100;
const uint PLATNIUM_VALUE = 1000;

ulong calculate_value_in_cp(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp);
void print_currency_breakdown(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp, uint pm);

int main(int argc, char * argv[]) {
    ulong cp = 0;
    ulong sp = 0;
    ulong ep = 0;
    ulong gp = 0;
    ulong pp = 0;
    uint pm = 0;
    
    // Turn our argument array into C++ String objects
    std::string arguments[argc - 1];

    for (int i = 0; i < argc - 1; i++) {
        arguments[i] = argv[i + 1];
    }

    // Calculate value of all coins
    for (int i = 0; i < argc - 1; i++) {
        std::string unit_type = arguments[i].substr(arguments[i].length() - 2);

        if (unit_type == "cp" || unit_type == "CP") { cp += stoi(arguments[i]); }
        else if (unit_type == "sp" || unit_type == "SP") { sp += std::stoi(arguments[i]); }
        else if (unit_type == "ep" || unit_type == "EP") { ep += std::stoi(arguments[i]); }
        else if (unit_type == "gp" || unit_type == "GP") { gp += std::stoi(arguments[i]); }
        else if (unit_type == "pp" || unit_type == "PP") { pp += std::stoi(arguments[i]); }
        else if (unit_type == "pm" || unit_type == "PM") { pm += std::stoi(arguments[i]); }

        else {
            printf("%s: Invalid unit type.\n", arguments[i].c_str());
            printf("Valid unit types:\n");
            printf("    CP (copper pieces)\n");
            printf("    SP (silver pieces)\n");
            printf("    EP (electrum pieces)\n");
            printf("    GP (gold pieces)\n");
            printf("    PP (platnium pieces)\n");
            
            return 1;
        }
    }

    print_currency_breakdown(cp, sp, ep, gp, pp, pm);
    
    return 0;
}

ulong calculate_value_in_cp(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp) {
    return cp * COPPER_VALUE + sp * SILVER_VALUE + ep * ELECTRUM_VALUE + gp * GOLD_VALUE + pp * PLATNIUM_VALUE;
}

void print_currency_breakdown(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp, uint pm) {
    ulong total_value = calculate_value_in_cp(cp, sp, ep, gp, pp);
    if (pm < 1) { pm = 1; }

    if (cp > 0) {
        printf("Copper pieces:\t\t%lu (%.2f gold pieces)\n", cp, cp * (COPPER_VALUE / (float)GOLD_VALUE));
    }

    if (sp > 0) {
        printf("Silver pieces:\t\t%lu (%.2f gold pieces)\n", sp, sp * (SILVER_VALUE / (float)GOLD_VALUE));
    }

    if (ep > 0) {
        printf("Electrum pieces:\t%lu (%.2f gold pieces)\n", ep, ep * (ELECTRUM_VALUE / (float)GOLD_VALUE));
    }

    if (gp > 0) {
        printf("Gold pieces:\t\t%lu\n", gp);
    }

    if (pp > 0) {
        printf("Platnium pieces:\t%lu (%.2f gold pieces)\n", pp, pp * (PLATNIUM_VALUE / (float)GOLD_VALUE));
    }
    
    printf("Total value:\t\t%.2f gold pieces ", total_value / (float)GOLD_VALUE);

    if (pm > 1) {
        printf("(%.2f gold pieces per party member)", (total_value / (float)GOLD_VALUE) / (float)pm);
    }

    printf("\n");
}
