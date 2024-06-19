#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = nullptr;

bool apakahPenuh() {
    
    return false;
}

bool apakahKosong() {
    return top == nullptr;
}

void tambahItem(string data) { 
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void ambilItem() {
    if (apakahKosong()) {
        cout << "Rak barang kosong!" << endl;
    } else {
        Node* temp = top;
        cout << "Barang yang diambil: " << top->data << endl;
        top = top->next;
        delete temp;
    }
}

void ubahItem(string data, int posisi) {
    if (apakahKosong()) {
        cout << "Rak barang kosong!" << endl;
    } else {
        Node* current = top;
        for (int i = 0; i < posisi - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current != nullptr) {
            current->data = data;
            cout << "Barang di posisi " << posisi << " diubah menjadi " << data << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

void kosongkanRak() {
    while (!apakahKosong()) {
        ambilItem();
    }
    cout << "Rak barang sudah dikosongkan." << endl;
}

void cetakRak() { 
    if (apakahKosong()) {
        cout << "Rak barang kosong!" << endl;
    } else {
        cout << "Daftar barang di rak:" << endl;
        Node* current = top;
        while (current != nullptr) {
            cout << "- " << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    tambahItem("Buku");
    cetakRak();

    tambahItem("Pensil");
    tambahItem("Penghapus");
    tambahItem("Ballpoint");
    tambahItem("Krayon");
    cetakRak();

    tambahItem("air mineral");
    cetakRak();

    ambilItem();
    cetakRak();

    cout << "Apakah rak barang penuh? " << apakahPenuh() << endl;
    cout << "Apakah rak barang kosong? " << apakahKosong() << endl;

    ubahItem("tipe-X", 2);
    cetakRak();

    kosongkanRak();
    cout << "Apakah rak barang penuh? " << apakahPenuh() << endl;
    cout << "Apakah rak barang kosong? " << apakahKosong() << endl;
}

