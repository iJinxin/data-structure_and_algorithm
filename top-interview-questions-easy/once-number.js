// 只出现一次的数字
/**
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 */

/**
 * @param {number[]} nums
 * @return {number}
 * 
 * 思路：使用异或运算，相同项会被置为0，唯一不同项不变
 * 执行用时：88 ms, 在所有 JavaScript 提交中击败了79.55%的用户
 * 内存消耗：40.5 MB, 在所有 JavaScript 提交中击败了54.33%的用户
 */
var singleNumber = function (nums) {
    let result = 0;
    for (let i = 0; i < nums.length; i++) {
        result ^= nums[i];
    }
    return result;
};
const test = [4,1,2,1,2]
console.log(singleNumber(test))