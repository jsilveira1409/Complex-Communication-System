#include "Constants.h"

void setup() {
    Serial1.begin(9600);
}

void loop() {
    Serial1.write(NOP);
    delay(10000);
    Serial1.write(FWD);
    delay(10000);
}
