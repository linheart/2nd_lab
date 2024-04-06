import Foundation

func err(_ exc: String) -> Never {
    fatalError(exc)
}

func initVal() -> Int {
    guard let line = readLine(), let val = Int(line) else {
        err("Invalid input")
    }
    return val
}

func countingDup(_ n: Int) -> Int {
    var a = initVal()
    var b = a
    var count = 0

    for _ in 1..<n {
        a = initVal()
        if a == b {
            count += 1
        }
        b = a
    }

    return count
}

let n = initVal()
if n <= 0 {
    err("Invalid input")
}

print(countingDup(n))
