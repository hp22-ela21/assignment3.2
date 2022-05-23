#ifndef GPIOD_H_
#define GPIOD_H_

/*************************************************************************************
* Denna headerfil samt motsvarande källkodsfil gpiod.c utgör enbart dummyfiler för
* kompilering i Visual Studio. Tag inte med dessa filer vid kompilering i Linuxmiljö,
* utan inkludera i stället biblioteket gpiod.h genom att lägga till -l gpiod vid
* kompilering av projektet!
**************************************************************************************/

/* Funktionsdefinitioner: */
struct gpiod_chip* gpiod_chip_open(const char* path);
struct gpiod_chip* gpiod_chip_open_by_name(const char* name);
struct gpiod_chip* gpiod_chip_open_by_number(unsigned int number);
struct gpiod_line* gpiod_chip_get_line(struct gpiod_chip* chip, unsigned int offset);
void gpiod_chip_close(struct gpiod_chip* chip);

int gpiod_line_request_input(struct gpiod_line* line, const char* consumer);
int gpiod_line_request_output(struct gpiod_line* line, const char* consumer, int default_val);
int gpiod_line_set_value(struct gpiod_line* line, int value);
int gpiod_line_get_value(struct gpiod_line* line);
void gpiod_line_release(struct gpiod_line* line);

#endif /* GPIOD_H_ */