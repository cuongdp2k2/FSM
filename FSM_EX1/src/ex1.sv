
module ex1  #(
    parameter  _A =  9'b000000001 ,
    parameter  _B =  9'b000000010 ,
    parameter  _C =  9'b000000100 ,
    parameter  _D =  9'b000001000 ,
    parameter  _E =  9'b000010000 ,
    parameter  _F =  9'b000100000 ,
    parameter  _G =  9'b001000000 ,
    parameter  _H =  9'b010000000 ,
    parameter  _I =  9'b100000000 
    
) (
    // input
    input logic clk_i ,
    input logic w_i   ,
    input logic res_ni ,

    // output
    output reg         z_o ,
    output reg [8:0] Stage_o 
);
        
    // typedef enum { 
    //     _A <=  9'b000000001 ,
    //     _B <=  9'b000000010 ,
    //     _C <=  9'b000000100 ,
    //     _D <=  9'b000001000 ,
    //     _E <=  9'b000010000 ,
    //     _F <=  9'b000100000 ,
    //     _G <=  9'b001000000 ,
    //     _H <=  9'b010000000 ,
    //     _I <=  9'b100000000 
    // } StageType;

    logic [8:0] Stage_wire ;
    //logic       z_wire     ;

    always_comb begin
        if(!res_ni) begin
            Stage_wire = _A ;
            //z_wire     = 0  ; 
        end
        else begin
            case (Stage_o)
                _A : begin 
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _F : _B ;  
                end

                _B : begin
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _F : _C ;    
                end
                _C : begin
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _F : _D ; 
                end
                _D : begin
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _F : _E ; 
                end
                _E : begin
                    //z_wire     = 1 ;
                    Stage_wire = (w_i) ? _F : _E ; 
                end
                _F : begin
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _G : _B ; 
                end
                _G : begin
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _H : _B ; 
                end
                _H : begin
                    //z_wire     = 0 ;
                    Stage_wire = (w_i) ? _I : _B ; 
                end
                _I : begin
                    //z_wire     = 1 ;
                    Stage_wire = (w_i) ? _I : _B ; 
                end

                default: begin
                    Stage_wire = _A ;
                    //z_wire     = 0  ; 
                end
            endcase 
        end
    end
    
    always @(posedge clk_i) begin
        z_o     <= (Stage_wire == _E | Stage_wire == _I ) ;
        Stage_o <= Stage_wire ;
    end

endmodule