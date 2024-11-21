// function satu() {
//     console.log("hallo saya satu");
// }

// function dua() {
//     console.log("saya dua");
// }

// function tiga() {
//     console.log("saya tiga");
// }

// function empat() {
//     console.log("saya empat");
// }
const delay = (ms) => {
    return new Promise(resolve => setTimeout(resolve, ms));
}

const satuedit = async (callback) => {
    console.log("hallo saya satu edit");
    await delay(3000);
    callback();
}

const duaedit = async (callback) => {
    console.log("hallo saya dua edit");
    await delay(2000);
    callback();
}

const tigaedit = (callback) => {
    console.log("hallo saya tiga edit");
    callback();
}


const empatedit = () => {
    console.log("hallo saya empat edit");
}



// satuedit(duaedit);
// // duaedit();
// tigaedit();
// empatedit();

satuedit(() =>{
    duaedit(() => {
        tigaedit(() =>{
            empatedit();
        });
    });
});