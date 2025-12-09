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

