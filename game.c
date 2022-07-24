

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

double score_tally = 0;
int player_health = 100; 
char intro_choice[4];


//variable terminology reference for understanding
// sec_x = second encounter choice & the related choice from the previous instance


int first_encounter(void) {
    printf("Tashy must choose which path to embark on: (cave = c, scrap = s or blood = b) \r\n");
    char first_encounter_choice = fgetc(stdin);
    char *fec_pointer = &first_encounter_choice;
    double *st = &score_tally;

        if (*fec_pointer  == 'c') {
            printf("Our hero returns to her cabin to grab her sword and journeys to the distant cave. \r\n");
            *st += 1.25;
        }

        else if(*fec_pointer == 's') {
            printf("Tashy has decided to investigate this scrap and found that this was not bubby clothing. \r\n");
            *st += 1.75;
        }

        else if (*fec_pointer  == 'b') {
            printf("Tashy has decided to investigate the blood trail. \r\n");
            *st += 1.5;
        }
return 0;
}

//sec c,s & b are all encounters that stem from the first encoutner choice and lead the player down a unique path

int sec_c(void) {
        printf("tashy has followed the path to the entrance of an abandoned cave. \r\n");
        printf("It appears that this cave used to be inhabited but by what? \r\n");
        printf("The cave is inhabited by a gigantic bear which you were unaware of. you must roll to survive \r\n");
        char sec_str[4];
        scanf("%s",sec_str);
        char *ptr_sec_c_choice;
        ptr_sec_c_choice = sec_str; // this shouldn't work? maybe look into it. 
        double *st = &score_tally;

            //implements a random number generation attempting to rereate a d20 roll akin to D&D 
            if(strcmp (ptr_sec_c_choice, sec_str) == 0){
                srand(time(NULL));
                int roll = rand() % 21;
                int *roll_ptr;
                roll_ptr = &roll;
                printf("your roll was %i \r\n",roll);
                if (roll >= 10){
                    *st += 2.25;
                    printf("You have slain the bear and find a map in the cave to the elf city of balistrade \r\n");
                }
                else{
                    printf("you have died \r\n");
                }
            }

            //if you choose this it force exits you from the game cause you died.
            //if(*roll_ptr <= 8){
            //    printf("You're fuckin dead bucko");

            //}
          
            
return 0;
}

int sec_s(void) {
    char sec_str_s[4];
        scanf("%s",sec_str_s);
        char *ptr_sec_s_choice;
        ptr_sec_s_choice = sec_str_s; 
    double *st = &score_tally;
        printf("the scrap may not have been from bubby's clothing but it does have a unique texture. \r\n");
        printf("This fabric is rare and afforded explicitly by nobles and lords. \r\n");
        printf("You have an inkling of where this could be from however they are in opposite directions. \r\n");
        printf("Which city do you choose to investigate: balistrade = b or vigh darum = v \r\n");
        

            if (strcmp (ptr_sec_s_choice, sec_str_s) == 0){
                printf("You have elected to visit the legendary elven weavers of Balistrade. \r\n");
                *st += 111; //placeholder st values 
            }

            else if (strcmp (ptr_sec_s_choice, sec_str_s) == 1){
                printf("You have elected to visit the dwarven capital of vigh darum \r\n");
                *st += 111; //placeholder st values
            }
        
    
return 0;
}

int sec_b(void){
        printf("tashy has followed the trail to a wooded area she looks around to see the following \n");
        printf("a broken sword submerged in a pool of water \r\n");
        printf("a streak of blood on a nearby tree \r\n");
        printf("What would you like to investigate? Sword or Blood \r\n");
        //printf("%f \n",score_tally);

        char sec_str_b[5];
        scanf("%4s",sec_str_b);
        char *ptr_sec_b_choice;
        ptr_sec_b_choice = sec_str_b;

            if (strcmp (ptr_sec_b_choice, sec_str_b) == 0){
                printf("The broken sword is bubbies, there is a shiny object in the water next to it. You collect the object to see it is a dwarven necklace. you decide to travel to the dwarven capital to find its maker. \r\n");
                *st += 111; //placeholder
            }

            else if(strcmp (ptr_sec_b_choice, sec_str_b) == 1){
                printf("You can't figure out where the blood is from but you see foot prints leading into a dark cave. \r\n");
                printf("In the cave is a pit of spikes, this was a trap set by goblins. You are dead. \r\n ");
                *st += 111; //placeholer
            }
        
    
return 0;
}

// thir encounter choice will piggy back off of the second and begin the filtering towards one of two endings

int tec_balistrade(){
    printf("After a 100 mile journey to the golden fields of Balistrade you encounter a guard at the portal to the city. \r\n");
    printf("Halt! Shouts a guard. State your business in these lands \r\n");
    printf("I have come to investigate the disappearance of my beloved you say as you draw the scrap of cloth from your bag. \r\n");
    printf("The guard inspects the fabric and requests to know from whence you hail, yu oblige the request and the guard grants you entry \r\n");
    printf("I suggest you pay a visit to the lord warden, he oversees all investigations and prosecutions in this realm. \r\n");
    *st += 111; //placeholder


return 0;
}

int tec_cave(){
    printf("You take the map you found and decide to head to balistrade \r\n");
    printf("THe Journey is arduous and will require you to walk for 100 miles \r\n");
     *st += 111; //placeholder
return 0;
}

int tec_vigh(){
    printf("After an arduous trek into the northern mountains you are ambushed by a squad of dwarves \r\n");
    printf("They surround you and demand you tell them how you passed through the mountains and found the entrance to their home \r\n");
    printf("You state that you are investigating the disappearance of your beloved and have evidence which drew you here \r\n");
    printf("The dwarves investigate your evidence and state that you would need to speak with the clan leader as he would be able to assist. \r\n");
     *st += 111; //placeholder
return 0;
}


// fourth encounter will be the last point before the game begins to wind down. 

int fourthec_lord_warden(){
    printf("You are granted entrace to the office of the lord warden. It is ornate yet practical. Beautiful and brutal.");
    printf("The warden sits behind a desk of Ancient oak wood and stares at you silently.");
    printf("What have you come to me seeking traveller? the warden says");
    printf("My love has disappeared and I have discovered evidence which leads me here. *you hand over the cloth*");
    printf("The warden stares at the fabric in shock. This cloth has not been woven since the unification of races. There can be only one culprit.");
    printf("Your culprit is the dragon parthanax. he resides in the stone vaults of Belgorod");
    printf("If this is true and the threat you face yet lives you will need to take a relic of our people.");
    printf("You have been given Chartreuse, the elf sword of legend. your mission soon comes to a close a you must battle Parthanax.");
     *st += 111; //placeholder

return 0;
}


int fourthec_clan_leader(){
    printf("The hearthguard takes you to the chambers of the clan leader, you cross from the sunlit mountains into a brutalist cave");
    printf("The heat of the forges is sweltering, the dwarves seem unaffected, you do not wish to stay here any longer than neccesary.");
    printf("Entering the foremans office of the Clan Leader you see a short and robust dwarf with a mountainous beard.");
    printf("Oi laddie, my scouts tell me of a message ye have for me? Spit it out before I lose interest.");
    printf("you tell the clan leader about the scrap you found.");
    printf("If what you have said is accurate then You are fighting an enemy that the realm has thought dead for an age, if you are to battle Dolthalum...");
    printf("You will need the axe of our forefathers, we will expect this returned once you conclude this quest please sign a contract of binding agreement.");
     *st += 111; //placeholder


return 0;
}

//fifth encounter will lead towards a dragon 
int fifthenc_journey(){
    printf("you have been grandted a legendary weapon by your sponsor. They told you the path to the stone vaults.");
    printf("Outfitted you with the strongest armor and provided you with an invisibility cloak. You are ready for the Dragon and to rescue bubby");
    *st += 111; //placeholder

return 0;
}

//sixth encounter is the fight with the dragon



//7th encounter is the resolution and ending
int final_enc(){
    printf("you have slain parthanax, bubby has been saved and you journey back to your cabin to contiue work on your estate happily ever after.");
return 0;
}


int main(void){


//intro to the game
printf("are you ready to embark on this adventure? \n");
gets(intro_choice);

if (*intro_choice == 'y'){
    printf("now begins the journey of the legendary quest dragon tashy! \n");
    score_tally++;
}
else {
    printf("I am sorry you were not ready to become a legend \n");
    score_tally--;
}

//first choice
printf(" open: our hero tashy stands alone in a forest. \n");
printf(" she is gathering medicines for an upcoming quest to slay a terrible stone dragon. \n");
printf(" who has terrorized a keep to the north. \n");
printf(" Suddenly she hears bubby scream in the distance. \n"); 
printf(" She rushes to the site of the noise to see bubby gone, only a scrap of clothing left on a nearby bramble. \n");

if (score_tally == 1){
    first_encounter();
}

//second choices

if (score_tally == 2.25){
    sec_c();
}

if (score_tally == 2.5){
    sec_b();
}

if (score_tally == 2.75){
    sec_s();
}
//third choice
if (score_tally == 111){
    tec_balistrade();//placeholders
}

if (score_tally == 111){
    tec_cave();//placeholders
}

if (score_tally == 111){
    tec_vigh();//placeholders
}

if (score_tally == 111){
    fourthec_lord_warden();//placeholders
}

if (score_tally == 111){
    fourthec_clan_leader();//placeholders
}

if (score_tally == 111){
    fifthenc_journey();//placeholders
}


return 0;
}