# simple_C_shell
Task 3 is cray cray

 - sys calls that don't require forking were already implemented, just had to write functions to call the resp files 
 
 ### what students had to do
 - loop the shell to only exit upon typing exit
 - tokenisation arguments (parser to decide when to fork/when not to fork)
 - simple daemon summoning using forks and chdir etc, and keep track of your daemons inside 






## Misc
There were 2 branches had unrelated histories because i:
git clone an existing repository, initialised new repo with readmefile, changed remote branch to this branch 
so 2 different commit histories (nat's repo vs my repo with readme)
fixed by:
git pull origin master --allow-unrelated-histories on main(the readme one from main)
see here to learn
https://www.educative.io/edpresso/the-fatal-refusing-to-merge-unrelated-histories-git-error
