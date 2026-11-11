#include <Arduino.h>

typedef struct  {
    int CLCK_PIN;

    int MOSI_PIN;
    int MISO_PIN;

    bool cpol; //FALSE: CLOCK DEFAULTS LOW, TRUE: CLOCK DEFAULTS HIGH
    bool cpha; //FALSE: SAMPLE ON RISING EDGE, TRUE: SAMPLE ON FALLING EDGE
} spi_master_t;

typedef struct {

    spi_master_t* master;
    int CS_IN; //CHIP SELECT PIN ON SELF
    int CS_OUT; //CHIP SELECT PIN ON MASTER

    int CLCK_PIN;

    int MOSI_PIN;
    int MISO_PIN;
} spi_slave_t;

void init_master(spi_master_t* m, int _CLCK_PIN, int _MOSI_PIN, int _MISO_PIN, bool _cpol = false, bool _cpha = false ){
    m->CLCK_PIN = _CLCK_PIN;
    m->MOSI_PIN = _MOSI_PIN;
    m->MISO_PIN = _MISO_PIN;

    m->cpol = _cpol;
    m->cpha = _cpha;

    pinMode(m->CLCK_PIN, OUTPUT);
    pinMode(m->MOSI_PIN, OUTPUT);
    pinMode(m->MISO_PIN, INPUT);
}