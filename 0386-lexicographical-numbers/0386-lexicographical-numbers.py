class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        arr = range(1, n+1)
        for i in range(len(arr)):
            arr[i] = str(arr[i])
        arr = sorted(arr)
        for i in range(len(arr)):
            arr[i] = int(arr[i])
        return arr
        