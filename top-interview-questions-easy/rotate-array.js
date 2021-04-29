// 旋转数组
/**
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 *
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 *
 * 1 <= nums.length <= 2 * 104
 * -231 <= nums[i] <= 231 - 1
 * 0 <= k <= 105
 */

/**
 * 初始思路是模仿循环链表，向右旋转k次（求余后），然而运行超时
 *
 * 另外两种办法
 * 1.临时数组存放数据
 * 2.局部反转
 * 
 * 使用局部反转
 * 执行用时：132 ms, 在所有 JavaScript 提交中击败了33.37%的用户
 * 内存消耗：45 MB, 在所有 JavaScript 提交中击败了22.94%的用户
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    k = k % nums.length;

    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);

    function reverse(array, start, end) {
        while (start < end) {
            let temp = array[start];
            array[start++] = array[end];
            array[end--] = temp;
        }
    }
    console.log(nums)
};
const nums = [1, 2, 3, 4, 5, 6, 7];
const k = 3;

console.log(rotate(nums, 3));

// 运行超时
// var rotate = function (nums, k) {
//     let len = nums.length;
//     if (len === 1) return nums;

//     let times = k % len;

//     while (times != 0) {
//         let last = nums[len - 1];
//         for (let i = len - 1; i > 0; i--) {
//             nums[i] = nums[i - 1];
//         }
//         nums[0] = last;
//         times--;
//     }
// };
