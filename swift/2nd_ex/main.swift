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

func cmp(_ arr: [Int], _ v: Int) {
    guard v >= arr.max() ?? 0 else {
        err("The volume of the watering can is not enough to water the flower")
    }
}

func countingSteps(_ arr: [Int], _ v: Int) -> Int {
    var count = 0
    var tmp = v

    for (i, val) in arr.enumerated() {
        if tmp < val {
            tmp = v
            count += i * 2
        }
        count += 1
        tmp -= val
    }

    return count
}

let n = initVal()
var arr: [Int] = []

for _ in 0..<n {
    arr.append(initVal())
}

let v = initVal()

cmp(arr, v)

print(countingSteps(arr, v))
