#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char**argv){
	int 
		dflag =0,
		aflag =0,
		hflag =0;
	char *dvalue = NULL;
	int index;
	int c;
	opterr =0; 
	if( argc ==1 ){
		printf("There aren't arguments\n");
		return 1;
	}
	while((c = getopt(argc, argv, "had:")) !=-1)
		printf("%c\n", c);
		printf("*dvalue: %s\n", dvalue);
		printf("*optarg: %s", optarg);
		switch(c)
		{
			case 'h':
				hflag = 1;
				break;
			case 'a':
				aflag = 1;
			case 'd':
				dflag = 1;
				dvalue = optarg;
				break;
			case '?':
				if(optopt == 'd')
					fprintf(stderr, "Option -%d requires an argument.\n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Unknown option -%d.\n", optopt);
				else
					fprintf (stderr, "Unknown option character \\x%x.\n", optopt);
				return 1;
			default:
				abort();
		
		}
	if(aflag)
		printf("aflag = %d, ", aflag);
	if(dflag)
		printf("dvalue = %s ", dvalue);
	if(hflag)
		printf("hflag = %d", hflag);
	
	for (index = optind; index < argc; index++)
		printf("Non-option argument %s\n", argv[index]);

	printf("\n");
	return 0;
	
}
