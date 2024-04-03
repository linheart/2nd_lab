use std::io::stdin;

fn cmp(a: i32, b: i32) -> i32 {
    if a == b {1} else {0}
}

fn main() {
    let mut input = String::new();
    
    stdin().read_line(&mut input).expect("Failed to read line");
    let n: usize = input.trim().parse().expect("Input was not a number");
    input.clear();
    
    stdin().read_line(&mut input).expect("Failed to read line");
    let mut a: i32 = input.trim().parse().expect("Input was not a number");
    let mut b = a;
    input.clear();
    
    let mut count = 0;

    for _ in 1..n {
        stdin().read_line(&mut input).expect("Failed to read line");
        a = input.trim().parse().expect("Input was not a number");
        input.clear();

        count += cmp(a, b);
        b = a;
    }

    println!("{}", count);
}
