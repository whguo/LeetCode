#判断一个字符串能否代表一棵二叉树的前序遍历，None用#表示。
class Solution(object):

    #栈的思想：不断的砍掉叶子节点。最后看看能不能全部砍掉。
    #1.使用“栈”从左到右扫描数据；
    #2.当遇到数字字符，直接进栈；
    #3.当遇到“#”字符：
        #1）如果“栈”顶不是“#”，直接入栈；
        #2）如果“栈”顶也是“#”，连续再次出栈，循环直到“栈”顶非“#”；
        #3）“#”字符进栈。
    #4.最后，当stack中只剩一个“#”字符时，返回true，否则false。
    def isValidSerialization1(self, preorder):
        preorder = preorder.split(',')
        stack = []
        for ch in preorder:
            while ch=='#' and stack!=[] and stack[-1]=='#':
                stack.pop()
                if stack==[]:   return False
                stack.pop()
            stack.append(ch)
        return len(stack)==1 and stack[0]=='#'

    #入度和出度的差
    #对于二叉树，我们把空的地方也作为叶子节点（如题目中的#），那么有
    #1.所有的非空节点提供2个出度和1个入度（根除外）
    #2.所有的空节点提供0个出度和1个入度
    #在遍历的时候，计算diff = outdegree – indegree. 当一个节点出现的时候，diff – 1，因为它提供一个入度；
    #当节点不是#的时候，diff+2(提供两个出度) 如果序列式合法的，那么遍历过程中diff >=0 且最后结果为0.
    def isValidSerialization(self, preorder):
        preorder = preorder.split(',')
        diff = 1
        for ch in preorder:
            diff -= 1
            if diff<0: return False
            if ch!='#': diff += 2
        return diff==0

s = Solution()
print(s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"))

