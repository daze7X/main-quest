let array = [1, 56, 30, 12, 88]

function bubblesort(array){
    let length = array.length

    for(let i= 0; i< length; i++){
        for(let j= 0; j< length; j++){
            if(array[j] > array[j + 1]) {
                let temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp
            }
        }
        console.log('iteration ${i + 1}:', array)
    }
    return array
}

console.log(bubblesort(array))