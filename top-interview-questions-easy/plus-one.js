// 加一
/**
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 *
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 */

/**
 * @param {number[]} digits
 * @return {number[]}
 *
 * 计算-进位
 * 执行用时：96 ms, 在所有 JavaScript 提交中击败了19.87%的用户
 * 内存消耗：37.8 MB, 在所有 JavaScript 提交中击败了67.64%的用户
 */
var plusOne = function (digits) {
    calc(digits.length - 1);

    function calc(index) {
        if (digits[index] === 9) {
            if (index === 0) {
                digits[0] = 0;
                digits.unshift(1);
            } else {
                digits[index] = 0;
                calc(index - 1);
            }
        } else {
            digits[index] += 1;
        }
    }
    return digits;
};
// const test = [9,9,9,9]
// console.log(plusOne(test))

/**
 * @param {number[]} digits
 * @return {number[]}
 * 执行用时：84 ms, 在所有 JavaScript 提交中击败了65.21%的用户
 * 内存消耗：37.8 MB, 在所有 JavaScript 提交中击败了85.31%的用户
 */
var plusOne2 = function (digits) {
    for (let i = digits.length - 1; i >= 0; i--) {
        if (digits[i] === 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            return digits;
        }
    }
    digits.unshift(1);
    return digits;
};

const test = [1, 2, 3, 4];
console.log(plusOne2(test));
