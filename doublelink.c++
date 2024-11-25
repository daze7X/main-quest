#include <iostream>

using namespace std;

struct Datauser{
    string nama,  username, email, password;
    Datauser *prev;//sebelumnya
    Datauser *next;//selanjutnya
};

Datauser *kepala, *ekor, *cur, *newnode, *del;

//membuat double linked list
void doublelinkedlist( string data [4]){

    kepala = new Datauser();
    kepala -> nama = data[0];
    kepala -> username = data[1];
    kepala -> email = data[2];
    kepala -> password = data[3];
    kepala->prev = NULL;
    kepala->next = NULL;
    ekor = kepala;
}
//tambah awalan
void addfirst( string data[4]){
if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
        newnode = new Datauser();
        newnode -> nama = data[0];
        newnode -> username = data[1];
        newnode -> email = data[2];
        newnode -> password = data[3];
        newnode->prev = NULL;
        newnode->next = ekor; 
        kepala ->prev = newnode;
        kepala = newnode;
     }
}
//TAMBAH node diakhir
void addlast( string data[4]){
if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
        newnode = new Datauser();
        newnode -> nama = data[0];
        newnode -> username = data[1];
        newnode -> email = data[2];
        newnode -> password = data[3];
        newnode->prev = ekor;
        newnode->next = NULL; 
        ekor ->prev = newnode;
        ekor = newnode;
     }
}
//remove first
void removefirst(){
    if(kepala == NULL){
    cout << "double-link list belum dibuat";
    }else{
        del = kepala;
        kepala = kepala->next;
        kepala->prev = NULL;
        delete del;
    }
}
//remove last
void removelast(){
    if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
    del = ekor;
    ekor = ekor ->prev;
    ekor -> next = NULL;
    delete del;
    }
}
//cetak double linked list
void cetakdouble(){
if(kepala == NULL){
    cout << "double-link list belum dibuat";
}else{
    cout << "isi data : " << endl;
cur = kepala;
while (cur != NULL){
//print
            cout << "nama user : " << cur->nama << endl;
            cout << "username : " << cur->username <<endl;
            cout << "email user : " << cur->email << endl;
            cout << "password : " << cur->password << " \n"<< endl; 
            cur=cur->next;
        }
    }
}


int main(){
    string newData[4]= {"justin bin alex", "justin", 
    "justin@gmail.com","12345"};
    doublelinkedlist(newData);
    cetakdouble();

    string data2[4] = {"mushasi karim", "karim",
    "karim@gmal.com", "987654321"};
    addfirst( data2);
    cetakdouble();

    string data3[4] = {"diavolo", "diavolo",
    "volo@gmal.com", "123saja"};
    addlast( data3);
    cetakdouble();


    removefirst();
    cetakdouble();

    removelast();
    cetakdouble();


}