function err(exc) {
    throw new Error(exc);
}

function init() {
    const val = parseInt(prompt());
    if (isNaN(val) || val <= 0) {
        err("Invalid input");
    }
    return val;
}

function cmp(arr, v) {
    if (v < Math.max(...arr)) {
        err("The volume of the watering can is not enough to water the flower");
    }
}

function countingSteps(arr, v) {
    let count = 0;
    let tmp = v;

    for (let i = 0; i < arr.length; i++) {
        if (tmp < arr[i]) {
            tmp = v;
            count += i * 2;
        }
        count += 1;
        tmp -= arr[i];
    }

    return count;
}
try {
    const n = init();

    const arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(init());
    }

    const v = init();

    cmp(arr, v);
    
    console.log(countingSteps(arr, v));
} catch (e) {
    console.error(e.message);
}
