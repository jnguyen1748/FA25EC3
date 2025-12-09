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



