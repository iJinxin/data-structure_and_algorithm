/**
 * 棒球比赛
 * 你现在是一场采特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
 * 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：

 * 整数 x - 表示本回合新获得分数 x
 * "+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
 * "D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
 * "C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
 * 请你返回记录中所有得分的总和。
 * 
 * tips:
 *  1 <= ops.length <= 1000
    ops[i] 为 "C"、"D"、"+"，或者一个表示整数的字符串。整数范围是 [-3 * 104, 3 * 104]
    对于 "+" 操作，题目数据保证记录此操作时前面总是存在两个有效的分数
    对于 "C" 和 "D" 操作，题目数据保证记录此操作时前面总是存在一个有效的分数

   Result:
    执行用时：92 ms, 在所有 JavaScript 提交中击败了44.70%的用户
    内存消耗：38.8 MB, 在所有 JavaScript 提交中击败了28.11%的用户
 */


/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function (ops) {
    let stack = [0];
    ops.forEach(item => {
        if (item === '+') {
            stack[0] += Number(stack[stack.length - 1]) + Number(stack[stack.length - 2])
            stack.push(Number(stack[stack.length - 1]) + Number(stack[stack.length - 2]))
        } else if (item === 'D') {
            stack[0] += Number(stack[stack.length - 1])*2
            stack.push(Number(stack[stack.length - 1])*2)
        } else if (item === 'C') {
            stack[0] -= Number(stack[stack.length - 1])
            stack.pop()
        } else {
            stack[0] += Number(item)
            stack.push(item)
        }
    })
    return stack[0]
};
