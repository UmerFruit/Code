#include "Headers.h"
#include <pthread.h>
#include <semaphore.h>
#include <random>
#include <algorithm>
void shuff(vector<int> &turn)
{
    mt19937 g((random_device())());
    shuffle(turn.begin(), turn.end(), g); // generate random order for turns again
}

int main()
{
    ifstream fin("network.csv");
}