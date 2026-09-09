/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    arr.sort(function(a,b) {
        if(fn(a) > fn(b)) {
            return 1;
        }
        else {
            return -1;
        }
    });
    return arr;
};