# Detecting Missing Video Frames
This repository is part of a participation in HurryApp 3 hackathone and only contains solutions related to the challenge problem.
# Solutions 
## Optimal Solution
Because the problem states an explicit rule not to use sort(), I assumed that we cannot even implement a sorting algorithm manually. Fastest sorting algorithms costs O(frames log frames) on average but this solution that skips sorting and focuses on lookup is faster: O(frames). By just adding all frames into an unordered set we can utilize that unordered sets allow us to lookup in an average time of O(1). To sum it up, we first find the heighest number in the list (that last frame) and then we lookup if each frame from 1 to last frame (maxi) exists in the unordered set in O(1) which makes up a total of O(n)* time complexity and O(n) space complexity.

## Additional Solutions:
1. We could sort the frames without explicity using an built-in sort() function but by adding all frames to an ordered set that will automatically sort them. adding one element costs O(log n) to an ordered set but adding n elements costs O(n log n). regarding space complexity it is also O(n).
2. We could also use quicksort to sort them manually but we are not sure if sorting manually is allowed at all and this method also takes O(n log n).
3. This solution is fine only if frames <= 10^9**. We can create a boolean array and mark each cell in the array as true if the element exists in frames. This solution has a time complexity of O(maxi) because we are only looking up frames based on their indices (which are naturally ordered) and since we have a fixed start (frame counting starts from 1) this is considered a good solution but given that these frames are of a surviliance videos then we cannot assume a maximum number of frames of 10^9 and that means we would need so much space to cover all that processing even though it has a space complexity of O(n).
---
\* n = number of frames or the heighest frames between frames.

** PROPLEMS SHOULD HAVE CONSTRAINTS please don't do that again.
![Angry Leonardo Dicaprio GIF](https://github.com/user-attachments/assets/bf720f0e-ca05-47e3-8db3-a0598244d6b8)
