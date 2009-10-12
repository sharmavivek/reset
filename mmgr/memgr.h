#ifndef __MEMGR_H_
#define __MEMGR_H_

//Initialization for t_mminfo (MemMgr).
#define VEC_INIT {NULL, NULL, NULL, 0,0,0}

#define ERR_INIT	-100
#define INF_INIT	100


typedef enum return_status{
	//error values 
	e_malloc = ERR_INIT,
	
	
	// generic 
	fail 	= -1,	 
	success	= 0,
	
	//success/information values
	i_mem_init	= INF_INIT,
	i_mem_add,
	
	
}t_status;
	
typedef struct memory_block_info{
	struct t_mminfo	*head_ptr;		// only to be altered when decreading the Q 
	struct t_mminfo	*tail_ptr;		// only to be altered when increasing the Q
	struct t_mminfo	*in_ptr;		// to add the entity/ usually tail of Q
	struct t_mminfo	*out_ptr;		// for exit of entity/usually head of Q
	struct t_mminfo *cur_ptr;		// for present node 
	void*	arr_ptr;				// this points to the memory or the array.
	//s23		cur_ptr;			// which node of linked list
	s32		cur_index;				// which index in current node
	s32		filled;					// space occupied in total
	s32		avail;					// space available in the current node.
}t_mminfo;


/*		
typedef struct memory_block_info{ //get the new one from memgr.c
	void	*head_ptr;
	void	*tail_ptr;
	void	*cur_ptr;				// which node of linked list
	s32		cur_index;				// which index in current node
	s32		total_elements;
	s32		space_avail;			// in the current node.
}t_mminfo;
*/
	
/* Memory Allocation Manager related system calls. */

extern t_status mm_alloc();
extern t_status mm_free();

/* Getters*/
extern t_status mm_get_index();
extern t_status mm_get_size();
extern t_status mm_get_head();
extern t_status mm_get_tail();

#endif
