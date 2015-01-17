
#include <stdio.h>
#include <malloc.h>
#include <string.h>

/**
 * The type u1 represent an unsigned one-byte quantity
 *
 *
 */
typedef unsigned char u1;

/**
 * The type u2 represent an unsigned two-byte quantity
 *
 */
typedef unsigned short u2;

/**
 * The type u4 represent an unsigned four-byte quantity
 *
 */
typedef unsigned long u4;

/**
 *
 *
 *
 */
typedef struct cp_info {
    	u1 tag;
    	u1 info[];
} __cp_info;

/**
 *
 *
 *
 */
struct ClassFile {

	u4 magic;

	u2 minor_version;
	u2 major_version;

	u2 constant_pool_count;
	struct cp_info *constant_pool; //constant_pool[constant_pool_count-1];
    	
	u2 access_flags;
    
	u2 this_class;
    	
	u2 super_class;
    	
	u2 interfaces_count;
	u2 interfaces[/*interfaces_count*/];
};

/**
 *
 *
 */
typedef struct ClassFile __class, __class_file;


void main() {
	char *class_file = (char *) malloc(256 * sizeof(char));
	char a[9];
	char b[] = {'a', 'b', 'c', 'd', 'e'};

	printf("%d\n", sizeof(a));
	printf("%d\n", strlen(a));

	printf("%d\n", sizeof(b));
	printf("%d\n", strlen(b));

	printf("%d\n", sizeof(class_file));
	printf("%d\n", strlen(class_file));

	printf("%d\n", sizeof(*class_file));
	//printf("%d\n", strlen(*class_file));

	printf(">.class file: ");
	gets(class_file);
	//scanf("%s", class_file);
	/*
	int i, ch;
	for (i = 0; (i < 256) && ((ch = getchar()) != EOF) && (ch != '\n'); i++) {
		class_file[i] = ch;
	}
	*/

	printf(">>.class file: %s\n", class_file);
	FILE *f = fopen(class_file, "r");
	if (f == NULL) {
		printf(">>Error to open file: %s\n", class_file);
	} else {
		printf(">>OK to open file: %s\n", class_file);
	}

	if (f != NULL) {
		__class c;

		unsigned long magic = 0;
		unsigned short minor_version = 0;
		unsigned short major_version = 0;
		unsigned short constant_pool_count = 0;
		int i = fseek(f, 0, SEEK_SET);
		if (i == 0) {
			for (int j = 4; j > 0; j--) {
				unsigned int ch = fgetc(f);
				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				ch <<= 24;
				ch >>= 8 * (4 - j);
				
				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				magic += ch;

			}
			printf(">>Magic: %d--%u--%x\n", magic, magic, magic);
			c.magic = magic;

			for (j = 2; j > 0; j--) {
				unsigned int ch = fgetc(f);
				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				ch <<= 8;
				ch >>= 8 * (2 - j);

				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				minor_version += ch;
			}
			printf(">>Minor Version: %d--%u--%x\n", minor_version, minor_version, minor_version);
			c.minor_version = minor_version;

			for (j = 2; j > 0; j--) {
				unsigned int ch = fgetc(f);
				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				ch <<= 8;
				ch >>= 8 * (2 - j);

				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				major_version += ch;
			}
			printf(">>Major Version: %d--%u--%x\n", major_version, major_version, major_version);
			c.major_version = major_version;

			for (j = 2; j > 0; j--) {
				unsigned int ch = fgetc(f);
				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				ch <<= 8;
				ch >>= 8 * (2 - j);

				printf(">>Read: %d--%u--%x\n", ch, ch, ch);
				constant_pool_count += ch;
			}
			printf(">>Constant Pool Count: %d--%u--%x\n", constant_pool_count, constant_pool_count, constant_pool_count);
			c.constant_pool_count = constant_pool_count;
		}

		i = fclose(f);
		if (i != 0) {
			printf(">>Error to close file: %s\n", class_file);
		} else {
			printf(">>OK to close file: %s\n", class_file);
		}
	}

}