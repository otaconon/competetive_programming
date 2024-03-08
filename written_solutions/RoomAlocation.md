# Room Allocation (CSES)

### Problem Statement

We are given a list of $n$ ranges that describe time at which $\text{customer}_i$ stays at a hotel. We are tasked with printing how many rooms at most were allocated, and desribes which customer got which room.

### My solution

I first create a map that keeps track at which time stamp which customers come and go. Next i create a priority queue that keeps available rooms. I iterate over all time stamps and i assign to customers coming at the time stamp their room, next i delete the room from the set to add it whenever that customer leaves.


### Better solution

Better solution is to store a priority queue of departure times of each customer and then to iterate over all ranges which are sorted by range start. if current customer arrival time is greater than pq.top(), then we can assign this room to the current customer, else we have to assign a new room.
