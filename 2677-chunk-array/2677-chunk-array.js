/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let ans2=[];
    for(let i=0; i<arr.length; i+=size) {
        let ans1=[];
        for(let j=i; j<i+size && j<arr.length; j++) {
            ans1.push(arr[j]);
        }
        ans2.push(ans1);
    }
    return ans2;
};
