// 存在重复元素
/**
 * 给定一个整数数组，判断是否存在重复元素。
 * 如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 */

 /**
 * @param {number[]} nums
 * @return {boolean}
 * 执行用时：120 ms, 在所有 JavaScript 提交中击败了22.58%的用户
 * 内存消耗：46.1 MB, 在所有 JavaScript 提交中击败了6.89%的用户
 */
var containsDuplicate = function(nums) {
    if (nums.length <= 1) return false

    let map = {}
    for (let i=0;i<nums.length;i++) {
        if (!map[nums[i]]) {
            map[nums[i]] = 1
        } else {
            return true
        }
    }
    return false
};

 /**
 * @param {number[]} nums
 * @return {boolean}
 * 执行用时：88 ms, 在所有 JavaScript 提交中击败了84.20%的用户
 * 内存消耗：43.7 MB, 在所有 JavaScript 提交中击败了50.40%的用户
 */
var containsDuplicate2 = function(nums) {
    return new Set(nums).size !== nums.length
};

const test = [1,2,3,4,1]
console.log(containsDuplicate2(test))