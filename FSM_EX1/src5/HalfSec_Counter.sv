module HalfSec_Counter(
    // input
    input logic CLOCK50_i ,
    // ouput
    output logic timeCounter_o 
) ;
    reg [31:0] timeCounter_reg ;
    logic [31:0] timeCounter_wire ;

    assign timeCounter_wire = timeCounter_reg  + 1 ;

    assign timeCounter_o = (timeCounter_reg == 32'd25000000) ;

    always @( posedge CLOCK50_i ) begin
        timeCounter_reg <= (timeCounter_wire == 32'd25000000) ? 0 : timeCounter_wire ;
    end

endmodule : HalfSec_Counter