/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let resolvedCount = 0;

        if (functions.length === 0) {
            return resolve(results);
        }

        functions.forEach((fn, index) => {
            fn()
                .then((val) => {
                    results[index] = val; // Maintain original order
                    resolvedCount++;

                    // Resolve only when all functions have completed successfully
                    if (resolvedCount === functions.length) {
                        resolve(results);
                    }
                })
                .catch((err) => {
                    // Reject immediately if any promise fails
                    reject(err);
                });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna