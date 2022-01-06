# pipex
behavior of the pipe function


<br> Your objective is to code the Pipex program. </br>
<br>It should be executed in this way: </br>
<br>$> ./pipex file1 cmd1 cmd2 file2 </br>
<br>Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with
their parameters. </br>
<br>The execution of the pipex program should do the same as the next shell command: </br>
<br>$> < file1 cmd1 | cmd2 > file2 </br>
<br>III.1 Examples </br>
<br>$> ./pipex infile ``ls -l'' ``wc -l'' outfile </br>
<br>should be the same as “< infile ls -l | wc -l > outfile” </br>
<br>$> ./pipex infile ``grep a1'' ``wc -w'' outfile </br>
<br>should be the same as “< infile grep a1 | wc -w > outfile” </br>

<br> • Handle multiple pipes </br>
<br> Support « and » when the first parameter is "here_doc" </br>
