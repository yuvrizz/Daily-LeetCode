/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    
    var ans = new Array();

    for(let i=0; i<arr.length/size; i++){
        let temp = new Array();

        for(let j=i*size; j<(i+1)*size && j<arr.length; j++){
            temp.push(arr[j]);
        }
        
        ans[i] = temp;
    }

    return ans;
};
