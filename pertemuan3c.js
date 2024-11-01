const delay = (ms) => {
    return new Promise(resolve => setTimeout(resolve, ms));
}

const satuedit = async () => {
    console.log("hallo saya satu edit");
    await delay(3000); 
}

const duaedit = async () => {
    console.log("hallo saya dua edit");
    await delay(2000); 
}

const tigaedit = () => {
    console.log("hallo saya tiga edit");
}

const empatedit = () => {
    console.log("hallo saya empat edit");
}


const main = async () => {
    await satuedit(); 
    await duaedit();  
    tigaedit();       
    empatedit();      
}


main();