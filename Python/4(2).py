class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        l1 = len(nums1)
        l2 = len(nums2)
        l = l1+l2
        i,j,k = 0,0,0
        while i<l/2:
            if j<l1 and k<l2:
                if nums1[j]>=nums2[k]:
                    tmp=nums1[k]
                    k+=1
                    
                else:
                    tmp=nums2[j]
                    j+=1
                    
            elif j>=l1:
                tmp=nums2[k]
                k+=1
                
            elif k>=l2:
                tmp=nums1[j]
                j+=1
                
            i+=1
            print(j,k)
        return tmp
        
        

s = Solution()
print(s.findMedianSortedArrays([1,3,9,10],[2,4,5,6])) 
