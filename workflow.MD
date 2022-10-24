This file will run through the basics of how to get started on your personal project!

# Get the code onto your machine from the Github project:
1. Clone the Repository
        - This will be done by finding the git extension on your local machine and following the interface to find the space about cloning.
        - For VS Code, check out this [link](https://learn.microsoft.com/en-us/azure/developer/javascript/how-to/with-visual-studio-code/clone-github-repository?tabs=create-repo-command-palette%2Cinitialize-repo-activity-bar%2Ccreate-branch-command-palette%2Ccommit-changes-command-palette%2Cpush-command-palette)     
2. Branch your work away from the Main branch
    - Branching away from the main branch allows for us to not put vital errors or mistakes that could set us back substantially.
    - To do so we "check out" other branches
    - `git checkout -b "your_name/what-you-want-to-name-the-branch"`
        * This command creates a new branch with that name and makes sure you immediately switch to the branch
    - `git branch`
        * This lists all the branches of this project with Main being the Master branch
    - `git checkout "branch-name"`
        * Allows for you to change which branch you are on

    **Always make sure that you are on your branch when coding. The main branch is where all of our code changes will be and it may break what we worked really hard on**

3. Code
    - Do whatever you are most comfortable with, but always use normal commenting for code that may be a bit difficult to understand.
    - Write separate functions for code that could be duplicated.
    - Use consistent formatting.
4. Commit your changes 
    - Can be done with the IDE's git functions 
    - or by: `git commit -m "A message you want to say about your changes"`
5. Continue steps 2 and 3 until you are satisfied with your changes (Branch and code)
6. **Push** your changes to the remote branch
    - This will be done when you think you are ready for your code to be added to the main branch
    - `git push`
        * This may prompt a longer push command, copy and paste the one that it says and it will allow you to use just `git push` next time
        * It may also tell you that there are no remote branches for your new branch. Allow for it to publish the remote branch.
7. Create a **Pull Request**
    - You will do this within Github under the "Pull Requests" tab
    - There will likely be a new button that recognizes your new branch. Click that option
    - You want your branch to merge into main
    - This PR can stay up for as long as you want.
    - **How long should PR's be?**
        * they should be relatively small. Rather have a bunch of small PR's over one huge one that is so hard to look over.
        * It could be as small as one function!
8. Continue working until you are satisified
    - You can keep pushing changes and it will show up within the PR's code changes.
    - Merge Conflicts:
        * Hopefully we will not have any since we will delegate separate tasks
        * Make sure that you handle it by editing YOUR own code and not overwriting someone else's changes or it will get tough to handle.
    - If you are happy with what is created move onto step 9
9. Merge changes with the main branch
    - You can do this by looking at your PR and click the "Merge pull request" button!
10. Celebrate
    - You have completed your changes to the main branch! Thank you for your hard work :D