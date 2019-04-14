char *str_cat(char *str1, char *str2){

    int i, c, f=0;

    for(i=0;str1[i]!='\0';i++){}
    for(c=i;str2[f]!='\0';c++){
        str1[c] = str2[f];
        f++;
    }

    return str1;
}

char *str_cpy(char *str1, char *str2){

	int i = 0;

    while(1){

        if(str2[i] == '\0'){
            break;
        }

        str1[i] = str2[i];
        i++;
    }

	return str1;
}

long int str_len(char *str1){

    int i;

    for(i=0;str1[i]!='\0';i++){}

    return i;
}

long int str_cmp(char *str1, char *str2){

	int i = 0;

    while(1){

        if(str1[i] == str2[i]){
            i++;

        if(i == sizeof(str1)) return 0;
        }
        else{
            return 1;
       }
    }
}


