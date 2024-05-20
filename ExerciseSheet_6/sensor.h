
#ifndef EXERCISESHEET_6_SENSOR_H
#define EXERCISESHEET_6_SENSOR_H

class Sensor {

protected:
    bool errorState = false;

public:
    //Default Konstruktor
    Sensor() = default;

    //Destruktor für Polymorphismus als virtual kennzeichnen
    virtual ~Sensor();

    virtual bool getErrorState() const {
        return this->errorState;
    }

    //Virtual Reset - wird von Unterklassen definiert
    virtual void reset() = 0;

    virtual int checkSensor() = 0;

};

#endif //EXERCISESHEET_6_SENSOR_H
