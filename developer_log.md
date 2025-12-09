Your Developer Log must include:
- A dated entry every time you work on the assignment
- A description of what you worked on
- Any bugs, issues, or problems you encountered
- How you attempted to solve each issue
- A brief explanation of every commit you make
- A list of all files modified during each commit

Commit messages must also be descriptive, and the Developer Log must reflect the reasoning behind each commit.

2025/12/08
worked on the tree.h for now and getting it put together, to understand how the project structure worked

This work extended into the next day, so the commit is on 12/09

commit name: added tree.h (or something along those lines)


modified:
- tree.h and developer_log.md


problems:
implementing dfs in tree.h took some planning and thinking. Although I implemented DFS in the
past assignment, adapting it to this situation, and especially having to use DFS for both delete and findnode
was a little tricky.

To get around not editing method headers (i assume you cant) I decided to use helper methods. since I forgot how
class files work in c++ i didnt immediately think to put the helper methods in the private: part of tree, so
that took some trial and error to figure out.

problem 2:
after building tree.h how I thought it was supposed to work, I had to figure out what was meant by // TODO: Students, add all remaining nodes,
written in the main.cpp. I had no idea what to put in the for loop, and I had to think about the project structure and plan changes
to tree.h that would be needed. 

well I decided to just leave what I thought was right, and move on to developing playgame(). I am unsure about what to do here, maybe
it will make more sense after developing playgame();

playgame() actually made sense, so I guess I will make this complete and then go back. 

2025/12/09 about 12

added commit that added a short playgame() that I thought made sense, as well as a lot of comments
and planning around how to proceed with development. This assignment is becoming more complicated and I need
a good outline to not get lost. 

- modified main.cpp, tree.h, developer_log.md

back to problem 2:
I decided I should use a nested for loop instead of a single for loop. the reason for this is that just
straight up adding nodes wouldn't work. 

2025/12/09 1245

added another commit

now bug testing

I decided to add my own story.txt and start running the program and figuring out what was going wrong, cause
I felt like there was something I was missing in my implementation of tree.h. 

I got an output that was this:
parent 2 not found
parent 3 not found
parent 3 not found
parent 4 not found
parent 5 not found
Story loaded into your dynamic tree structure.
Implement the Tree class to enable traversal and printing.
play start
node id: 1:  You stand in a forest clearing.
game end

Now I need to figure out what is wrong here.

problem 3: adding nodes and then actually using add method problems

so initially with our single for loop, we were doing this:
for each rawNode:
create node
create children

however, this resulted in nullpointer errors, as we would reference children that didn't exist
ex: node 2 might have 4 as child but 4 isn't read yet, so now findNode(4) returns null cause 4 wasnt read yet.

the solution for this was a double for loop structure.
for each rawNode:
for each child ID of rawNode:
addNode(parentID, childID, childText)

this structure is somewhat similar to how we did dfs, but I got stuck here cause i didn't know if it was ok to use 2 for loops,
since it looked like minimal changes to main were asked of. After doing this, I added collecting the child text value as well,
using another for loop to look up child text values.

fixing addnode:

the old addnode would work by using the childnode value and always making a new child

Node<T>* childNode = new Node<T>(childID, value);
parentNode->children.push_back(childNode);  

if we added 1 -> 2 and 3 -> 2, then we would create 2 nodes representing 2.
(1-2) and (3-2) would be made, instead of a node 2 that has parents 1 and 3.

so the new addnode works by simply checking for null child first
function addNode(parentID, childID, value):

childNode = findNode(childID)
if childNode is null:
childNode = new Node(childID, value)

with this, I was finally able to fix problems 2 and 3, and commited this.

commit 2025/12/09

finally have basic functionallity


