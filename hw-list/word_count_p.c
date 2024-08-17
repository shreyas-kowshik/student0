/*
 * Implementation of the word_count interface using Pintos lists and pthreads.
 *
 * You may modify this file, and are expected to modify it.
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

#ifndef PINTOS_LIST
#error "PINTOS_LIST must be #define'd when compiling word_count_lp.c"
#endif

#ifndef PTHREADS
#error "PTHREADS must be #define'd when compiling word_count_lp.c"
#endif

#include "word_count.h"

void init_words(word_count_list_t* wclist) { /* TODO */
  list_init(&(wclist->lst));
  int rc = pthread_mutex_init(&(wclist->lock), NULL);
  if(rc) {
    printf("ERROR; return code from pthread_mutex_init() is %d\n", rc);
    exit(-1);
  }
}

size_t len_words(word_count_list_t* wclist) {
  /* TODO */
  int ans = 0;

  struct list_elem *e;

  for(e = list_begin(&(wclist->lst)); e != list_end(&(wclist->lst)); e = list_next(e)) {
    word_count_t *wc = list_entry(e, word_count_t, elem);
    ans+=(wc->count);
  }

  return 0;
}

word_count_t* find_word(word_count_list_t* wclist, char* word) {
  /* TODO */
  struct list_elem *e;
  word_count_t* ans = NULL;

  for(e = list_begin(&(wclist->lst)); e != list_end(&(wclist->lst)); e = list_next(e)) {
    word_count_t* cur = list_entry(e, word_count_t, elem);
    if(strcmp(cur->word, word)==0) {
      ans = cur;
      break;
    }
  }

  return ans;
}

word_count_t* add_word(word_count_list_t* wclist, char* word) {
  /* TODO */
  // pthread_mutex_lock(&(wclist->lock));
  // printf("Adding word %s\n", word);
  word_count_t* wc_word = find_word(wclist, word);
  if(wc_word) {
    wc_word->count = (wc_word->count) + 1;
  }
  else {
    wc_word = (word_count_t*)malloc(sizeof(word_count_t));
    /*
    Extremely important step
    Since the original pointer is freed in `pwords.c`, very important to create a copy here  
    */
    char *dst = (char *)malloc(sizeof(word));
    strcpy(dst, word);

    wc_word->word = dst;
    wc_word->count = 1;
    list_push_back(&(wclist->lst), &(wc_word->elem));
  }
  // pthread_mutex_unlock(&(wclist->lock));
  return wc_word;
}

void fprint_words(word_count_list_t* wclist, FILE* outfile) { /* TODO */
  struct list_elem *e;
  for(e = list_begin(&(wclist->lst)); e != list_end(&(wclist->lst)); e = list_next(e)) {
    word_count_t* wc = list_entry(e, word_count_t, elem);
    fprintf(outfile, "%i\t%s\n", wc->count, wc->word);
  }
}

static bool less_list(const struct list_elem* ewc1, const struct list_elem* ewc2, void* aux) {
  /* TODO */
  bool (*aux_ptr)(word_count_t*, word_count_t*) = aux;
  word_count_t *wc1 = list_entry(ewc1, word_count_t, elem);
  word_count_t *wc2 = list_entry(ewc2, word_count_t, elem);
  return aux_ptr(wc1, wc2);
}

void wordcount_sort(word_count_list_t* wclist,
                    bool less(const word_count_t*, const word_count_t*)) {
  list_sort(&(wclist->lst), less_list, less);
}
