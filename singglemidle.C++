#include <iostream>

using namespace std;

struct Buku{

  string judul, pengarang;
  int tahunTerbit;

  Buku *next;

};

Buku *kepala, *ekor, *cur, *newNode, *del, *sebelum;

// membuat single linked list
void buatSingleLinkedList(string judul, string pengarang, int tB){
  kepala = new Buku();
  kepala->judul = judul;
  kepala->pengarang = pengarang;
  kepala->tahunTerbit = tB;
  kepala->next = NULL;
  ekor = kepala;
}




//menampilkan
int hitungSingleLinkedList(){
  cur = kepala;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

// tambahAwal
void addFirst(string judul, string pengarang, int tB){
  newNode = new Buku();
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tB;
  newNode->next = kepala;
  kepala = newNode;
}

// tambahAkhir
void addLast(string judul, string pengarang, int tB){
  newNode = new Buku();
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tB;
  newNode->next = NULL;
  ekor->next = newNode;
  ekor = newNode;
}

// tambah tengah
void addMiddle(string judul, string pengarang, int tB, int posisi){
  if( posisi < 1 || posisi > hitungSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
//transfer
    cur = kepala;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
  }
}


// Remove First
void hapusawal(){
  del = kepala;
  kepala = kepala->next;
  delete del;
}

// Remove Last
void hapusakhir(){
  del = ekor;
  cur = kepala;
  while( cur->next != ekor ){
    cur = cur->next;
  }
  ekor = cur;
  ekor->next = NULL;
  delete del;
}

// hapus node tengah
void hapusmidle(int posisi){
  if( posisi < 1 || posisi > hitungSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    cur = kepala;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        sebelum = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    sebelum->next = cur;
    delete del;
  }
}

// ubahAwal Single linked list
void changeFirst(string judul, string pengarang, int tB){
  kepala->judul = judul;
  kepala->pengarang = pengarang;
  kepala->tahunTerbit = tB;
}

// ubahAkhir Single linked list
void changeLast(string judul, string pengarang, int tB){
  ekor->judul = judul;
  ekor->pengarang = pengarang;
  ekor->tahunTerbit = tB;
}

// ubah Tengah Single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi){
  if( posisi < 1 || posisi > hitungSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1 || posisi == hitungSingleLinkedList() ){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    cur = kepala;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
    }
    cur->judul = judul;
    cur->pengarang = pengarang;
    cur->tahunTerbit = tB;
  }
}





void printSingleLinkedList(){
  cout << "Jumlah data ada : " << hitungSingleLinkedList() << endl;
  cur = kepala;
  while( cur != NULL ){
    cout << "Judul Buku : " << cur->judul << endl;
    cout << "Pengarang Buku : " << cur->pengarang << endl;
    cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

    cur = cur->next;
  }
}

int main(){

  buatSingleLinkedList("bukan aku", "Gen z", 2010);

  printSingleLinkedList();

  cout << "\n\n" << endl;

  addFirst("cinta", "ngadiman", 2000);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addLast("bunga mawar", "bustam", 2020);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  hapusawal();

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addLast("sahabat hitam", "Fiersa", 2019);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  hapusakhir();

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  changeFirst("waktu itu", "budi", 2015);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addMiddle("kala sore", "bambang", 20015, 2);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addMiddle("daftar pustaka", "Afuad", 2019, 2);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  hapusmidle(5);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  changeMiddle("cara tidur", "makmur", 2045, 2);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

}