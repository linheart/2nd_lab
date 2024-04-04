use std::io::stdin;

fn func(s: i32, m: i32, n: i32) -> i32 {
    if s * m > (s - s / 7) * n {
        -1
    } else {
        ((s as f64) * (m as f64) / (n as f64)).ceil() as i32
    }
}

fn init() -> i32 {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed to read line");

    match input.trim().parse::<i32>() {
        Ok(num) if num > 0 => return num,
        _ => panic!("Invalid input"),
    }
}

fn main() {
    let s = init();
    let n = init();
    let m = init();

    println!("{}", func(s, m, n));
}
