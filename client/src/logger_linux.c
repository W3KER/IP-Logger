#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h> 
#include <unistd.h>
 
#define MAX_NAME 32
#define MAX_IP 39
#define DEFAULT_SERVER "http://0th.me/iplogger/"
#define DEFAULT_INTERVAL 1000*60*50

int curl(char *server, char *name, char *ip) {
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
    
  char * url = malloc(MAX_IP + MAX_NAME + strlen(server));
  if(curl) {
      
    sprintf(url, "%s?name=%s&ip=%s",server,name,ip);
    printf("%s\n",url);
       
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);  
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  free(url);
  return 0;    
}

int main(int argc, char *argv[])
{
  FILE *fp;
  char str[1035];
  char name[MAX_NAME], ip[MAX_IP];
  char * server;
  int hostLen;
    
//  while(1) {    
      fp = popen("ifconfig", "r");
      if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
      }

      server = argc>1? argv[1]: DEFAULT_SERVER; 
      gethostname(name, MAX_NAME);
      name[hostLen = strlen(name)] = '_';
      while (fgets(str, sizeof(str), fp) != NULL) 
        if(str[0] != '\t') 
            memcpy(name + hostLen + 1, strtok(str,":"), MAX_NAME);
        else if(!memcmp(str, "\tinet ",6)) 
            curl(server, name, memcpy(ip, strtok(str+5, " "),MAX_IP));

      pclose(fp);
          
//      sleep(DEFAULT_INTERVAL);      
//  }
      
  return 0;
}
