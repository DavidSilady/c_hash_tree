//
// Created by david on 11/6/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "tester.h"
#include <time.h>
#include <math.h>
#include "github_src/stolen_tree/rbtree.c"
#include "github_src/stolen_hash/hashtab.c"

#define DEBUG 10000
#define MAX_STACK 40000
#define OUTPUT "C:/Users/david/CLionProjects/trees/test.log"

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int *read_input(char file_name[49], int input_size) {
    int *input = malloc(input_size * sizeof(int));
    FILE *file;
    file = fopen(file_name, "r");

    for (int i = 0; i < input_size; ++i) {
        fscanf(file, "%d", &input[i]);
    }

    fclose(file);
    return input;
}

void insert_test_my_hash(Hash *hash, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed = 0;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        if (i % DEBUG == 0) {
            double split_time = time_elapsed;
            end = clock();
            time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            split_time = time_elapsed - split_time;

            fprintf(output, "%5d. inserted | Split time: %lf | ", i, split_time);
            fprintf(output, "Total time elapsed: %lf\n", time_elapsed);
        }

        hash_add(hash, array[i]);
    }
    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    fprintf(output, "Time elapsed (My Hash Insert): %lf\n", time_elapsed);
    fclose(output);
}

void find_test_my_hash(Hash *hash, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        Node *node = hash_find(hash, array[i]);
    }
    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (My Hash Find): %lf\n\n", time_elapsed);
    fclose(output);
}

void find_test_stolen_hash(hashtab_t *hash, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        ht_search(hash, &array[i], sizeof(int));
    }
    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (Stolen Hash Find): %lf\n\n", time_elapsed);
    fclose(output);
}

void insert_test_stolen_hash(hashtab_t *hash, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed = 0;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        if (i % DEBUG == 0) {
            double split_time = time_elapsed;
            end = clock();
            time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            split_time = time_elapsed - split_time;

            fprintf(output, "%5d. inserted | Split time: %lf | ", i, split_time);
            fprintf(output, "Total time elapsed: %lf\n", time_elapsed);
        }

        ht_insert(hash, &array[i], sizeof(int), &array[i], sizeof(int));
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (Stolen Hash Insert): %lf\n", time_elapsed);
    fclose(output);
}

void insert_test_stolen_tree(rbtree rb_tree, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed = 0;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        if (i % DEBUG == 0) {
            double split_time = time_elapsed;
            end = clock();
            time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            split_time = time_elapsed - split_time;

            fprintf(output, "%5d. inserted | Split time: %lf | ", i, split_time);
            fprintf(output, "Total time elapsed: %lf\n", time_elapsed);
        }

        rbtree_insert(rb_tree, (void *)&array[i], compare_int);
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (Stolen Tree Insert): %lf\n", time_elapsed);
    fclose(output);
}

void find_test_stolen_tree(rbtree rb_tree, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed = 0;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        rbtree_lookup(rb_tree, (void *)&array[i], compare_int);
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (Stolen Tree Find): %lf\n\n", time_elapsed);
    fclose(output);
}

void insert_test_my_tree(Tree *tree, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed = 0;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        if (i % DEBUG == 0) {
            double split_time = time_elapsed;
            end = clock();
            time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            split_time = time_elapsed - split_time;

            fprintf(output, "%5d. inserted | Split time: %lf | ", i, split_time);
            fprintf(output, "Total time elapsed: %lf\n", time_elapsed);
        }

        insert(tree, array[i]);
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (My Tree Insert): %lf\n", time_elapsed);
    fclose(output);
}

void insert_test_my_bvs_tree(Tree *tree, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed = 0;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        if (i % DEBUG == 0) {
            double split_time = time_elapsed;
            end = clock();
            time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            split_time = time_elapsed - split_time;

            fprintf(output, "%5d. inserted | Split time: %lf | ", i, split_time);
            fprintf(output, "Total time elapsed: %lf\n", time_elapsed);
        }
        bvs_insert(tree, array[i]);
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (My BVS Tree Insert): %lf\n", time_elapsed);
    fclose(output);
}

void find_test_my_tree(Tree *tree, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        Node *node = find_value(tree, array[i]);
        if (node == NULL)
            printf("%d | ", array[i]);
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (My Tree Find): %lf\n\n", time_elapsed);

    fclose(output);
}

void find_test_my_bvs_tree(Tree *tree, int array_size, int *array) {
    FILE *output = fopen(OUTPUT, "a");

    clock_t start, end;
    double time_elapsed;

    start = clock();

    for (int i = 0; i < array_size; ++i) {
        Node *node = find_value(tree, array[i]);
    }

    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "Time elapsed (My BVS Tree Find): %lf\n", time_elapsed);

    fclose(output);
}

int *generate_array(int max_value, int min_value, int size) {
    max_value = floor(sqrt(max_value));
    int *array = malloc(size * sizeof(int));
    //srand(time(0));
    for (int i = 0; i < size; ++i) {
        int a = (rand() % (max_value - min_value + 1)) + min_value;
        int b = (rand() % (max_value - min_value + 1)) + min_value;
        array[i] = a * b;
    }
    printf("Generated\n\n");
    return array;
}

int *generate_consecutive_array(int array_size) {
    int *array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; ++i) {
        array[i] = i;
    }
    return array;
}

void test(int *array, int array_size) {
    rbtree rb_tree = rbtree_create();
    hashtab_t *hash_tab = ht_init(16, NULL);
    Tree *tree = new_tree();
    Tree *bvs_tree = new_tree();
    Hash *hash = new_hash(8);
/*
    insert_test_stolen_hash(hash_tab, array_size, array);
    find_test_stolen_hash(hash_tab, array_size, array);
    ht_destroy(hash_tab);
    printf("Stolen hash completed.\n");

    insert_test_stolen_tree(rb_tree, array_size, array);
    find_test_stolen_tree(rb_tree, array_size, array);
    for (int i = 0; i < array_size; ++i) {
        rbtree_delete(rb_tree,  (void *)&array[i], compare_int);
    }
    printf("Stolen tree completed.\n");

    insert_test_my_hash(hash, array_size, array);
    find_test_my_hash(hash, array_size, array);
    hash_destroy(hash);
    printf("My hash completed.\n");
*/
    insert_test_my_tree(tree, array_size, array);
    find_test_my_tree(tree, array_size, array);
    destroy_tree(tree);
    printf("My tree completed.\n");

    insert_test_my_bvs_tree(bvs_tree, min(array_size, MAX_STACK), array);
    find_test_my_bvs_tree(bvs_tree, array_size, array);
    destroy_tree(bvs_tree);
    printf("My bvs tree completed.\n");
}

void small_test() {
    const int array_size = 100000;
    //int *random_array = read_input("C:\\Users\\david\\CLionProjects\\trees\\test1.txt", array_size);
    int *random_array = generate_array(array_size, 0, array_size);
    FILE *output = fopen(OUTPUT, "a");
    fprintf(output, "\n\nRandom Array:\n");
    fclose(output);
    test(random_array, array_size);
    free(random_array);

    output = fopen(OUTPUT, "a");
    fprintf(output, "\n\nConsecutive Array:\n");
    fclose(output);
    int *consecutive_array = generate_consecutive_array(array_size);
    test(consecutive_array, array_size);
    free(consecutive_array);
    printf("Completed.");
}












