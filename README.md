# Carnival

## Menu
* [Brief](#Brief)
* [Features](#Features)
* [Support for TTY](#support-for-tty)
* [Compilers](#Compilers)
* [C Standard](#c-standard)
* [Build](#Build)
* [DevLog](#DevLog)
* [Trouble Shooting](#trouble-shooting)

## Brief
A friend project to: [__\[Jungle - Study - Java\]__](https://github.com/WilliamPascal/STUDY) written in C. More supplies towards [__GNU__](https://www.gnu.org/)/[__Linux__](https://www.gnu.org/gnu/linux-and-gnu.html) and __Microsoft® Windows™__.

## Features
* Date & Time calculator
* Powerful Scheduler
* Todo list with its programmable language
* Alarm clock
* Text editor (TUI version of [Que](https://github.com/WilliamPascal/Que))
* Music player

## Specials
* TUI Windowing
* Graceful
* Customisable
* Impressive to use on first, impossible to get rid off it later on. :)[^1.1]
* Has features above ;)[^1.2]

## Support for TTY
Carnival's output is simply __ASCII__[^1] (TUI). However, colouring is not strictly required, as an compatibility for non-colourable terminals.  
For TTY, our first priority, we do provide basic rendering on most terminals.  

## Compilers
In code, we tried to make Carnival more compatible with different compilers.  
In current stage, it's mainly supported by:
* [GCC](https://gcc.gnu.org/)
* [MinGW](https://www.mingw-w64.org/)

Please note, unlike what we did previously, Carnival is now assembled with those compilers' support.  
That means, you could have used your compilers to build this project and execute the result regardless about what your compilers are as long as they are in support. :)[^1.1]

## C Standard
In Carnival, we use __C99__[^2] standard.

## Build
*Please be aware, if you want to use your own compiler, then you need to check file "config.sh" first, in order to set proper environment variables.*

0. ### Configure
   * #### Edit `config.sh` until satisfied. :)[^1.1]
0. ### Build
   * #### Input "make" within your terminal.
   * #### Wait until above command is done.
   * #### Input "./Carnival" to execute.
0. ### Done
   * #### _~~What more do ya want?~~_ Enjoy!

## DevLog
__\[6th Mar, 2023\]__  
Due to project code responsibility allocation controversial issue, previous "Carnival" or "Carnival_MinGW" and "Carnival_GNU" are found ambiguous to be continued on development.  
Thus, we created a new repository for dividing job responsibility, for Carnival, for all.

We will not change our original promise in file README from previous storage.  
Here they are:

>\[31st Jan, 2023\]  
>Carnival is currently in development, this project will roughly go on the stage with polish in about 6 more months(in the worst scenario).
>
>For development, Carnival is now divided into two parts for multi-platform performance.  
>They are:
>  - Carnival_MinGW
>  - Carnival_GNU  
>
>The MinGW one is obviously majorly for Windows;  
>The GNU one is yet again, apparently mostly for GNU/Linux;
>
>BTW, if you'd like to have C/CXX compilers on Android, there's my project [Attraction (Early development stage)](https://github.com/WilliamPascal/Attraction).
>If there were any questions, please contact via e-mail at "williampascal_official@outlook.com". I might not be reply in time, thank you.

## Trouble shooting
Q0: What license does this project hold?  
A0: [GPL 3.0](https://www.gnu.org/licenses/gpl-3.0.en.html)

Q1: What does this project do?  
A1: ~~It's currently unemployed.~~  
A1: I mean, it could help users with following:
* Date & Time calculator
* Powerful Scheduler
* Todo list with lang...  

Didn't I just declared all these in section [Features](#Features)?  
A0: Yep.

Q2: Can I modify this project?  
A2: Yes, you can. :)[^1.1]  
__But__, only to improve. ;)[^1.2]

Q3: What is [ASCII](https://computersciencewiki.org/index.php/ASCII)?  
A3: Thank you, that will be all.

Q4: How do I ~black~mail ya? 😈  
A4: "williampascal_official@outlook.com" 😅

Q5: There were no matching questions here with mine.  
A5: Well, you can always put up an ***issue*** to ask. :)[^1.1]

Q6: How many faces drawn in ASCII are there?  
A6: 钝角

[^1]: Not the final decision. We are willing to use [Unicode](https://home.unicode.org/) in the short future.  
[^1.1]: A smiling face drawn in ASCII.  
[^1.2]: A smiling winking face drawn in ASCII.  
[^2]: [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html)  
