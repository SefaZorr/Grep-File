#include<stdio.h>
#include<string.h>


int Search(char *str, char *fname);
int Usage(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	int result;

	if(Usage(argc, argv) == -1){
        return -1;
    }

	result = Search(argv[1], argv[2]);
	if(result == -1) {
		printf("Error occurs");
	}
	return(0);
}

int Usage(int argc, char *argv[])
{
    if(argc==1){
        printf("grepFile: No arguments given, please enter file name and search string in order\n");
        return -1;
    }
    if(argc == 2){
        printf("grepFile: Missing argument\n");
        return -1;
    }
    else if(argc>3){
        printf("grepFile: Too many arguments\n");
        return -1;
    }
    return 0;
}

int Search(char *fname, char *str) {
	FILE *fp, *fp2;
	int line_num = 1;
	int find_result = 0;
	char temp[1000];
	

	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}

	if((fp2 = fopen("output.txt", "a")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 1000, fp) != NULL) { //fp'den okuduklarini temp isimli diziye atiyor. 1000 ise dosyadan okunacak karakter sayisini gosteriyor.
		if((strstr(temp, str)) != NULL) {
			find_result++;
			fprintf(fp2, "Bulunduğu Satır: %d\n %s\n", line_num, temp);
		}	
		line_num++;			
	}
	
	
	printf("Aradiginiz kelime %d adet bulundu.\n",find_result);

	if(find_result == 0) {
		printf("Malasef bir eslesme bulunamadi.\n");
	}
	
	if(fp) {
		fclose(fp);
	}

	if(fp2) {

		fclose(fp2);
	}

   	return (0);
}