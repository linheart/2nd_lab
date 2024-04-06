import Foundation

func err(_ exc: String) -> Never {
    fatalError(exc)
}

func initVal() -> Int {
    guard let line = readLine(), let val = Int(line), val > 0 else {
        err("Invalid input")
    }
    return val
}

func funcCalc(S: Int, N: Int, M: Int) -> Int {
    if S * M > (S - S / 7) * N {
        return -1
    }
    return Int(ceil(Double(S * M) / Double(N)))
}

let S = initVal()
let N = initVal()
let M = initVal()

print(funcCalc(S: S, N: N, M: M))
