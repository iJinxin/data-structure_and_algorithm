// 两数之和
/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 *
 * 两层循环暴力破解
 * 执行用时：84 ms, 在所有 JavaScript 提交中击败了65.20%的用户
 * 内存消耗：38 MB, 在所有 JavaScript 提交中击败了49.18%的用户
 */
var twoSum = function (nums, target) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }
};
// const nums = [3,2,4];
// const target = 6
// console.log(twoSum(nums, target))

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 * hash
 * 执行用时：76 ms, 在所有 JavaScript 提交中击败了91.63%的用户
 * 内存消耗：37.8 MB, 在所有 JavaScript 提交中击败了92.55%的用户
 */
var twoSum2 = function (nums, target) {
    let m = {};
    for (let i = 0; i < nums.length; i++) {
        let key = target - nums[i]
        if (m[key] != undefined) {
            return [m[key], i];
        }
        m[nums[i]] = i;
    }
};
const nums = [2, 7, 11, 15];
const target = 9;
console.log(twoSum2(nums, target));
