extern int file_open_and_write_value(const char *fname, const char *wdata);
extern int gpio_export(int gpio_num);
extern int gpio_unexport(int gpio_num);
extern int gpio_set_direction(int gpio_num,const char* dir);
extern int gpio_set_value(int gpio_num, const char *value);
extern void gpio_configure_for_display(void);
extern void spi_configure_for_display(void);
extern void spi_write_1_byte(uint8_t val);
extern void display_write_command(uint8_t cmd);
extern void display_write_data(uint8_t data);
extern void display_do_reset(void);
extern void display_turn_on(void);
extern void display_turn_off(void);
extern void display_set_contrast(uint8_t contrast);
extern void display_invert_disable(void);
extern void display_set_page_address(uint8_t address);
extern void display_set_column_address(uint8_t address);
extern void display_clear(void);
extern void display_do_init(void);
extern void display_write_string(const char* string);