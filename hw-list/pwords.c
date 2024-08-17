/*
 * Word count application with one thread per input file.
 *
 * You may modify this file in any way you like, and are expected to modify it.
 * Your solution must read each input file from a separate thread. We encourage
 * you to make as few changes as necessary.
 */

/*
 * Copyright © 2021 University of California, Berkeley
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>

#include "word_count.h"
#include "word_helpers.h"

void* threadfun(void* arg) {
  struct wc_thread_struct *wc = (struct wc_thread_struct*)arg;
  FILE* infile = fopen(wc->filename, "r");

  bool new_word=false;
  char *cur_word = NULL;

  do {
    char c = fgetc(infile);
    // printf("Read from file\n");
    if(feof(infile)) break;

    c = tolower(c);

    if(isalpha(c) && !new_word) {
      new_word=true;
      cur_word = (char*)malloc(sizeof(char));
      *cur_word = c;  
    }
    else if(isalpha(c)) {
      strncat(cur_word, &c, 1);
    }
    else if(!isalpha(c) && new_word) {
      new_word = false;
      pthread_mutex_lock(&(wc->word_counts->lock));
      add_word(wc->word_counts, cur_word);
      pthread_mutex_unlock(&(wc->word_counts->lock));

      // printf("Wrote word %s in file %s\n", cur_word, wc->filename);
      free(cur_word);
      cur_word = NULL;
    }
  }
  while(1);

  if (cur_word) {
    pthread_mutex_lock(&(wc->word_counts->lock));
    add_word(wc->word_counts, cur_word);
    pthread_mutex_unlock(&(wc->word_counts->lock));

    // printf("Wrote word %s in file %s\n", cur_word, wc->filename);

    free(cur_word);
    cur_word = NULL;
  }

  pthread_exit(NULL);
}

// void* threadfun2(void* threadid) {
//   long tid;
//   tid = (long)threadid;
//   printf("IN thread\n");
//   pthread_exit(NULL);
// }

/*
 * main - handle command line, spawning one thread per file.
 */
int main(int argc, char* argv[]) {
  /* Create the empty data structure. */
  word_count_list_t word_counts;
  init_words(&word_counts);

  // printf("%d\n", argc);

  if (argc <= 1) {
    /* Process stdin in a single thread. */
    count_words(&word_counts, stdin);
  } else {
    /* TODO */
    /*
    int rc;
    struct wc_thread_struct args;
    args.word_counts = &word_counts;
    args.filename = argv[argc-1];

    pthread_t _thread;
    rc = pthread_create(&_thread, NULL, threadfun, (void*)&args);
    if(rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
    */

    pthread_t threads[argc-1];
    int idx;
    for(idx = 1;idx < argc;idx++) {
      /* If one uses a non malloc appraoch here like `struct wc_thread_struct args`, the compiler
         may optimize that and use the same memory location for updating the output for multiple threads
         That will lead to issues since it is possible by the time the first thread starts work, the second
         thread has udpated the `args` structure to have `argv[2]` where `argv[1]` should be present
         Malloc ensures each time a new memory location is obtained, and moreover the original location
         still is unique as it is not freed
      */
      struct wc_thread_struct *args = malloc(sizeof(struct wc_thread_struct));
      args->word_counts = &word_counts;
      args->filename = argv[idx];

      int rc = pthread_create(&(threads[idx-1]), NULL, threadfun, (void*)args);
      if(rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
    }

    for(idx = 0;idx < argc-1;idx++)
      pthread_join(threads[idx], NULL);
  }

  /* Output final result of all threads' work. */
  wordcount_sort(&word_counts, less_count);
  fprint_words(&word_counts, stdout);
  return 0;
}
