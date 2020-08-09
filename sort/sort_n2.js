// n^2 排序算法

// 冒泡排序
function bubbleSort(arr) {
    let size = arr.length

    for (let i=0;i<size;i++) {
        let flag = false
        for (let j=0;j<size-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                let temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
                flag = true
            }
        }
        if (!flag) break
    }
    return arr
}

// 选择排序
function selectSort(arr) {
    let size = arr.length

    for (let i=0;i<size;i++) {
        let minIndex = i;
        for (let j=i+1;j<size;j++) {
            if (arr[j] < arr[i]) {
                minIndex = j
            }
        }
        if (minIndex != i) {
            let temp = arr[i]
            arr[i] = arr[minIndex]
            arr[minIndex] = temp
        }
    }
    return arr
}

// 插入排序
function insertSort(arr) {
    let size = arr.length
    if (size <= 1) return

    for (let i=1;i<size;i++) {
        let value = arr[i];
        let j = i-1
        for (;j>=0;j--) {
            if (value < arr[j]) {
                arr[j+1] = arr[j] // 数据右移
            } else {
                break
            }
        }
        arr[j+1] = value
    }
    return arr;
}


let testArr = [2,3,4,1,11,42,14,12,3, 100]
// console.log(bubbleSort(testArr))
// console.log(insertSort(testArr))
console.log(selectSort(testArr))