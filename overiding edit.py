class Batu:
    def __init__(self, jenis=""):
        self._jenis = jenis
        print("cincin Batu dibuat.")

    def akik(self):
        print("Menggosok batu")

    # Getter
    def get_jenis(self):
        return self._jenis

    # Setter
    def set_jenis(self, jenis):
        self._jenis = jenis

    def __del__(self):
        print("cincin Batu dihapus.")


class Giok(Batu):
    def __init__(self, jenis=""):
        super().__init__(jenis)
        print("cincin Giok dibuat.")

    def akik(self):
        super().akik()
        print(f"Cincin batu akik {self.get_jenis()}")

    def __del__(self):
        print("cincin Giok dihapus.")
        super().__del__()


karang = Giok()  
karang.set_jenis("Giok")  # menggunakan setter
karang.akik() 

del karang  
