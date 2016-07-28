#给定一个嵌套的整数列表，实现一个迭代器将其展开。
#每一个元素或者是一个整数，或者是一个列表 -- 其元素也是一个整数或者其他列表
class NestedIterator(object):
    def __init__(self, nestedList):
        self.__list = []
        self.__index = 0
        self.__getList(nestedList)

    def __getList(self, nestedList):
        for item in nestedList:
            if item.isInteger():
                self.__list.append(item.getInteger())
            else:
                self.__getList(item.getList())

    def next(self):
        res = self.__list[self.__index]
        self.__index += 1
        return res

    def hasNext(self):
        if(self.__index < len(self.__list)):
            return True
        return False


