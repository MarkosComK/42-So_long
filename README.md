<h1 align="center"> 42Cursus so_long </h1>

<p align="center">
<img alt="so_long" src="https://github.com/user-attachments/assets/12029da6-0667-4a64-970e-df681c40cc48">
</p>
<p align="center">Development repo for 42Cursus so_long project</p>

## This project is in progress. Keep looking!

<div align="center">
	<img src="https://github.com/MarkosComK/42-Libft/assets/67120870/10a2a298-340e-4a67-96bd-d97716a60526">
</div>

## Index
* [What is so_long?](#what-is-so_long)
* [Requirements](#requirements)
* [How does it work?](#how-does-it-work)
	* [Maps](#maps)	
	* [Controls](#controls)
* [How do I test it?](#how-do-i-test-it)
* [42 Cursus](#42-cursus)
* [Author](#author)

<h2 align="center" id="what-is-so_long"> What is so_long? </h2>

The fifth project at 42 programming school.
It's the first graphical project in the <a href="https://github.com/MarkosComK/42-Common-Core-Guide">Cursus</a>, we can choose between 3 options - FdF, Fractol and so_long - that in general
cover different areas, but all 3 are graphical projects. The so_long consists of a top-down game, which we code from scratch using
the MiniLibx graphical library. It involves a series of validations from the map that is passed as argument,
checks to prevent memoy leaks, the game engineering, managing windows, events, sprites and maps.
	
<h2 align="center" id="requirements"> Requirements </h2>

<p  align="center"> :warning: The project must be written in accordance with the <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a> </p>
The Norm  is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and
to any project where it's specified. These are some of them:

    Each function must be maximum 25 lines, not counting the function's own curly brackets.
    
    Each line must be at most 80 columns wide, comments included.
    
    A function can take 4 named parameters maximum.
    
    You can't declare more than 5 variables per function.
    
    You're not allowed to use: for , do...while , switch , case ,  goto  ,
    ternary operators such as `?' and VLAs - Variable Length Arrays.
  The norminette (as we call the norm at 42) is in python and open source.
  
  Its repository is available at https://github.com/42School/norminette.
    
<h2 align="center" id="how-does-it-work"> How does it work? </h2>

You'll be able to play once you install the <a href="https://github.com/42Paris/minilibx-linux">MiniLibx</a> features or if you're using one of the machines at 42.

To play, first compile the project with make:

	make
	
In case you wanna play the bonus version:

	make bonus
	
So, run ./so_long followed by the map:
	
```sh
	./so_long maps/valid/valid2.ber
```

For bonus:

```sh
	./so_long_bonus maps/bonus_cluster.ber
```
	
<h3 id="maps" align="center"> Maps </h3>   
You can parse any kind of map, as long as it respects the below rules:

The map must be a .ber file.

And can only contain these characters:
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Wall   |
| C	        | Coin |
| E	        |   Exit  |
| P         |   Player  |      
| 0         |   Floor     |
    
For bonus there's an extra character - which makes you lose once touch it.
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| H         |   Enemy  |


The map must be rectangular and surrounded by walls '1'.

The map must contain at least one exit, one collectible, and one starting position.

Check some examples in the folder /assets/maps.
	
As in assets/maps/valid/map2.ber:

<img src="HERE THE MAP IMG FOR EXAMPLE">

This .ber file generates this map:
    
    
<img src="HERE MAP IMG">
	
<h3 id="controls" align="center"> Controls </h3>   
    
| KEY |	OBJECT   |
| --------- | ---------- |
| W or ⬆️        |    Move up   |
| A	or ⬅️        |    Move left |
| S	or ⬇️     |    Move down   |
| D or ➡️       |   Move para right|      
| Q or Esc      |   Close the game     | 
    
    
Use WASD or arrow keys to move.
	
	
After getting all the coin bags, the exit opens and you can escape downstairs.
	
You can close the game by Clicking on the red cross on the window’s frame, or pressing Q or Esc.
	
<h2 align="center" id="how-do-i-test-it"> How do I test it? </h2>  

To test the game itself it's recommendable to run it with some different maps and try things like:

Running into a wall and see if you're blocked or if the movements counter increase while you're stucked.

Go to the exit without collecting all the coins.

Go through the same path at least one time.

Try to move with the arrow keys and with WASD.

Check if the window closes when clicking the red cross on window's frame, same with Esc or Q.

Try to minimize the window and open it again.

Run the project with Valgrind to see if there's any memory leak.

To test some map validations as
No map, missing argv, multiple argv, invalid extension, map with an empty line, invalid map parameter
missing W parameter, missing C parameter, missing E parameter, missing P parameter, extra P parameter
I used augustobecker tester [Tester](https://github.com/augustobecker/so_long_tester).

To test the code in this repo Clone this repo and cd into it:

```sh
git clone https://github.com/augustobecker/so_long

cd so_long/
```
Now, clone the Tester

```sh
git clone https://github.com/augustobecker/so_long_tester
```

Go into the test folder and run with make:

```sh
cd so_long_tester
make
```

If you did everything correctly you should see something like this


<h2 align="center" id="42-cursus"> 42 Cursus </h2>
	
42 is a global education initiative that proposes a new way of learning technology: no teachers, no classrooms,
students learning from their fellow students (peer to peer learning),
with a methodology that develops both computing and life skills.
Not to mention that it's completely free of charge and open to all with no prerequisites.

Admissions at 42 are unlike other colleges. We use a merit-based admission process.
The final step of the admission is the Piscine - This is part of the admissions process and 
requires 4 weeks of intensive and immersive coding. No prior coding experience is necessary at all.
	
You can check more about the admission process on the 42porto website: https://www.42porto.com.

To see other projects developed by me at 42, click here: <a href="https://github.com/MarkosComK/">My Profile</a>
	
<h2  align="center" id="author">Author</h2>
<div align="center">
	<div>
	<img width="200" src="https://github.com/user-attachments/assets/7f5d1839-bd82-44e8-aa06-168ea71ca392">
	</div>
	<div>
		<strong> Markos Santos | marsoare | 🇧🇷👨‍🚀</strong>

#### DO YOU KNOW ABOUT .BFE FILES?

file.bfe:VAA0DAYFf07ym3ROeASsmsgnY0o0sDMJev7zFHhwQ
S8mvM8V5xQQpLc6cDCFXDWTiFzZ2H9skYkiJ/DpQtnM/uZ0
