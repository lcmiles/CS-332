#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINESIZE 1024

struct listing { //structure containing the varaibles of each item listing
	int id, host_id, minimum_nights, number_of_reviews, calculated_host_listings_count,availability_365;
	char *host_name, *neighbourhood_group, *neighbourhood, *room_type;
	float latitude, longitude, price;
};

struct listing getfields(char* line) { 
	struct listing item;

	//tokenize each line at each "," and add corresponding field to structure variables
	item.id = atoi(strtok(line, ","));
	item.host_id = atoi(strtok(NULL, ","));
	item.host_name = strdup(strtok(NULL, ","));
	item.neighbourhood_group = strdup(strtok(NULL, ","));
	item.neighbourhood = strdup(strtok(NULL, ","));
	item.latitude = atof(strtok(NULL, ","));
	item.longitude = atof(strtok(NULL, ","));
	item.room_type = strdup(strtok(NULL, ","));
	item.price = atof(strtok(NULL, ","));
	item.minimum_nights = atoi(strtok(NULL, ","));
	item.number_of_reviews = atoi(strtok(NULL, ","));
	item.calculated_host_listings_count = atoi(strtok(NULL, ","));
	item.availability_365 = atoi(strtok(NULL, ","));
	
	return item;
}

int cmpPrice(const struct listing *p1, const struct listing *p2) {

    return p1->price > p2->price; //compare the price of one structure to another using pointers to each, returning a 1 if the first is greater than the second

}

int cmpName(const struct listing *p1, const struct listing *p2) {

    return strcmp(p1->host_name,p2->host_name); //compare the host_name of one structure to another using pointers to each, returning a positive or negative number based on the ascii value comparison

}

int main(int argc, char* args[]) {
	struct listing list_items[22555];
	char line[LINESIZE];
	int i, count;

	FILE *file_in = fopen("listings.csv", "r"); //open input file with read only flag
	
	if(file_in == NULL){ //error code if no file descriptor
		printf("Error reading input file listings.csv\n"); 
		exit (-1);
	}

	count = 0;
	while (fgets(line, LINESIZE, file_in) != NULL) { //loop through each line in the CSV,call getfields() on it, and add the resulting struct into an array
		list_items[count++] = getfields(line);
	}

	fclose(file_in); 

    qsort(list_items, count, sizeof(struct listing), cmpPrice); //call qsort() using cmpPrice()

	FILE *file_out = fopen("listingsSortedByPrice.csv", "w"); //open output file with write only flag

	if(file_out == NULL){ //error code if no file descriptor
		printf("Error writing to listingsSortedByPrice.csv\n");
		exit (-1);
	}

	for (i=0; i<count; i++) { //for each struct in the array

		fseek(file_out,0,SEEK_END); //point to the end of the file

		fprintf(file_out,"%d,%d,%s,%s,%s,%f,%f,%s,%f,%d,%d,%d,%d\n",list_items[i].id,list_items[i].host_id,list_items[i].host_name,list_items[i].neighbourhood_group,list_items[i].neighbourhood,list_items[i].latitude,list_items[i].longitude,list_items[i].room_type,list_items[i].price,list_items[i].minimum_nights,list_items[i].number_of_reviews,list_items[i].calculated_host_listings_count,list_items[i].availability_365); //print the line to the file
	}

	fclose(file_out);

	qsort(list_items, count, sizeof(struct listing), cmpName); //call qsort() using cmpName()

	FILE *file_out2 = fopen("listingsSortedByName.csv", "w"); //open output file with write only flag

	if(file_out2 == NULL){ //error code if no file descriptor
		printf("Error writing to listingsSortedByName.csv\n");
		exit (-1);
	}

	for (i=0; i<count; i++) { //for each struct in the array

		fseek(file_out2,0,SEEK_END); //point to end of file

		fprintf(file_out2,"%d,%d,%s,%s,%s,%f,%f,%s,%f,%d,%d,%d,%d\n",list_items[i].id,list_items[i].host_id,list_items[i].host_name,list_items[i].neighbourhood_group,list_items[i].neighbourhood,list_items[i].latitude,list_items[i].longitude,list_items[i].room_type,list_items[i].price,list_items[i].minimum_nights,list_items[i].number_of_reviews,list_items[i].calculated_host_listings_count,list_items[i].availability_365); //print the line to the file
	}

	fclose(file_out2);

	return 0;
}
