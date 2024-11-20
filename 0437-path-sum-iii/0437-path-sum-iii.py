class Solution:
    def pathSum(self, root, sum):
        def dfs(node, current_sum, prefix_sum):
            if not node:
                return 0

            # Update the current sum
            current_sum += node.val

            # Check if there is a path that ends at the current node
            count = prefix_sum.get(current_sum - sum, 0)

            # Update the prefix_sum map
            prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1

            # Recurse into left and right children
            count += dfs(node.left, current_sum, prefix_sum)
            count += dfs(node.right, current_sum, prefix_sum)

            # Decrement the current sum path count (backtracking)
            prefix_sum[current_sum] -= 1

            return count

        # Initialize the prefix sum map with the base case
        prefix_sum = {0: 1}  # There is one way to get a sum of 0 (empty path)
        return dfs(root, 0, prefix_sum)
