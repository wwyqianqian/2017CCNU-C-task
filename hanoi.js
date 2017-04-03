let hanoi = (n, a, b, c) => {
    if (n == 1) {
        console.log(`${a} -> ${c}`)
    } else {
        hanoi(n - 1, a, c, b)
        hanoi(1, a, b, c)
        hanoi(n - 1, b, a, c)
    }
}

hanoi(3, 'a', 'b', 'c')
