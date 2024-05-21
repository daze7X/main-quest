#include <iostream>

using namespace std;

struct Buku{
 string judul,penulis;
 int tahunterbit;

 Buku *next;
 
};

Buku *kepala, *ekor, *cur, *nodeBaru, *del, *sebelum;


void membuatsingglelinkedlist(string judul, string penulis, int tB){
    kepala = new Buku;
    kepala ->judul = judul;
    kepala ->penulis = penulis;
    kepala ->tahunterbit = tB;
    kepala ->next = NULL;
    ekor = kepala;
};
int hitungdata(){
    cur = kepala;
    int jumlah = 0;
    while( cur != NULL){
        jumlah++;
        cur = cur -> next;
}
    return jumlah;

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

//tambah node tengah
void tambahtengah(string judul, string penulis, int tB, int posisi){
    if( posisi < 1|| posisi >hitungdata()){
        cout <<"posisi diluar jangkauan" << endl;
    }else if( posisi == 1 || posisi == hitungdata()){
        cout << "posisi bukan di tengah" << endl;
    }else{
        nodeBaru = new Buku;
        nodeBaru ->judul = judul;
        nodeBaru ->penulis = penulis;
        nodeBaru ->tahunterbit = tB;
        
        //pemindahan
        cur = kepala;
        int nomor= 1;
        while( nomor  < posisi - 1){
            cur = cur ->next;
            nomor++;
        }

        nodeBaru->next = cur ->next;
        cur -> next = nodeBaru;
    }
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
//hapus midle
void hapusMiddle(int posisi){
    if( posisi < 1|| posisi >hitungdata()){
        cout <<"posisi diluar jangkauan" << endl;
    }else if( posisi == 1 || posisi == hitungdata()){
        cout << "posisi bukan di tengah" << endl;
    }else{int nomor = 1;
    cur = kepala;
    while( nomor <= posisi){
        if( nomor  == posisi){
            sebelum = cur;
        }
        if( nomor == posisi){
            del = cur;
        }
        cur = cur ->next;
        nomor++;
    }
    sebelum ->next= cur;
    delete del;
    }
    
};


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
    cout << " jumlah data : " << hitungdata() << endl;
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

tambahtengah("lemari usang", "parjo", 2010, 2);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

tambahtengah("Berlari", "paing", 2011, 3);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;

hapusMiddle(1);
mencetaksingglelinkedlist();
cout << "\n\n" <<endl;
};