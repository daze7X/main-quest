#include <iostream>
using namespace std;

struct InventarisB {
    string barang, kategori;
    int jumlahbarang;
    InventarisB* next;
};

InventarisB* kepala, * ekor, * newNode, * cur, * del;

void buatCircularLinkedList(string data[3], int jumlahBarang) {
    kepala = new InventarisB();
    kepala->barang = data[0];
    kepala->kategori = data[1];
    kepala->jumlahbarang = jumlahBarang;
    kepala->next = kepala;
    ekor = kepala;
}

int hitungCircularLinkedList() {
    if (kepala == NULL) {
        cout << "Circular Linked List belum dibuat!!!" << endl;
        return 0;
    } else {
        cur = kepala;
        int jumlah = 0;
        do {
            jumlah++;
            cur = cur->next;
        } while (cur != kepala);
        return jumlah;
    }
}

void tambahawal(string data[3], int jumlahBarang) {
    if (kepala == NULL) {
        cout << "Circular Linked List belum dibuat!" << endl;
    } else {
        newNode = new InventarisB();
        newNode->barang = data[0];
        newNode->kategori = data[1];
        newNode->jumlahbarang = jumlahBarang;
        newNode->next = kepala;
        ekor->next = newNode;
        kepala = newNode;
    }
}

void tambahakhir(string data[3], int jumlahBarang) {
    if (kepala == NULL) {
        cout << "Circular Linked List belum dibuat!!!" << endl;
    } else {
        newNode = new InventarisB();
        newNode->barang = data[0];
        newNode->kategori = data[1];
        newNode->jumlahbarang = jumlahBarang;
        newNode->next = kepala;
        ekor->next = newNode;
        ekor = newNode;
    }
}

void tambahtengah(string data[3], int posisi, int jumlahBarang) {
    if (kepala == NULL) {
        cout << "Circular Linked List belum dibuat!!!" << endl;
    } else {
        int jumlahNode = hitungCircularLinkedList();
        if (posisi <= 1 || posisi > jumlahNode + 1) {
            cout << "Posisi tidak valid!" << endl;
        } else {
            newNode = new InventarisB();
            newNode->barang = data[0];
            newNode->kategori = data[1];
            newNode->jumlahbarang = jumlahBarang;

            cur = kepala;
            for (int i = 1; i < posisi - 1; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;

            if (posisi == jumlahNode + 1) {
                ekor = newNode;
            }
        }
    }
}




void cetakCircularLinkedList() {
    if (kepala == NULL) {
        cout << "Circular Linked List belum dibuat!!!" << endl;
    } else {
        cout << "|jumlah data  : |" << hitungCircularLinkedList() << endl;
        cout << "|data barang : |" << "\n-------------------------------------------------------\n" << endl;
        cur = kepala;
        do {
            cout << "\nnama barang : " << cur->barang << endl;
            cout << "kategori barang : " << cur->kategori << endl;
            cout << "jumlah barang : " << cur->jumlahbarang << endl;
            cur = cur->next;
        } while (cur != kepala);
    }
}

int main() {
    string newdata[3] = { "oreo", "snack" };
    buatCircularLinkedList(newdata, 12);
    cetakCircularLinkedList();
    cout << "\n\n" << endl;

    string data2[3] = { "sekop", "alat pertanian" };
    tambahawal(data2, 15);
    cetakCircularLinkedList();
    cout << "\n\n" << endl;

    string data3[3] = { "set meja kursi", "prabotan" };
    tambahakhir(data3, 20);
    cetakCircularLinkedList();
    cout << "\n\n" << endl;

    string data4[3] = { "stop kontak", "kelistrikan" };
    tambahtengah(data4, 3, 15);
    cetakCircularLinkedList();
    cout << "\n\n" << endl;

}
