use std::io::stdin;

fn counting_steps(arr: &Vec<i32>, v: i32) -> usize {
    let mut count = 0;
    let mut tmp = v;

    for i in 0..arr.len() {
        if tmp < arr[i] {
            tmp = v;
            count += i * 2;
        }
        count += 1;
        tmp -= arr[i];
    }

    count
}

fn init_str() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed to read line");

    input
}

fn init_i32(input: String) -> i32 {
    match input.trim().parse::<i32>() {
        Ok(num) if num > 0 => return num,
        _ => panic!("Invalid input"),
    }
}

fn init_vec(input: String) -> Vec<i32> {
    let arr: Vec<i32> = input
        .split_whitespace()
        .map(|s| {
            s.parse::<i32>().unwrap_or_else(|_| {
                panic!("Invalid input");
            })
        })
        .filter(|&n| {
            if n > 0 {
                true
            } else {
                panic!("Invalid input");
            }
        })
        .collect();

    arr
}

fn cmp(v: i32, arr: &Vec<i32>) {
    if v < *arr.iter().max().unwrap() {
        panic!("The volume of the watering can is not enough to water the flower");
    }
}

fn main() {
    let n = init_i32(init_str());

    let arr: Vec<i32> = init_vec(init_str());

    if arr.len() != (n as usize) {
        panic!("The array does not consist of n elements");
    }

    let v = init_i32(init_str());

    cmp(v, &arr);

    println!("{}", counting_steps(&arr, v));
}
