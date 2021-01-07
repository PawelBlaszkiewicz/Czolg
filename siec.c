#include "siec.h"
 
static size_t WriteMemoryCallback(void *data, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  Memory *mem = (Memory *)userp;

  char *ptr = NULL;
 
 if(mem->response !=NULL)
 {  
     ptr = realloc(mem->response, mem->size + realsize + 1);
 }
 else
 {
     ptr=malloc(mem->size + realsize + 1);
 }

  if(ptr == NULL) 
  { 
    printf("brak pamięci\n");
    return 0;
  }
 
  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;
 
  return realsize;
}

cJSON *make_request(char *token) // tu mozna zwracać cjsona coułati zwalnianie pamieci
{ 
  CURL *curl;
  CURLcode res;
  Memory chunk; 
  chunk.size = 0;   
  chunk.response=NULL;  
  cJSON *xd=(cJSON*) malloc(sizeof(cJSON));
 
  curl = curl_easy_init();
 if(curl)
 {
  
  curl_easy_setopt(curl, CURLOPT_URL, token); 
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); 
  curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
 
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

  res = curl_easy_perform(curl);
  
  if(res != CURLE_OK) {
    fprintf(stderr, "Błąd! curl_easy_perform() niepowodzenie: %s\n",curl_easy_strerror(res));
  }
  else {
    //strncpy(aps, &chunk.response[178], 224);
    //printf("%s\n", aps);
    //   printf("%s", chunk.response);
  }
 
  curl_easy_cleanup(curl);
 }

 xd = cJSON_Parse(&chunk.response[178]);
  free(chunk.response);
 return xd;

}