/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let nums=[];
    for(let i=0; i<arr.length; i++) {
        let result=fn(arr[i],i);
        nums.push(result);
    }
    return nums;
};