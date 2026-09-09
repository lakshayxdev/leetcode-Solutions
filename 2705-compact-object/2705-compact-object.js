/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        let ans = [];

        for (let i = 0; i < obj.length; i++) {
            if(typeof obj[i]==="object" && obj[i]!==null) {
                let value=compactObject(obj[i]);
                if(value) {
                    ans.push(value);
                }
            }
            else {
                if(obj[i]) {
                    ans.push(obj[i]);
                }
            }
        }

        return ans;
    }
    else {
        let ans = {};

        for (let key in obj) {

            if (typeof obj[key] === "object" && obj[key] !== null) {
                let value = compactObject(obj[key]);

                if (value) {
                    ans = {...ans, [key]: value};
                }
            }
            else {
                if (obj[key]) {
                    ans = {...ans, [key]: obj[key]};
                }
            }
        }

        return ans;
    }
};