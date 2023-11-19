module HalfSec_Counter(
    // input
    input logic CLOCK50_i ,
    // ouput
    output logic timeCounter_o 
) ;
    reg [31:0] timeCounter_reg ;
    always @(posedge CLOCK50_i) begin
        timeCounter_reg <= (timeCounter_reg == 25000000) ? 0 : timeCounter_reg + 1;
        timeCounter_o   <= (timeCounter_reg > 12500000) & (timeCounter_reg < 25000000) ;
    end

endmodule : HalfSec_Counter