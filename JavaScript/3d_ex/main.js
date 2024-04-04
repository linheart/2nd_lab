function err(exc) {
    throw new Error(exc);
}

function init() {
    const val = parseInt(prompt());
    if (isNaN(val)) {
        err("Invalid input");
    }
    return val;
}

function countingDup(n) {
    let a = init();
    let b = a;
    let count = 0;

    for (let i = 1; i < n; i++) {
        a = init();
        if (a === b) {
            count += 1;
        }
        b = a;
    }
    return count;
}
try {
    const n = init();
    if (n <= 0) {
        err("Invalid input");
    }

    console.log(countingDup(n));
} catch (e) {
    console.error(e.message);
}
