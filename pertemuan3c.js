const delay = (ms) => {
    return new Promise(resolve => setTimeout(resolve, ms));
}

const satuedit = async () => {
    setTimeout(()=>console.log("hallo saya satu edit"), 3000);
 
}

const duaedit = async () => {
    setTimeout(()=>console.log("hallo saya dua edit"),2000);
     
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
