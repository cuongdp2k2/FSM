module ex2 (
    // input
    input logic clk_i ,
    input logic w     ,
    input logic res_ni ,

    // output
    output reg         z_o ,
    output reg [3:0] State_o 
) ;
    logic [3:0] State_wire ;
    //logic       z_wire     ;

    assign State_wire = State_o    ;
        
    always @(posedge clk_i) begin
        if(!res_ni) begin
            State_o <= 4'b0 ;
            z_o     <= 1'b0 ;
        end else begin
            State_o[3] <= (State_wire[2] & State_wire[1] & State_wire[0] & w) | (State_wire[3] & w);
            State_o[2] <= (~State_wire[2] & State_wire[1] & State_wire[0]) | (State_wire[2] & ~State_wire[1] & ~State_wire[0]) | (~State_wire[3] & ~State_wire[1] & w) | (~State_wire[3] & ~State_wire[0] & w);
            State_o[1] <= (~State_wire[2] & ~State_wire[1] & State_wire[0] & ~w) | (~State_wire[2] & State_wire[1] & ~State_wire[0] & ~w) | (State_wire[2] & ~State_wire[1] & State_wire[0] & w) | (State_wire[2] & State_wire[1] & ~State_wire[0] & w);
            State_o[0] <= (State_wire[2] & State_wire[0] & ~w) | (~State_wire[2] & ~State_wire[0] & ~w) | (~State_wire[3] & ~State_wire[2] & w) | (~State_wire[3] & ~State_wire[0] & w) | (State_wire[2] & State_wire[1] & ~w);
        end
    end

endmodule : ex2 
