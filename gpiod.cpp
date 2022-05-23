/* Inkluderingsdirektiv: */
#include "gpiod.h"

/*************************************************************************************
* Denna k�llkodsfil samt motsvarande headerfil gpiod.h utg�r enbart dummyfiler f�r
* kompilering i Visual Studio. Tag inte med dessa filer vid kompilering i Linuxmilj�,
* utan inkludera i st�llet biblioteket gpiod.h genom att l�gga till -l gpiod vid
* kompilering av projektet!
**************************************************************************************/

/* Funktionsdefinitioner: */
struct gpiod_chip* gpiod_chip_open(const char* path) { return 0; }
struct gpiod_chip* gpiod_chip_open_by_name(const char* name) { return 0; }
struct gpiod_chip* gpiod_chip_open_by_number(unsigned int number) { return 0; }
struct gpiod_line* gpiod_chip_get_line(struct gpiod_chip* chip, unsigned int offset) { return 0; }
void gpiod_chip_close(struct gpiod_chip* chip) { }

int gpiod_line_request_input(struct gpiod_line* line, const char* consumer) { return 0; }
int gpiod_line_request_output(struct gpiod_line* line, const char* consumer, int default_val) { return 0; }
int gpiod_line_set_value(struct gpiod_line* line, int value) { return 0; }
int gpiod_line_get_value(struct gpiod_line* line) { return 0; }
void gpiod_line_release(struct gpiod_line* line) { }