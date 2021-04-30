// 移动零
/**
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 */

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 * 执行用时：96 ms, 在所有 JavaScript 提交中击败了54.00%的用户
 * 内存消耗：39.8 MB, 在所有 JavaScript 提交中击败了16.36%的用户
 */
var moveZeroes = function (nums) {
    let len = nums.length;
    if (len <= 1) return nums;

    let pos = 0;
    for (let i = 0; i < len; i++) {
        if (nums[i] == 0) {
            pos = findNonZero(Math.max(pos + 1, i + 1));
            if (pos >= len) break

            nums[i] = nums[pos];
            nums[pos] = 0;
        }
    }
    function findNonZero(index) {
        while (index < len) {
            if (nums[index] != 0) break;
            index++;
        }
        return index;
    }

    return nums;
};
// const test = [0, 0];
// console.log(moveZeroes(test));

/**
 * 陷入了误区，尝试往后找非0的元素，但其实只需记录i之前的0即可
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 * 执行用时：88 ms, 在所有 JavaScript 提交中击败了84.90%的用户
 * 内存消耗：39.3 MB, 在所有 JavaScript 提交中击败了82.77%的用户
 */
var moveZeroes2 = function(nums) {
    let pos = 0
    for (let i=0;i<nums.length;i++) {
        if (nums[i] != 0) {
            let temp = nums[i]
            nums[i] = nums[pos]
            nums[pos] = temp
            pos++
        }
    }
    return nums
}
const test = [1, 0, 2,3];
console.log(moveZeroes2(test));