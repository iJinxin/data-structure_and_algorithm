/**
 * 删除排序数组中的重复项
 *
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成
 *
 * 0 <= nums.length <= 3 * 104
 * -104 <= nums[i] <= 104
 * nums 已按升序排列
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let len = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[len]) {
            nums[++len] = nums[i]
        }
    }
    return len + 1
};

const test1 = [1,1,2]
const test2 = [0,0,1,1,1,2,2,3,3,4]
console.log(removeDuplicates(test1))

/**
 * 执行用时：104 ms, 在所有 JavaScript 提交中击败了57.50%的用户
 * 内存消耗：39.9 MB, 在所有 JavaScript 提交中击败了92.46%的用户
 */
