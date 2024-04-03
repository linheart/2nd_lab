use std::io::stdin;

fn func(s: i32, m: i32, n: i32) -> i32 {
    if s * m > (s - s / 7) * n {
        -1
    } else {
        ((s as f64) * (m as f64) / (n as f64)).ceil() as i32
    }
}

fn main() {
    let mut input = String::new();

    stdin().read_line(&mut input).expect("Failed to read line");
    let s: i32 = input.trim().parse().expect("Input was not an integer");
    input.clear();

    stdin().read_line(&mut input).expect("Failed to read line");
    let n: i32 = input.trim().parse().expect("Input was not an integer");
    input.clear();

    stdin().read_line(&mut input).expect("Failed to read line");
    let m: i32 = input.trim().parse().expect("Input was not an integer");

    println!("{}", func(s, m, n));
}
