## Wildfire Ascend Mini / Xilinx Artix-7 xc7a200tfbg484-2

set_property PACKAGE_PIN W19 [get_ports fpga_clk_i]
set_property IOSTANDARD LVCMOS33 [get_ports fpga_clk_i]
create_clock -period 20.000 -name fpga_clk_i [get_ports fpga_clk_i]

set_property PACKAGE_PIN Y19 [get_ports reset_n_i]
set_property IOSTANDARD LVCMOS33 [get_ports reset_n_i]
set_property PULLUP true [get_ports reset_n_i]

set_property PACKAGE_PIN R16 [get_ports {key_n_i[0]}]
set_property PACKAGE_PIN P15 [get_ports {key_n_i[1]}]
set_property PACKAGE_PIN T20 [get_ports {key_n_i[2]}]
set_property PACKAGE_PIN Y18 [get_ports {key_n_i[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {key_n_i[*]}]
set_property PULLUP true [get_ports {key_n_i[*]}]

set_property PACKAGE_PIN N20 [get_ports {led_o[0]}]
set_property PACKAGE_PIN M20 [get_ports {led_o[1]}]
set_property PACKAGE_PIN N22 [get_ports {led_o[2]}]
set_property PACKAGE_PIN M22 [get_ports {led_o[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {led_o[*]}]

set_property PACKAGE_PIN K18 [get_ports {dig_o[0]}]
set_property PACKAGE_PIN K16 [get_ports {dig_o[1]}]
set_property PACKAGE_PIN L16 [get_ports {dig_o[2]}]
set_property PACKAGE_PIN G20 [get_ports {dig_o[3]}]
set_property PACKAGE_PIN H20 [get_ports {dig_o[4]}]
set_property PACKAGE_PIN H18 [get_ports {dig_o[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dig_o[*]}]

set_property PACKAGE_PIN U22  [get_ports {seg_o[0]}]
set_property PACKAGE_PIN P19  [get_ports {seg_o[1]}]
set_property PACKAGE_PIN W21  [get_ports {seg_o[2]}]
set_property PACKAGE_PIN V22  [get_ports {seg_o[3]}]
set_property PACKAGE_PIN AB20 [get_ports {seg_o[4]}]
set_property PACKAGE_PIN W22  [get_ports {seg_o[5]}]
set_property PACKAGE_PIN AA20 [get_ports {seg_o[6]}]
set_property PACKAGE_PIN AA21 [get_ports {seg_o[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seg_o[*]}]

set_property PACKAGE_PIN AA18 [get_ports beep_o]
set_property IOSTANDARD LVCMOS33 [get_ports beep_o]
