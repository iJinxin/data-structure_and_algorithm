// leetcode20,括号匹配
// 执行用时：72 ms, 在所有 JavaScript 提交中击败了98.35%的用户
// 内存消耗：37.8 MB, 在所有 JavaScript 提交中击败了42.33%的用户
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    let n = s.length
    if (n % 2 !== 0) return false

    let stack = []
    let map = new Map([
        [')', '('],
        [']', '['],
        ['}', '{']
    ])
    for (let i = 0; i < n; i++) {
        let char = s.charAt(i)
        if (map.has(char)) {
            if (stack.length === 0 || stack[stack.length - 1] !== map.get(char)) {
                return false
            }
            stack.pop()
        } else {
            stack.push(char)
        }
    }
    return stack.length === 0
};


let test = "([}}])"
console.log(isValid(test))