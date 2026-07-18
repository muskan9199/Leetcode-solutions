/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const res = {};
    for (const item of this) {
        const key = fn(item);
        if (!res[key]) {
            res[key] = [];
        }
        res[key].push(item);
    }
    return res;
};
/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna