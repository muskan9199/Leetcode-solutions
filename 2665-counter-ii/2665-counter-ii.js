/**
 * @param {integer} init
 * @return { {increment: Function, decrement: Function, reset: Function} }
 */
var createCounter = function(init) {
    let currentCount = init;

    return {
        increment: function() {
            return ++currentCount;
        },
        decrement: function() {
            return --currentCount;
        },
        reset: function() {
            currentCount = init;
            return currentCount;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna