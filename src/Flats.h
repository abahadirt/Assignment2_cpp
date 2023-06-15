//
// Created by turha on 19.11.2022.
//

#ifndef ASSIGNMENT2_FLATS_H
#define ASSIGNMENT2_FLATS_H



class NodeFlat{
public:
    int id;
    int initialBandwidth;
    int isEmpty=1;
    NodeFlat* prev=nullptr;
    NodeFlat* next=nullptr;
};

class Flats {
public:
    NodeFlat* head=nullptr;
    void addFlat(int index, int initialBandwidth, int flatId,int maxBandwidth);
    void emptyFlat(int flatId);
//    void mergeApartmentsOfFlats(NodeApartment *aparment1,NodeApartment *aparment2);
};


#endif //ASSIGNMENT2_FLATS_H
