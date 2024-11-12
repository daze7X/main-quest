class Penambah:
    def __init__(self, tipedata):
        self.tipedata = tipedata
        if tipedata == 'int':
            self._jawab = 0
        elif tipedata == 'str':
            self._jawab = ""
        else:
            print("Tipe data tidak dikenali")
            self._jawab = None

    def tambah(self, *args):
        if self._jawab is None:
            print("Tipe data tidak valid.")
            return
        for x in args:
            self._jawab += x
        print(self._jawab)

    # Setter
    def set_jawab(self, value):
        self._jawab = value
    
    # Getter
    def get_jawab(self):
        return self._jawab

    # Destruktor
    def __del__(self):
        print("Objek Penambah dihancurkan.")

penambah_int = Penambah('int')
penambah_int.tambah(5, 6)  # Output: 11

penambah_str = Penambah('str')
penambah_str.tambah('ini', ' overloading')  # Output: ini overloading

# Menggunakan setter dan getter
penambah_int.set_jawab(100)
print(penambah_int.get_jawab())  # Output: 100

# Menghapus objek
del penambah_int
del penambah_str
