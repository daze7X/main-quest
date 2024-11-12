def tambah(tipedata, *args):
    if tipedata == 'int':
        jawab = 0
    elif tipedata == 'str':
        jawab = ""
    else:
        print("Tipe data tidak dikenali")
        return

    for x in args:
        jawab = jawab + x

    print(jawab)


tambah('int', 5, 6)        
tambah('str', 'ini', ' overloading') 
