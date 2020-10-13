#include <stdio.h>
#include <stdlib.h>

//Structure for the pageFrame to easily hold the counter and page number for each pageFrame
struct pageFrame {
    unsigned int counter;	// 8 bits
    int page_number;
} *pageFrame;


// Global Variables
// numberOfPageFrames - to save number of page frames that user specified in the argument
// hits - number of hits
// misses - number of misses
long numberOfPageFrames;
long hits = 0;
long misses = 0;

//Ageing algorithm
void update_page_frames(int current_page) {
    long index_for_lowest_value_counter = 0;
    for (long i = 0; i < numberOfPageFrames; i++) {
        if (pageFrame[i].counter < pageFrame[index_for_lowest_value_counter].counter) {
            index_for_lowest_value_counter = i;
        }
        if (pageFrame[i].page_number == current_page) {
            // Hit
            pageFrame[i].counter = pageFrame[i].counter | (1 << 7);  //adding 1 to the leftmost bit of the counter
            hits++;
            return;
        }
    }

    //If the program reached here it means that we have miss
    misses++;
    pageFrame[index_for_lowest_value_counter].counter = 1 << 7;  //set counter to the 1000 0000(since it was just added)
    pageFrame[index_for_lowest_value_counter].page_number = current_page;
}


int main(int argc, char *argv[]) {
    //Checking if the user entered exactly 1 argument
    if(argc > 2 || argc < 2){
        printf("Error! You inserted more or less than 1 arguments. But you need to insert exactly 1 arguments!");
        return 1;
    }

    //Making form
    char *endptr;
    numberOfPageFrames = strtol(argv[1], &endptr, 10);

    // Allocate memory for the Page Frames
    pageFrame = malloc(numberOfPageFrames*sizeof(struct pageFrame));
    // Initialize counter and page_number for each pageFrame
    for (long i = 0; i < numberOfPageFrames; i++) {
        pageFrame[i].counter = 0;
        pageFrame[i].page_number = -1;
    }

    // Go through the file and run ageing algorithm
    FILE *input;
    input = fopen("highMissRate.txt", "r");
    int current_page;
    while (fscanf(input, "%d", &current_page) != EOF) {
        update_page_frames(current_page);
    }

    printf("Hits: %ld\n", hits);
    printf("Misses: %ld\n", misses);
    printf("Ratio hits to misses: %f\n", hits/(double)misses);


    return 0;
}
