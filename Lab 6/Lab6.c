#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINESIZE 1024

struct listing {
	int id, host_id, minimum_nights, number_of_reviews, calculated_host_listings_count,availability_365;
	char *host_name, *neighbourhood_group, *neighbourhood, *room_type;
	float latitude, longitude, price;
};

struct listing getfields(char* line) {
	struct listing item;

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

void displayStruct(struct listing item) {
	printf("ID : %d\n", item.id);
	printf("Host ID : %d\n", item.host_id);
	printf("Host Name : %s\n", item.host_name);
	printf("Neighbourhood Group : %s\n", item.neighbourhood_group);
	printf("Neighbourhood : %s\n", item.neighbourhood);
	printf("Latitude : %f\n", item.latitude);
	printf("Longitude : %f\n", item.longitude);
	printf("Room Type : %s\n", item.room_type);
	printf("Price : %f\n", item.price);
	printf("Minimum Nights : %d\n", item.minimum_nights);
	printf("Number of Reviews : %d\n", item.number_of_reviews);
	printf("Calculated Host Listings Count : %d\n", item.calculated_host_listings_count);
	printf("Availability_365 : %d\n\n", item.availability_365);
}

int cmpPrice(const struct listing *p1, const struct listing *p2) {
    
    struct listing *ps1 = (struct listing*) p1;
    struct listing *ps2 = (struct listing*) p2;

    return p1->price > p2->price;
}

int main(int argc, char* args[]) {
	struct listing list_items[22555];
	char line[LINESIZE];
	int i, count;

	FILE *file_in = fopen("listings.csv", "r");
	if(file_in == NULL){
		printf("Error reading input file listings.csv\n");
		exit (-1);
	}

	count = 0;
	while (fgets(line, LINESIZE, file_in) != NULL) {
		list_items[count++] = getfields(line);
	}

	fclose(file_in);

    qsort(list_items, count, sizeof(struct listing), cmpPrice);

    for (i=0; i<count; i++) {
	    displayStruct(list_items[i]);
	}

	FILE *file_out = fopen("listingsSortedByPrice.csv", "w");

	for (i=0; i<count; i++) {
	    

		if(file_out == NULL){
			printf("Error writing to listingsSortedByPrice.csv\n");
			exit (-1);
		}

		fseek(file_out,0,SEEK_END);

		fprintf(file_out,"%d,%d,%s,%s,%s,%f,%f,%s,%f,%d,%d,%d,%d\n",list_items[i].id,list_items[i].host_id,list_items[i].host_name,list_items[i].neighbourhood_group,list_items[i].neighbourhood,list_items[i].latitude,list_items[i].longitude,list_items[i].room_type,list_items[i].price,list_items[i].minimum_nights,list_items[i].number_of_reviews,list_items[i].calculated_host_listings_count,list_items[i].availability_365);
	}

	fclose(file_out);

	return 0;
}
