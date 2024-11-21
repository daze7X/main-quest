function tambah(a,b) {
    return a + b;

}

function sapa() {
    console.log("hallo")
}

function hitungluas(panjang, lebar) {
    const luas = panjang * lebar;
    return luas;
}
const hitungluas2= (panjang,lebar) => {
    const luas = panjang * lebar;
    return luas;
} 



sapa();
console.log("hasil = " + tambah(70, 3));
console.log("luas = " + hitungluas(10, 2));
console.log("luas2 = " + hitungluas2(25, 3))