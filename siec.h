#ifndef _SIEC_H
#define _SIEC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

typedef struct Memory {
  char *response;
  size_t size;
}Memory;

static size_t WriteMemoryCallback(void *data, size_t size, size_t nmemb, void *userp);
cJSON *make_request(char *token);

#endif