use std::io::stdin;

fn cmp(a: i32, b: i32) -> i32 {
    if a == b {
        1
    } else {
        0
    }
}

fn init() -> i32 {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed to read line");

    let num = input.trim().parse().expect("Invalid input");

    num
}

fn main() {
    let n = init();
    if n <= 0 {
        panic!("Invalid input");
    }

    let mut a = init();
    let mut b = a;
    let mut count = 0;

    for _ in 1..n {
        a = init();
        count += cmp(a, b);
        b = a;
    }

    println!("{}", count);
}
