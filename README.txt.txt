FOTA Firmware



Cần thực hiện phương thức get dữ liệu với mỗi thành phần khác nhau : UART, SPI, I2C, Ethernet, SD CARD,...

trong hàm lấy dữ liệu cần gọi phương thức fota_data_is_comming(p_fota, data);