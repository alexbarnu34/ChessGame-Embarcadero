//---------------------------------------------------------------------------

#pragma hdrstop

#include "Knight.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Knight::Knight(PlayerColor color, int x, int y): ChessPiece(color, x, y)
{

}

std::vector<ChessMove>::getPosibleMoves(const ChessBoard* board)const override  {
		   std::vector<ChessMove> moves;
		   std::vector<int> move_down_x ={this->PositionX+1,this->PositionX+2, this->PositionX+1,this->PositionX+2 }
		   std::vector<int> move_down_y ={this->PositionY+2,this->PositionY+1 ,this->PositionY-2,this->PositionY-1 }
		   std::vector<int> move_up_x ={this->PositionX-1,this->PositionX-2, thi->.PositonX-1,this->PositionX-2 }
		   std::vector<int> move_up_y ={this->PositionY+2,this->PositionY+1, this->PositionY-2,this->PositionY-1}
			for(int i=0;i<8;i++){
				if(i<4){
				 int poz_x=move_down_x.pop();
				 int poz_y=move_down_y.pop();
				 moves.push_back(ChessMove(this.PositionX,this.PositionY,poz_x,poz_y));
				}else{
				 int poz_x=move_up_x.pop();
				 int poz_y=move_up_y.pop();
				 moves.push_back(ChessMove(this.PositionX,this.PositionY,poz_x,poz_y));
				}
			}
	  return moves;
}
