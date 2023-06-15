//
// Created by turha on 19.11.2022.
//
#include <iostream>
using namespace std;


#include "Flats.h"


void Flats::addFlat(int index, int initialBandwidth, int flatId,int maxBandwidth){ //this function add flats as it is

    NodeFlat *nodeFlat = new NodeFlat();
    nodeFlat->id=flatId;
    nodeFlat->initialBandwidth=initialBandwidth;
    nodeFlat->isEmpty=0;
    if(head== nullptr){
        head=nodeFlat;
    }
    else if(head!= nullptr && index==0){
        nodeFlat->next=head;
        head->prev=nodeFlat;
        head=nodeFlat;
    }
    else{
        NodeFlat *temp=head;
        int tempcount=1;   //temp is prev node of changing node of change index
        while(tempcount!=index){
            tempcount++;
            temp= temp->next;

        }
        if(temp->next!= nullptr){
            temp->next->prev=nodeFlat;
            nodeFlat->next=temp->next;
            temp->next= nodeFlat;
            nodeFlat->prev=temp;

        }
        else{
            nodeFlat->prev=temp;
            temp->next=nodeFlat;

        }
    }


    NodeFlat *temp2=head;
    int totalBandwidth=0;
    while(temp2!=nullptr){
        totalBandwidth+=temp2->initialBandwidth;
        temp2=temp2->next;
    }
    if(totalBandwidth>maxBandwidth){
        nodeFlat->initialBandwidth=maxBandwidth-(totalBandwidth-nodeFlat->initialBandwidth);
        if(nodeFlat->initialBandwidth==0){
            nodeFlat->isEmpty=0;
        }
    }

}

void Flats::emptyFlat(int flatId){
    NodeFlat *temp=head;
    while(temp!=nullptr){
        if(flatId==temp->id){
            temp->initialBandwidth=0;
            temp->isEmpty=1;
            break;
        }
        temp= temp->next;
    }
}

