/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    let len = functions.length;

    return function(x) {
        
        let ans = x; 

        for(let i=len-1; i>=0; i--){
            let curr = functions[i];
            ans = curr(ans);
        }

        return ans;
    }

};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */