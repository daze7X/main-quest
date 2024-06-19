#include <iostream>
#include <string>

using namespace std;

int maksimal = 10; // ukuran array sebagai variabel
string arrayRak[10]; // inisialisasi array dengan ukuran 10
int front = 0; // indeks depan saat ini dari queue
int rear = 0; // indeks belakang saat ini dari queue

bool apakahPenuh() {
    return (rear - front) == maksimal;
}

bool apakahKosong() {
    return front == rear;
}

void tambahItem(string data) { // fungsi untuk menambahkan item ke queue
    if (apakahPenuh()) {
        cout << "Rak barang penuh!" << endl;
    } else {
        arrayRak[rear % maksimal] = data;
        rear++;
    }
}

void ambilItem() {
    if (apakahKosong()) {
        cout << "Rak barang kosong!" << endl;
    } else {
        cout << "Barang yang diambil: " << arrayRak[front % maksimal] << endl;
        front++;
    }
}

void ubahItem(string data, int posisi) {
    if (apakahKosong()) {
        cout << "Rak barang kosong!" << endl;
    } else {
        int indeks = front + posisi - 1;
        if (indeks >= front && indeks < rear) {
            arrayRak[indeks % maksimal] = data;
            cout << "Barang di posisi " << posisi << " diubah menjadi " << data << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

void kosongkanRak() {
    front = 0;
    rear = 0;
    cout << "Rak barang sudah dikosongkan." << endl;
}

void cetakRak() { // fungsi untuk mencetak isi queue
    if (apakahKosong()) {
        cout << "Rak barang kosong!" << endl;
    } else {
        cout << "Daftar barang di rak:" << endl;
        for (int i = front; i < rear; i++) {
            cout << "- " << arrayRak[i % maksimal] << endl;
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
    cout << "Jumlah barang: " << (rear - front) << endl;

    ubahItem("tipe-X", 2);
    cetakRak();

    kosongkanRak();
    cout << "Apakah rak barang penuh? " << apakahPenuh() << endl;
    cout << "Apakah rak barang kosong? " << apakahKosong() << endl;
}
