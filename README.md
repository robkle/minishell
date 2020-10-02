# minishell
A simple Unix command interpreter that does the following:<br />
* Displays a prompt and wait for a command, which is validated by pressing enter.<br />
* Simple commands; no pipes, no redirections (except > and >> with **echo** command).<br />
* Multiple commands separated by ';'.<br />
* Commands found in paths indicated by PATH environment variable.<br />
* Manage errors.<br />
* Manage '$' and '~' expansion.<br />

Minishell also includes builtins: **echo**, **cd**, and **exit**, as well as **env**, **setenv**, and **unsetenv** for displaying, modifying/adding, and deleting environment variables.<br />
### Usage
Repository contains a Makefile for:<br /> 
* compiling executable (**make all**)<br />
* removing object files (**make clean**)<br />
* deleting executable (**make fclean**)<br />
* recompiling (**make re**)<br />

Example:<br />
<img src="screenshot.png" alt="example" width="450"/><br />
#### Notes:
This project is part of my studies at Hive Helsinki. It was thoroughly tested by 5 fellow Hive students.
