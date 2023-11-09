#define MAX_SIM 20

// Cuong own function
void TestBench_EX1(Vtop *dut, vluint64_t sim_unit){
	static int stage = dut->State_o ;
	static int count = 0 ; 
	if( sim_unit >3 ){
		printf("%d: %d -> %d \n",count,stage,dut->State_o) ;
		stage = dut->State_o ;
		count++ ;
	}
	return ;
}

// void TestBench_EX2(Vtop *dut, vluint64_t sim_unit){

// }

/*--------- MAIN TEST BENCH HERE -------------------------------------*/ 
void set_random(Vtop *dut, vluint64_t sim_unit) {
	dut->w = rand() % 2;
	dut->res_ni = (sim_unit > 3) ? 1 : 0    ;

	//TestBench_EX1(dut,sim_unit) ;
}

