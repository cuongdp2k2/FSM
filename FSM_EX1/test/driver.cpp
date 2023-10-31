#define MAX_SIM 2000

void set_random(Vtop *dut, vluint64_t sim_unit) {
	dut->w_i = rand() % 2;
	dut->res_ni = (sim_unit > 3) ? 1 : 0    ;
}

