#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long int ulong;

const unsigned int COPPER_VALUE = 1;
const unsigned int SILVER_VALUE = 10;
const unsigned int ELECTRUM_VALUE = 50;
const unsigned int GOLD_VALUE = 100;
const unsigned int PLATNIUM_VALUE = 1000;

ulong calculate_value_in_cp(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp);
void print_currency_breakdown(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp, unsigned int pm);

int main(int argc, char * argv[]) {
    ulong cp = 0;
    ulong sp = 0;
    ulong ep = 0;
    ulong gp = 0;
    ulong pp = 0;
    unsigned int pm = 0;

    // Calculate value of all coins
    for (int i = 1; i < argc; i++) {
        char unit_type[] = "??";
        unit_type[0] = argv[i][strlen(argv[i]) - 2];
        unit_type[1] = argv[i][strlen(argv[i]) - 1];
        printf("%s\n", unit_type);

        if (strcmp(unit_type, "cp") == 0 || strcmp(unit_type, "CP") == 0) { cp += strtoul(argv[i], NULL, 10); }
        else if (strcmp(unit_type, "sp") == 0 || strcmp(unit_type, "SP") == 0) { sp += strtoul(argv[i], NULL, 10); }
        else if (strcmp(unit_type, "ep") == 0 || strcmp(unit_type, "EP") == 0) { ep += strtoul(argv[i], NULL, 10); }
        else if (strcmp(unit_type, "gp") == 0 || strcmp(unit_type, "GP") == 0) { cp += strtoul(argv[i], NULL, 10); }
        else if (strcmp(unit_type, "pp") == 0 || strcmp(unit_type, "PP") == 0) { cp += strtoul(argv[i], NULL, 10); }
        else if (strcmp(unit_type, "pm") == 0 || strcmp(unit_type, "PM") == 0) { cp += strtoul(argv[i], NULL, 10); }

        else {
            printf("%s: Invalid unit type.\n", argv[i]);
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

void print_currency_breakdown(ulong cp, ulong sp, ulong ep, ulong gp, ulong pp, unsigned int pm) {
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
