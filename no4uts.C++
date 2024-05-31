#include <iostream>
using namespace std;

struct InventarisB{
  string barang, kategori;
  int jumlahbarang;
  InventarisB* prev;
  InventarisB* next;
};

InventarisB *kepala, *ekor, *cur, *newNode, *del, *afternode;

void buatDoubleLinkedList(string data[3], int jumlahBarang){
  kepala = new InventarisB();
  kepala->barang = data[0];
  kepala->kategori = data[1];
  kepala->jumlahbarang = jumlahBarang;
  kepala->prev = NULL;
  kepala->next = NULL;
  ekor = kepala;
}

int hitungDoubleLinkedList(){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
    return 0;
  } else {
    cur = kepala;
    int jumlah = 0;
    while (cur != NULL){
      jumlah++;
      cur = cur->next;
    }
    return jumlah;
  }
}

void tambahawal(string data[3], int jumlahBarang){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!" << endl;
  } else {
    newNode = new InventarisB();
    newNode->barang = data[0];
    newNode->kategori = data[1];
    newNode->jumlahbarang = jumlahBarang;
    newNode->prev = NULL;
    newNode->next = kepala;
    kepala->prev = newNode;
    kepala = newNode;
  }
}

void tambahakhir(string data[3], int jumlahBarang){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    newNode = new InventarisB();
    newNode->barang = data[0];
    newNode->kategori = data[1];
    newNode->jumlahbarang = jumlahBarang;
    newNode->prev = ekor;
    newNode->next = NULL;
    ekor->next = newNode;
    ekor = newNode;
  }
}

void tambahtengah(string data[3], int posisi, int jumlahBarang){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    if (posisi == 1){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    } else if (posisi < 1 || posisi > hitungDoubleLinkedList()){
      cout << "Posisi diluar jangkauan!!!" << endl;
    } else {
      newNode = new InventarisB();
      newNode->barang = data[0];
      newNode->kategori = data[1];
      newNode->jumlahbarang = jumlahBarang;
      cur = kepala;
      int nomor = 1;
      while (nomor < posisi - 1){
        cur = cur->next;
        nomor++;
      }
      afternode = cur->next;
      newNode->prev = cur;
      newNode->next = afternode;
      cur->next = newNode;
      if (afternode != NULL)
        afternode->prev = newNode;
    }
  }
}

void hapusawal(){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    del = kepala;
    kepala = kepala->next;
    if (kepala != NULL)
      kepala->prev = NULL;
    else
      ekor = NULL;
    delete del;
  }
}

void hapusakhir(){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    del = ekor;
    ekor = ekor->prev;
    if (ekor != NULL)
      ekor->next = NULL;
    else
      kepala = NULL;
    delete del;
  }
}

void hapusMiddle(int posisi){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    if (posisi <= 1 || posisi >= hitungDoubleLinkedList()){
      cout << "Posisi bukan posisi tengah!!" << endl;
    } else {
      cur = kepala;
      for (int i = 1; i < posisi; i++){
        cur = cur->next;
      }
      del = cur;
      cur->prev->next = cur->next;
      if (cur->next != NULL)
        cur->next->prev = cur->prev;
      delete del;
    }
  }
}

void cetakDoubleLinkedList(){
  if (kepala == NULL){
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    cout << "|jumlah data  : |" << hitungDoubleLinkedList() << endl;
    cout << "|data barang : |\n-------------------------------------------------------\n" << endl;
    cur = kepala;
    while (cur != NULL){
      cout << "\nnama barang : " << cur->barang << endl;
      cout << "kategori barang : " << cur->kategori << endl;
      cout << "jumlah barang : " << cur->jumlahbarang << endl;
      cur = cur->next;
    }
  }
}

int main() {
    string newdata[3] = {"oreo", "snack"};
    buatDoubleLinkedList(newdata, 12);
    cetakDoubleLinkedList();
    cout << "\n\n" << endl;

    string data2[3] = {"sekop", "alat pertanian"};
    tambahawal(data2, 15);
    cetakDoubleLinkedList();
    cout << "\n\n" << endl;

    string data3[3] = {"set meja kursi", "prabotan"};
    tambahakhir(data3, 20);
    cetakDoubleLinkedList();
    cout << "\n\n" << endl;

    string data4[3] = {"stop kontak", "kelistrikan"};
    tambahtengah(data4, 3, 15);
    cetakDoubleLinkedList();

    hapusawal();
    cout << "\n\nSetelah menghapus node awal:" << endl;
    cetakDoubleLinkedList();

    hapusMiddle(2);
    cout << "\n\nSetelah menghapus node tengah:" << endl;
    cetakDoubleLinkedList();

    hapusakhir();
    cout << "\n\nSetelah menghapus node akhir:" << endl;
    cetakDoubleLinkedList();
}
