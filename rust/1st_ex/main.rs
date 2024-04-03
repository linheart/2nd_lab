use std::io::{stdout, stdin, Write};

fn func(s: i32, m: i32, n: i32) -> i32 {
    if s * m > (s - s / 7) * n {
        -1
    } else {
        ((s as f64) * (m as f64) / (n as f64)).ceil() as i32
    }
}

fn main() {
    let mut input = String::new();

    print!("Input the number of days: ");
    stdout().flush().unwrap(); 
    stdin().read_line(&mut input).expect("Failed to read line");
    let s: i32 = input.trim().parse().expect("Input was not an integer");
    input.clear();

    print!("Input the maximum number of units of food per day that a traveler can buy at the store: ");
    stdout().flush().unwrap();
    stdin().read_line(&mut input).expect("Failed to read line");
    let n: i32 = input.trim().parse().expect("Input was not an integer");
    input.clear();

    print!("Input the number of units of food per day that the traveler needs to survive: ");
    stdout().flush().unwrap();
    stdin().read_line(&mut input).expect("Failed to read line");
    let m: i32 = input.trim().parse().expect("Input was not an integer");

    println!("{}", func(s, m, n));
}
