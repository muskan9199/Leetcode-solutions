var join = function(arr1, arr2) {
    const res = {};

    for (const obj of arr1) {
        res[obj.id] = obj;
    }

    for (const obj of arr2) {
        res[obj.id] = res[obj.id] ? { ...res[obj.id], ...obj } : obj;
    }

    return Object.values(res);
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna