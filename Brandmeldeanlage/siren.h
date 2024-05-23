
#ifndef BRANDMELDEANLAGE_SIREN_H
#define BRANDMELDEANLAGE_SIREN_H

class Siren {

public:

    //Destruktor
    virtual ~Siren() {}

    virtual void switchOn();

    virtual void switchOff();

};

#endif //BRANDMELDEANLAGE_SIREN_H
