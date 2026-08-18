var compactObject = function(obj) {
    if (!obj) return null;
    if (typeof obj !== 'object') return obj;

    if (Array.isArray(obj)) {
        const newArr = [];
        for (let i = 0; i < obj.length; i++) {
            const subRes = compactObject(obj[i]);
            if (subRes) {
                newArr.push(subRes);
            }
        }
        return newArr;
    }

    const newObj = {};
    for (const key in obj) {
        const subRes = compactObject(obj[key]);
        if (subRes) {
            newObj[key] = subRes;
        }
    }
    return newObj;
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna