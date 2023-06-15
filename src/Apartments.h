//
// Created by turha on 19.11.2022.
//

#ifndef ASSIGNMENT2_APARTMENTS_H
#define ASSIGNMENT2_APARTMENTS_H
#include "Flats.h"
using namespace std;
#include <string>

class NodeApartment{
public:
    string name;
    int maxBandwidth;
    NodeApartment* next= nullptr;
    Flats *flats= new Flats();
};
class Apartments {
public:
    NodeApartment* head= nullptr;
    NodeApartment* tail= nullptr;
    void addApartment(string apartmentName, string position, int maxBandwidth);
    void addFlatToApartment(string apartmentName, int index, int initialBandwidth, int flatId);
    void emptyFlatOfApartment(string apartmentName, int flatId);
    int sumOfMaxBandwidth();
    void mergeApartments(string apartmentName1, string apartmentName2);
    void deleteApartment(string apartmentName);
};



#endif //ASSIGNMENT2_APARTMENTS_H
