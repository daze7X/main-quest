#include <iostream>
using namespace std;

struct DataUser{
  string nama, username, email, password;
  DataUser *prev;
  DataUser *next;
};

DataUser *kepala, *ekor, *cur, *newNode, *del, *afterNode;

// membuat Double Linked List
void buatDoubleLinkedList( string data[4] ){
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->username = data[1];
  kepala->email = data[2];
  kepala->password = data[3];
  kepala->prev = NULL;
  kepala->next = NULL;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = kepala;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
   
      cur = cur->next;
    }
    return jumlah;
  }
}



// Add awal
void tambahawal( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!";
  }else{
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = NULL;
    newNode->next = kepala;
    kepala->prev = newNode;
    kepala = newNode;
  }
}

// Add akhir
void tambahakhir( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = ekor;
    newNode->next = NULL;
    ekor->next = newNode;
    ekor = newNode;
  }
}


// Add Middle
void tambahtengah( string data[4], int posisi ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!!" << endl;
    }else{
      newNode = new DataUser();
      newNode->nama = data[0];
      newNode->username = data[1];
      newNode->email = data[2];
      newNode->password = data[3];

      cur = kepala;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }

  }
}

// hapus awal
void hapusawal()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = kepala;
    kepala = kepala->next;
    kepala->prev = NULL;
    delete del;
  }
}

// hapus akhir
void hapusakhir()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = ekor;
    ekor = ekor->prev;
    ekor->next = NULL;
    delete del;
  }
}

// hapus Middle
void hapusMiddle(int posisi){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    if( posisi == 1 || posisi == hitungDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int nomor = 1;
      cur = kepala;
      while( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// mencetak
void cetakDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = kepala;
    while( cur != NULL ){
      // cetak
      cout << "Nama User : " << cur->nama << endl;
      cout << "Username User : " << cur->username << endl;
      cout << "Email User : " << cur->email << endl;
      cout << "Password User : " << cur->password << "\n" << endl;
      //step
      cur = cur->next;
    }
  }
}

int main(){

  string newData[4] = {"bambang gentolet", "bBm", "sitampan@gmail.com", "123Aja"};
  buatDoubleLinkedList(newData);
  cetakDoubleLinkedList();

  string data2[4] = {"tegoh ady", "ady", "adytampan@gmail.com", "723987"};
  tambahawal( data2 );
  cetakDoubleLinkedList();

  string data3[4] = {"mamat", "matmat", "mamat@gmail.com", "18274"};
  tambahakhir( data3 );
  cetakDoubleLinkedList();

  string data4[4] = {"supriadi", "supri", "supra@yahoo.com", "12314"};
  tambahtengah(data4, 3);
  cetakDoubleLinkedList();

  hapusMiddle(2);
  cetakDoubleLinkedList();


}