## Wildfire Ascend Mini / Xilinx Artix-7 xc7a200tfbg484-2

set_property PACKAGE_PIN W19 [get_ports fpga_clk]
set_property IOSTANDARD LVCMOS33 [get_ports fpga_clk]
create_clock -period 20.000 -name fpga_clk [get_ports fpga_clk]

set_property PACKAGE_PIN Y19 [get_ports reset_n]
set_property IOSTANDARD LVCMOS33 [get_ports reset_n]
set_property PULLUP true [get_ports reset_n]

set_property PACKAGE_PIN R16 [get_ports {key_n[0]}]
set_property PACKAGE_PIN P15 [get_ports {key_n[1]}]
set_property PACKAGE_PIN T20 [get_ports {key_n[2]}]
set_property PACKAGE_PIN Y18 [get_ports {key_n[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {key_n[*]}]
set_property PULLUP true [get_ports {key_n[*]}]

set_property PACKAGE_PIN N20 [get_ports {led[0]}]
set_property PACKAGE_PIN M20 [get_ports {led[1]}]
set_property PACKAGE_PIN N22 [get_ports {led[2]}]
set_property PACKAGE_PIN M22 [get_ports {led[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {led[*]}]

set_property PACKAGE_PIN K18 [get_ports {dig[0]}]
set_property PACKAGE_PIN K16 [get_ports {dig[1]}]
set_property PACKAGE_PIN L16 [get_ports {dig[2]}]
set_property PACKAGE_PIN G20 [get_ports {dig[3]}]
set_property PACKAGE_PIN H20 [get_ports {dig[4]}]
set_property PACKAGE_PIN H18 [get_ports {dig[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {dig[*]}]

set_property PACKAGE_PIN U22  [get_ports {seg[0]}]
set_property PACKAGE_PIN P19  [get_ports {seg[1]}]
set_property PACKAGE_PIN W21  [get_ports {seg[2]}]
set_property PACKAGE_PIN V22  [get_ports {seg[3]}]
set_property PACKAGE_PIN AB20 [get_ports {seg[4]}]
set_property PACKAGE_PIN W22  [get_ports {seg[5]}]
set_property PACKAGE_PIN AA20 [get_ports {seg[6]}]
set_property PACKAGE_PIN AA21 [get_ports {seg[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seg[*]}]

set_property PACKAGE_PIN AA18 [get_ports beep]
set_property IOSTANDARD LVCMOS33 [get_ports beep]
