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
extern void i2c_write(__u8 reg_address, __u8 val);
extern char i2c_read(uint8_t reg_address);
uint16_t merge_bytes( uint8_t LSB, uint8_t MSB);
int16_t two_complement_to_int( uint8_t LSB, uint8_t MSB);

void set_cursor(uint8_t line_no, uint8_t cursor_position);
#define MPU6050_I2C_ADDR 0x68

#define REG_ACCEL_ZOUT_H 0x3F
#define REG_ACCEL_ZOUT_L 0x40
#define REG_PWR_MGMT_1 0x6B
#define REG_ACCEL_CONFIG 0x1C
#define REG_SMPRT_DIV 0x19
#define REG_CONFIG 0x1A
#define REG_FIFO_EN 0x23
#define REG_USER_CTRL 0x6A
#define REG_FIFO_COUNT_L 0x72
#define REG_FIFO_COUNT_H 0x73
#define REG_FIFO 0x74
