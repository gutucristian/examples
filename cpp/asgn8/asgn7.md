# Discrete Event Simulation

C++ is a rich language that provides outstanding support to write large, complex applications. To appreciate the support it provides for Object-Orientation, it is essential to do a design exercises of a suitable size. We will therefore embark now on a two week (two parts) assignment to build a discrete event simulator (A mini __simulink__ if you ever used that tool!). 

## Overview

### Part 1
The first week is devoted to reading a specification of a discrete system we wish to simulate. Naturally, we are not going to rebuild the work that MathWorks did over decades, but instead, build the quintessential core of that infrastructure.  Namely, we will focus on reading a specification of a *network* of components (servers, queues, dispatchers,...) and building a composite instance (I refer here to the composite design pattern) representing the graph of components and their connectivity to carry out the simulation next week.

### Part 2 

This will augment your implementation (and we will share the solution to part 1 before you do) with simulation capabilities. The objective of a simulation is to determine the average length of queue, average waiting time, how busy the processors are, etc...In a sense, it computes a number of statistics about components present in the discrete system. This aspect of the story will be elaborated on next time.

## Part 1: in Depth

### Bird's eye view

As you can imagine, a *design* for a discrete event simulator relies on a highly polymorphic implementation so that you can *build at runtime* a system to simulate involving a variety of components. For once, you will *not* receive any source code but instead must design and implement C++ code that reads a specification and instantiates (on the heap) the network to be simulated. That network, obviously, is a graph (possibly cyclic!). At this stage, the classes you create won't do much. They should be printable so that you can look at your network and confirm that it is consistent with the specification that you read from the file. The next stage will augment your implementation with methods on the classes involved to support the simulation. 

### Your main

At the top level, the main program is therefore quite straightforward and could boils down to (I'm assuming that the filename to read from is given on the command line and there is no error checking):

    #include <iostream>
    #include <iomanip>
    #include "Simulator.hpp"

    int main(int argc,char* argv[]) {
	   Simulator* s = new Simulator;
       s->read(argv[1]);
       std::cout << s << std::endl;
       delete s;
       return 0;
    }

### Network example

Perhaps the simplest example is a network as shown below. Namely, a network with a generator of events that uses a Poisson distribution to sample the inter-arrival time, a FIFO unbounded buffer (a queue) for holding onto the events and a server with service time distributed according to an exponential with rate **r**. Finally, tasks coming out of the server reach the exit of the network. 

In essence, a discrete event simulation proceeds as follows: the simulator uses the generator to synthesize the *arrival* of a *client* in the system. The arrival events are distributed according to the policy of the generator. In this case, the inter-arrival time would have to follow a Poisson distribution with a given rate. When an event occurs at time *t*, it would be sent from the source (generator) to its destination (the queue). The client would stay in the queue waiting for its turn. As soon as the server is free, the server would pull a client from the queue and "simulate" its service by sampling the service time (here the sample should comply with the server distribution, namely, an exponential). When the client is fully processed, it would be sent to the exit node where interesting statistics could be collected such as: 

- How long did the client wait in the queue
- What is the average wait time?
- What is the average queue length for the 1 queue in this system?

Note that more general examples can use "dispatching" nodes that can send a client to different locations in the network according to some discrete distribution and that can easily create cycles. 

###  Concepts

There are multiple concepts at play to describe the network to simulate. For instance, we have:

- **Generators**: The objects responsible for creating "arrival events" where clients enter the system
- **Buffers**: The objects responsible for simulating memory structures. The classic example is a FIFO (a queue) that you would see in check out lines in grocery stores.
- **Servers**: The objects responsible for simulating the entities doing the work to "process" the client (e.g., a clerk standing at the checkout and ringing in your items). Note that the exit node of a simulation is a server as well, it simply process a client instantaneously. It is worth adding that one can encounter different *kind* of servers. Some take constant time to do their task while others will need an amount of time that is distributed according to a normal, uniform, or exponential distribution. In essence, each  distribution leads to one type of server.
- **Routers**: The objects responsible for "dispatching" clients when they leave a server and must be sent somewhere. 

### Specification example

Recall the example introduced earlier. A specification of that very simple network appears below:

    B=Poisson(4.0)
    A=FIFO()
    C=ServerExp(0.3)
    X=Exit
    B->A
    A->C
    C->X

As you might expect, the specification is quite minimal and very easy to parse. This text file is a sequence of lines, with one component per line. 
The first line creates a generator following the Poisson distribution with a rate of 4.0. The component is christened 'B' for easy retrieval. The second line defines an unbounded buffer  (its size is not limited, the buffer can grow) implementing the FIFO policy. The buffer is called 'A' for easy access. 
The third line defines a server with a service time distributed according to an exponential with rate 0.3. It is called 'C'. Finally, there is an exit node in the network and it is called 'X'. Note how each line has defined a *node* of a graph, but the node assume different *forms*. The second part of the file define the *arcs* of the graph. Namely, events originating at 'B', move to 'A'  (they go from the generator to the queue). Similarly, events coming from 'A' (the queue) move to 'C' (the server). Finally, events leaving the server 'C' move to the exit node 'X'. Clearly, this is an acyclic graph. 

### A Bigger Instance.

A bigger instance with cycles is shown below:

    A=FIFO()
    B=ServerExp(0.3)
    C=FIFO()
    D=ServerExp(0.6)
    E=FIFO()
    F=ServerNormal(2,0.5)
    G=FIFO()
    H=ServerCst(1)
    X=Exit
    K=Poisson(4.0)
    L=Poisson(2.0)
    I=Dispatch([(A,0.2),(E,0.4),(G,0.4)])
    J=Dispatch([(X,0.8),(C,0.2)])
    A->B
    C->D
    E->F
    G->H
    K->A
    L->C
    B->I
    D->G
    F->X
    H->J

The example uses multiple servers, multiple queues, two generators and routers that dispatch the events reaching them to other nodes. For instance, dispatcher 'I' sends events to node 'A' with probability 0.2, to 'E' with probability 0.4 and to 'G' with probability 0.4 (clearly the probabilities sum up to 1). Note that the instance also illustrate three types of servers following different distribution for the service times. Namely: exponential with a given rate, constant and normal with a given mean and variance. 

### Your task

For this week, your task is to design the C++ implementation by introducing classes and using the STL to hold onto the relevant attriutes for each class. Clearly, your code should be able to read an instance from a file and create the corresponding objects and their connection in memory. To demonstrate that the code works, you are only expected to print the network. 

For instance, the reference solution produces the following output 

    A --> A=FIFO(target = B)
    B --> B=ServerExp(0.3,target=I)
    C --> C=FIFO(target = D)
    D --> D=ServerExp(0.6,target=G)
    E --> E=FIFO(target = F)
    F --> F=ServerNormal(2,0.5,target=X)
    G --> G=FIFO(target = H)
    H --> H=ServerCst(1.0,target=J)
    I --> I=Dispatch([(A,0.2),(E,0.4),(G,0.4)])
    J --> J=Dispatch([(X,0.8),(C,0.2)])
    K --> K=Poisson(4)
    L --> L=Poisson(2)
    X --> X=ServerExit()

Note how the components are named. Also note that the arcs connecting the nodes are now showing up as 'targets' inside the nodes. For instance, 'B' (an exponential time server with rate 0.3) sends its output to 'I' (a dispatcher). Note also that the network does not store in component 'B' the name of the target 'I') but a direct pointer to that component so that one can implement the simulation. Names are merely a way to *represent* an instance in a file. Once the instance is loaded in memory, names are purely for documentation purposes. 

In summary you need to:

1. Design a collection of classes to handle all the type of components. This should clearly make use of encapsulation, inheritance and polymorphism to get the job done elegantly. 
2. Write the necessary method(s) to read an instance off from a file and create an in-memory object graph encoding the network.
3. Write the necessary method(s) to print out an instance to the standard output in the format shown above. 

