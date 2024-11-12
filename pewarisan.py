class batu:
    jenis = ""

    def akik(self):
        print("batu gosok")

class giok(batu):
    def hijau(self):
        print("aku punya batu : ", self.jenis)

karang =  giok()

karang.jenis = "giok ungu"
karang.akik()

karang.hijau()