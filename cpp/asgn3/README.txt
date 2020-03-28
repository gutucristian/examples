The monks in Hanoi are trying to act out their ancient prophecy and
they need your help!

They have been tasked with moving a series of golden discs between
three posts, starting from a post on their left, to another post on
their right.  They may move a disc between any two posts, but they can
only move one disc at a time.  They are also not allowed to place a
disc on top of a smaller disc, as the weight could cause the discs to
warp.

Having studied their discs for a while, they realize that they need to
move all of their discs, but the bottom one to the middle post, so
that they can then move the largest of the golden discs to the
destination peg.  However, they are struggling to extend this to the
large number of discs that they have.

1.  Write a recursive function that can produce the instructions
necessary to instruct the monks in what order and where to move their
discs.

The monks are greatly encouraged to see your detailed solution to
their problem!

However, they quickly get lost in the lengthy list of instructions
when they go off to eat.

2.  Modify your solution so that you can retain the state of the pegs
using a series of stacks, each of which represents a single post.

3.  Add a print function that can clearly display the state of each
post as the discs are moved.

The monks are excited to see the drawings that make the solution so
easy to understand.  They scurry off to begin their Herculean task of
moving the golden discs.

4.  Having solved the monks' problem, improve your code by creating
abstractions of the three posts using structs that contain the name of
the post and the stack of discs that have been placed there.

A skeleton has been provided for you in HanoiSkeleton.cpp, so that you
have some structure to work with.

An example of good output for problems of size 4, 10 and 15 is
included in tower.txt.
