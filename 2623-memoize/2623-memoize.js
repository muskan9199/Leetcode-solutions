/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    // Create a cache map to store previous results
    const cache = new Map();
    
    return function(...args) {
        // Convert the arguments array into a unique string key
        const key = JSON.stringify(args);
        
        // If the key exists, return the cached result immediately
        if (cache.has(key)) {
            return cache.get(key);
        }
        
        // Otherwise, execute the function, store it, and return it
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }
}

/** * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 * return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna