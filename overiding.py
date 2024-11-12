class batu:
    jenis = " "

    def akik(self):
        print("menggosok")

class giok(batu):
    def akik(self):

        super().akik()
        print("cincin batu akik ", self.jenis)
 
karang = giok()

karang.akik()