#include <time.h>
#include "BankSimulator.h"

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    BankSimulator sim;
    sim.readSimulationParameters();
    sim.run();
    sim.printStat();
}
