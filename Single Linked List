#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    float data;
    node *link;
};

node *head=NULL;

void menu();
void execute(int x);
void nodeData();
void display();
void modify(float x);
void insertFront();
void insertMid(int x);
void insertLast();
void delAllNode();
bool nodeFind(float x);
int menuChoice();


int main(){
    if(head==NULL){
        nodeData();
        system("cls");
    }
    menu();
    int choice;
    choice=menuChoice();
    execute(choice);
}

void menu(){
    cout << "1. Display" << endl;
    cout << "2. Find and Modify" << endl;
    cout << "3. Insert Front" << endl;
    cout << "4. Insert Middle" << endl;
    cout << "5. Insert Last" << endl;
    cout << "6. Delete All" << endl;
    cout << "Pilih menu: ";
}

int menuChoice(){
    int num;
    cin >> num;
    return num;
}

void execute(int x){
    switch(x){
        case 1:
            display();
            system("pause");
            system("cls");
            main();
            break;
        case 2:
            float dataFind;
            cout << "Data yang ingin dicari: "; cin >> dataFind;
            if(nodeFind(dataFind)){
                char mod;
                cout << "Modify? (Y/N)" << endl;
                cin >> mod;
                if(mod=='y' || mod=='Y'){
                    modify(dataFind);
                }
            }
            system("pause");
            system("cls");
            main();
            break;
        case 3:
            insertFront();
            system("pause");
            system("cls");
            main();
            break;
        case 4:
            cout << "This Option Hasn't Done Yet" << endl;
            /*int index;
            display();
            cout << "Input data setelah data ke-"; cin >> index;
            insertMid(index);*/
            system("pause");
            system("cls");
            main();
            break;
        case 5:
            insertLast();
            system("pause");
            system("cls");
            main();
            break;
        case 6:
            delAllNode();
            system("pause");
            system("cls");
            main();
            break;
    }
}

void nodeData(){
    float nodeData;
    char decide;

    do{
        cout << "Masukkan Data: "; cin >> nodeData;
        //Mengalokasikan memori untuk node baru
        node *ptr = new node;

        //Menginput data ke dalam node
        ptr->data=nodeData;
        ptr->link=NULL;
        if(head==NULL){
            head=ptr;
        }
        //Insert Last
        else{
            node *temp = head;
            while(temp->link != NULL){
                temp=temp->link;
            }
            temp->link=ptr;
        }

        cout << "Input? (Y/N) ";
        cin >> decide;
    }while(decide=='y' || decide=='Y');
}

void display(){
    node *temp=head;

    cout << "Data yang tersimpan:" << endl;
    while(temp!=NULL){
        cout << temp->data;
        temp=temp->link;
        if(temp!=NULL){
            cout << " >> ";
        }
    }
    cout << endl;
}

void modify(float x){
    node *temp=head;
    float dataNew;

    while(temp!=NULL){
        if(temp->data == x){
            cout << "Masukkan Data Baru: "; cin >> dataNew;
            temp->data = dataNew;
        }
        temp=temp->link;
    }
    display();
}

void insertFront(){
    float data;
    char choice;

    do{
        cout << "Masukkan Data: "; cin >> data;
        node *ptr = new node;

        ptr->data=data;
        ptr->link=head;
        head=ptr;

        cout << "Input? (Y/N) "; cin >> choice;
    }while(choice=='y' || choice=='Y');
}

void insertMid(int x){
    float data;
    char choice;

    node *temp=head;

    for(int i=0; i<x; i++){
        temp=temp->link;
        if(i==1){
            do{
                cout << "Masukkan Data: "; cin >> data;
                node *ptr=new node;

                ptr->data=data;
                ptr->link=temp;

                temp->link=ptr;

                cout << "Input? (Y/N) "; cin >> choice;
            }while(choice=='y' || choice=='Y');
        }
    }
}

void insertLast(){
    float data;
    char decide;

    do{
        cout << "Masukkan Data: "; cin >> data;

        node *ptr = new node;

        ptr->data=data;
        ptr->link=NULL;

        node *temp=head;
        while(temp->link != NULL){
            temp=temp->link;
        }
        temp->link=ptr;

        cout << "Input? (Y/N) "; cin >> decide;
    }while(decide == 'y' || decide == 'Y');
}

void delAllNode(){
    while(head!=NULL){
        free(head);
        head=head->link;
    }
}

bool nodeFind(float x){
    node *temp=head;

    while(temp!=NULL){
        if(temp->data == x){
            cout << "Data ditemukan" << endl;
            return 1;
        }
        temp=temp->link;
    }
    cout << "Data tidak ditemukan" << endl;
    return 0;
}
