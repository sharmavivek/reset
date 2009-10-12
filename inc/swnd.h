#ifndef _SWND_H_
#define _SWND_H_
//This file contains the information regarding Sliding Window

#define SWIND_MAX_SIZE		64000		// going by old standards

typedef struct sliding_window{
	t_pkt	*ptk_ptr;
	s32		seq_no;	         /* shall i use this, or maths for */
}t_swnd;


typedef struct sliding_window_info{
	int head;
	int tail;
	int size;

}t_swinfo;


/* Circular Queue - sliding window implementation returns the point to the packet */
// tail will move.
t_status init_swnd(t_swnd* swnd){
	&swnd = *t_swnd [SWIND_MAX_SIZE];
	return status;
}

t_status input_swnd(t_pkt *pkt, t_swinfo *swinfo){
	//check if entry allowed


	return status;

}

//head will move
t_status remove_swnd(int index){

	return status;
}







/* What are the things added -- 
   for the data Structure of window 




 */


#endif
