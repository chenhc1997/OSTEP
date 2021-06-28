# 15 Mechanism: Address Translation

*flexibility* 

## 15.1 Assumptions

1. the user’s address space must be placed *contiguously* in physical memory

2. size is *less than the size of physical memory*
3. each address space is exactly the *same size*.

## 15.5 Operating System Issues

此时，与page不同之处在于，每个process只占用一个slot防止三个segment。

1. when a process is created, finding space for its address space in memory.
2. Upon termination of a process, the OS thus puts its memory back on the free list, and cleans up any associated data structures as need be.
3. the OS must *save and restore* the base-and-bounds pair when it switches be- tween processes. 

Base-and-bounds virtualization is quite *efficient*, 

**however**, because the process stack and heap are not too big, all of the space between the two is simply *wasted*.

要解决这些**internal fragmentation**, 引出了 **segmentation** 的virtualization方式。