//
// Created by turha on 19.11.2022.
//
using namespace std;
#include <iostream>
#include "Apartments.h"




void Apartments::addApartment(string apartmentName, string position, int maxBandwidth){
    NodeApartment *nodeApartment = new NodeApartment();
    nodeApartment->name= apartmentName;
    nodeApartment->maxBandwidth= maxBandwidth;

    if(head== nullptr){                             //adding head
        head=nodeApartment;
        tail=nodeApartment;
        head->next=nodeApartment;

    }

    NodeApartment *temp=head;
    if(position[0] == 'a'){                         //checking for "after"
        while(temp!=nullptr){
            if(position[6]==temp->name[0]){
                nodeApartment->next=temp->next;
                temp->next=nodeApartment;
                if(temp->next==head){               //adding to tail
                    tail=nodeApartment;
                }
                break;
            }
            temp= temp->next;
        }
    }

    else if(position[0]=='b'){                      //checking for "before"
        if(position[7]==head->name[0]){             //adding behind the head

            tail->next=nodeApartment;
            nodeApartment->next=head;
            head=nodeApartment;

        }
        else{
            while(temp->next!=nullptr){
                if(position[7]==temp->next->name[0]){
                    nodeApartment->next=temp->next;
                    temp->next=nodeApartment;

                    break;
                }
                temp= temp->next;
            }
        }
    }




}



void Apartments::addFlatToApartment(string apartmentName, int index, int initialBandwidth, int flatId){
    NodeApartment *temp=head;
    while(temp!=nullptr){           //adding flats
        if(apartmentName[0]==temp->name[0]){
            temp->flats->addFlat(index, initialBandwidth, flatId,temp->maxBandwidth);
            break;
        }
        temp= temp->next;
    }

}

void Apartments::emptyFlatOfApartment(string apartmentName, int flatId){
    NodeApartment *temp=head;
    while(temp!=nullptr){
        if(apartmentName[0]==temp->name[0]){

            break;
        }
        temp= temp->next;
    }
    temp->flats->emptyFlat(flatId);
}

int Apartments::sumOfMaxBandwidth() {
    NodeApartment *temp=head;
    int bandWidth=0;
    if(head!= nullptr){
        bandWidth+=head->maxBandwidth;
        temp=head->next;
    }
    while(temp!=nullptr && temp!=head){
        bandWidth+=temp->maxBandwidth;
        temp= temp->next;
    }
    return bandWidth;
}

void Apartments::mergeApartments(string apartmentName1, string apartmentName2){
    NodeApartment *temp1=head;
    while(temp1!=nullptr){
        if(apartmentName1[0]==temp1->name[0]){
            break;
        }
        temp1= temp1->next;
    }
    NodeApartment *temp2=head;
    while(temp2!=nullptr){
        if(apartmentName2[0]==temp2->name[0]){
            break;
        }
        temp2= temp2->next;
    }

    NodeFlat * lastNode = temp1->flats->head;
    while(lastNode->next!=nullptr){
        lastNode=lastNode->next;
    }
    if(lastNode!=nullptr){
        lastNode->next= temp2->flats->head;

    }
    else{
        temp1->flats->head=temp2->flats->head;

    }
    if(temp2->flats->head!=nullptr){
        temp2->flats->head->prev=lastNode;

    }
    else{}
    temp1->maxBandwidth = temp1->maxBandwidth + temp2->maxBandwidth;
    temp2->flats->head=nullptr;       //this is for breaking the link. deleting will be in below
    deleteApartment(apartmentName2);


}

void Apartments::deleteApartment(string apartmentName){ //this function has some boring dynamic memory method patterns.
    NodeApartment *temp=head;
    while(temp!=nullptr){
        if(apartmentName[0]==temp->name[0]){
            break;
        }
        temp= temp->next;
    }

    NodeFlat *temp2= temp->flats->head;
    NodeFlat *temp3;
    while(temp2!=nullptr){
        temp2=temp3;
        temp2=temp2->next;
        delete temp3;

    }

    NodeApartment *temp4=head;
    while(temp4!=temp){
        if(temp->name[0]==temp4->next->name[0]){
            break;
        }
        temp4= temp4->next;
    }
    temp4->next=temp->next;


    if(temp==head){
        head=temp->next;
    }
    else if(temp==tail){
        tail=temp4;
    }


    delete temp;

}



