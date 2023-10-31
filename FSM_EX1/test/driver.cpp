#define MAX_SIM 20

void set_random(Vtop *dut, vluint64_t sim_unit) {
	dut->w_i = rand() % 2;
	dut->res_ni = (sim_unit > 3) ? 1 : 0    ;

	static int stage = dut->Stage_o ;
	static int count = 0 ; 
	if( sim_unit >3 ){
		printf("%d: %d -> %d \n",count,stage,dut->Stage_o) ;
		stage = dut->Stage_o ;
		count++ ;
	}
}

