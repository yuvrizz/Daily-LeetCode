/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    
    let n = arr.length; 
    const newArr = new Array(n).fill(0);

    for(let i = 0; i < arr.length; i++) {
        newArr[i] = fn(arr[i],i);
    }

    return newArr;
};