#include <iostream>

using namespace std;

struct Buku{
 string judul,penulis;
 int tahunterbit;

 Buku *next;
 
};

Buku *kepala, *ekor, *cur, *nodeBaru, *del;

void membuatsingglelinkedlist(string judul, string penulis, int tB){
    kepala = new Buku;
    kepala ->judul = judul;
    kepala ->penulis = penulis;
    kepala ->tahunterbit = tB;
    kepala ->next = NULL;
    ekor = kepala;
};

void tambahnodepertama(string judul, string penulis, int tB){
    nodeBaru = new Buku;
    nodeBaru ->judul = judul;
    nodeBaru ->penulis = penulis;
    nodeBaru ->tahunterbit = tB;
    nodeBaru ->next = kepala;
    kepala = nodeBaru;
};

void tambahnodeterakhir(string judul, string penulis, int tB){
    nodeBaru = new Buku;
    nodeBaru ->judul = judul;
    nodeBaru ->penulis = penulis;
    nodeBaru ->tahunterbit = tB;
    nodeBaru ->next = NULL;
    ekor ->next = nodeBaru;
    ekor = nodeBaru;
};

//hapus node pertama
void hapuspertama(){

    del = kepala;
    kepala = kepala ->next;
    delete del;
}

//hapus node akhir
void hapusakhir(){
    del = ekor;
    cur = kepala;
    while (cur ->next != ekor){
        cur = cur ->next;
    }
    {
        ekor = cur;
        ekor -> next = NULL;
        delete del;
    }
    

}

void ubahawal(string judul, string penulis, int tB){
   kepala ->judul = judul;
   kepala ->penulis = penulis;
   kepala ->tahunterbit = tB;
};

void ubahakhir(string judul, string penulis, int tB){
   ekor ->judul = judul;
   ekor ->penulis = penulis;
   ekor ->tahunterbit = tB;
};

void mencetaksingglelinkedlist(){
    cur = kepala;
while( cur != NULL){
    cout << "judul buku : " << cur -> judul << endl;
    cout << "penulis buku : " << cur -> penulis << endl;
    cout << "tahun terbit buku : " << cur -> tahunterbit << endl;

    cur = cur -> next;
}


}

int main(){

membuatsingglelinkedlist("PEMPEK PAlEMBANG", "suratman", 2000);
mencetaksingglelinkedlist();

cout << "\n\n" <<endl;

tambahnodepertama("KAPAL SELAM", "harry", 2020);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

tambahnodeterakhir("merakit PC", "Alexander", 2018);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

tambahnodeterakhir("berbisnis", "jobathan", 2020);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

hapuspertama();
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

hapusakhir();
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

ubahawal("satu hati", "buku saku", 2000);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;




























// Buku *node1, *node2, *node3;

// //node1 = (Buku*)malloc(sizeof(Buku)); cara 1
// node1 = new Buku;//cara 2
// node2 = new Buku;//cara 2
// node3 = new Buku;//cara 2

// //pengisiasn node -------------
// node1 ->judul = "dongeng sikancil";
// node1 ->penulis = "tuan kancil";
// node1 ->tahunterbit = 2005;
// node1 ->next = node2;

// node2 ->judul = "bercocok tanam";
// node2 ->penulis = "Petani";
// node2 ->tahunterbit = 2007;
// node2 ->next = node3;

// node3 ->judul = "masak-masak";
// node3 ->penulis = "wr makan";
// node3 ->tahunterbit = 2010;
// node3 ->next = NULL;
// //------------------------------------//

// Buku *cur;
// cur = node1;
// while( cur != NULL){
//     cout << "judul buku : " << cur -> judul << endl;
//     cout << "penulis buku : " << cur -> penulis << endl;
//     cout << "tahun terbit buku : " << cur -> tahunterbit << endl;

//     cur = cur -> next;
// }


};