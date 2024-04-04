function err(exc) {
    throw new Error(exc);
}

function init() {
    let val = parseInt(prompt(), 10);
    if (isNaN(val) || val <= 0) {
        err("Invalid input");
    }
    return val;
}

function func(S, N, M) {
    if (S * M > (S - Math.floor(S / 7)) * N) {
        return -1;
    }
    return Math.ceil(S * M / N);
}

try {
    let S = init();
    let N = init();
    let M = init();

    console.log(func(S, N, M));
} catch (e) {
    console.error(e.message);
}
