# Dining Philosophers
 - One or more philosophers sit at a round table.
    There is a large bowl of spaghetti in the middle of the table

 -  The philosophers alternatively eat, think, or sleep.
    While they are eating, they are not thinking nor sleeping;
    while thinking, they are not eating nor sleeping;
    and, of course, while sleeping, they are not eating nor thinking.

 - There are also forks on the table. There are as many forks as philosophers
 - Because serving and eating spaghetti with only one fork is very inconvenient, a 
    philosopher takes their right and their left forks to eat, one in each hand.

- When a philosopher has finished eating, they put their forks back on the table and
 start sleeping. Once awake, they start thinking again. The simulation stops when
 a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!
## How to use

Using make in the philo directory will create the philo executable. Same for philo_bonus.
You run it specifying, in order :

- The number of philosophers
- The time in milliseconds until a philosopher dies from starvation
- The time in milliseconds it takes for a philosopher to eat
- The time in milliseconds it takes for a philosopher to sleep
- (Optional) The number of meals before the program stops
```
./philo 8 410 200 100 7
```
Here, the program will create 8 philosophers, who will die if they go without eating for 410 milliseconds. It takes them 200 milliseconds to eat, and 100 milliseconds to sleep. The program will stop after each philosopher has had 7 meals (or if any one of them dies prematurely).
### Output

The program outputs every action with a timestamp (in milliseconds) and the philosopher's number.
### Additional information

For more information you can read the philosophers.subject.pdf. Before using my code for 42 school please double check the Norms.
