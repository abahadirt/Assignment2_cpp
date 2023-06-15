//
// Created by turha on 19.11.2022.
//
#include "Apartments.h"
#include "Reader.h"
using namespace std;

    void Reader::reader(string inputName,string outputName){
    ofstream outputFile;
    outputFile.open (outputName);
    Apartments *apartments = new Apartments();
    string myText;
    ifstream inputFile(inputName);
    while (getline (inputFile, myText)) {
        stringstream sstream;
        sstream<<myText;
        string toDo;
        sstream >>toDo;
        if(toDo=="add_apartment"){
            string apartmentName;
            string position;
            int maxBandwidth;
            sstream>>apartmentName;
            sstream>>position;
            sstream>>maxBandwidth;
            apartments->addApartment(apartmentName, position, maxBandwidth);
        }
        else if(toDo=="add_flat"){
            string apartmentName;
            int index;
            int initialBandwidth;
            int flatId;
            sstream>>apartmentName;
            sstream>>index;
            sstream>>initialBandwidth;
            sstream>>flatId;
            apartments->addFlatToApartment(apartmentName, index, initialBandwidth, flatId);

        }
        else if(toDo=="remove_apartment"){
            string apartmentName;
            sstream>>apartmentName;
            apartments->deleteApartment(apartmentName);

        }
        else if(toDo=="make_flat_empty"){
            string apartmentName;
            int flatId;
            sstream>>apartmentName;
            sstream>>flatId;
            apartments->emptyFlatOfApartment(apartmentName,flatId);
        }
        else if(toDo=="find_sum_of_max_bandwidths"){

            outputFile<<"sum of bandwidth: "<<apartments->sumOfMaxBandwidth()<<"\n\n";

        }
        else if(toDo=="merge_two_apartments"){
            string apartmentName1;
            string apartmentName2;
            sstream>>apartmentName1;
            sstream>>apartmentName2;
            apartments->mergeApartments(apartmentName1,apartmentName2);
        }
        else if(toDo=="list_apartments"){

            NodeApartment *temp;
            temp=apartments->head;
            NodeFlat *temp2;
            temp2=temp->flats->head;
            if(temp== nullptr){
                outputFile<<"NULL\n";
            }
            else{
                outputFile<<temp->name<<"("<<temp->maxBandwidth<<")\t";
                while(temp2!= nullptr){
                    outputFile<<"Flat"<<temp2->id<<"("<<temp2->initialBandwidth<<")\t";
                    temp2=temp2->next;
                }
                outputFile<<"\n";
                temp=temp->next;
                temp2=temp->flats->head;

                while(temp!= nullptr &&temp!=apartments->head){
                    outputFile<<temp->name<<"("<<temp->maxBandwidth<<")\t";
                    while(temp2!= nullptr){
                        outputFile<<"Flat"<<temp2->id<<"("<<temp2->initialBandwidth<<")\t";
                        temp2=temp2->next;
                    }
                    outputFile<<"\n";
                    temp=temp->next;
                    temp2=temp->flats->head;
                }


            }

            outputFile<<"\n";
        }





    }
    outputFile.close();
    inputFile.close();
}