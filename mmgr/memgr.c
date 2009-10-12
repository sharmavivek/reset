/*Memory Manager-- to implement an ArrList equivalent in C*/

/*  How to use this library?
 *****************************************************************************
 * Make a pointer to the linklist ie of t_mminfo structure, all the revelant 
 * information is store in this structure.
 * 
 * 
 *****************************************************************************
 */ 


/* t_size sz- size of the element, eg- sizeof(struct abc)
 * s32 no_ele- no of elements of sz 
 */
typedef struct memory_block_info{
	struct t_mminfo	*head_ptr;		// only to be altered when decreasing the Q 
	struct t_mminfo	*tail_ptr;		// only to be altered when increasing the Q
	struct t_mminfo	*in_ptr;		// to add the entity/ usually tail of Q
	struct t_mminfo	*out_ptr;		// for exit of entity/usually head of Q
//	struct t_mminfo *cur_ptr;		// for present node -- is this same as in_ptr (tail)
	void*	arr_ptr;				// this points to the memory or the array. (this can used for del)
	//s23		cur_ptr;			// which node of linked list
	s32		cur_index;				// which array index in current node
	s32		gbl_filled;				// space occupied in total across the lists. 
	s32		lcl_filled;				// space occupied in local node, for del
	s32		gbl_avail;				// space available in the current node.
	s32		tol_size;				// total memory in use, in terms of elements.
}t_mminfo;


/* No of elements/units.
 * Size of each elements, template emulation.
 * using calloc over malloc, as initial value of the elements is 0.
 */
	
t_status mm_alloc(t_size sz, s32 no_ele, t_mminfo *mminfo){
	
	t_mminfo *new_node, *new_block;
	if(NULL == (new_node = (t_mminfo*)calloc(1, sizeof(t_mminfo)) ))
		return e_malloc;		
	else if(NULL == (new_block = (void*) calloc(ele, sizeof(void*)) ))
			return e_malloc;
		else 
			new_node->arr_ptr = new_block;
	
	if (mminfo->hdr_ptr == NULL){		// List initial allocation
		mminfo->head_ptr = new_block;
		mminfo->tail_ptr = mminfo->head_ptr + (sizeof(t_mminfo) * ele);
		mminfo->in = mminfo->tail_ptr;
		mminfo->out = mminfo->head_ptr;
		//mminfo->cur_ptr = mminfo->head_ptr;
		mminfo->no_present = 0;
		mminfo->cur_node = 0;
		mminfo->space_avail = n_ele;
		return i_mem_add;
	}
	else{
		new_node->head_ptr = mminfo->tail_ptr;
		mminfo->tail_ptr = new_node->tail_ptr;
		mminfo->avail += ele;
		mminfo->cur_node += 1;
		return i_mem_add;
	}
	
}

	

t_status mm_input (void* value, t_mminfo* mminfo, p_swnd){
	if (!mm_info->avail){
			return e_nospace;
	else{
		t_mminfo *cur_node	= mminfo->cur_ptr;
		*cur_node->arr_ptr[*mminfo->cur_index] = value;
		*cur_node->in_ptr = ur_node->cur_index;
		*cur_node->cur_index += 1;
		mminfo->space_avail = (*cur_node->space_avail -= 1);
		
		return success;
	}
	return success;
}

/* Delete policy -- recursive delete from the last node.
 * Donot follow circular setup, simply move the queues.
 */

/* eg - got an Ack, remove the entry */
t_status mm_del (global_index){
	/* check for the last element in the node -
	 */
	
	 t_mminfo *cur_node = mm_info->out_ptr;
	 cur_node
	s32 node_no = global 
	
	
	
}




/* Gives the head for a particular memory block*/
s32 mm_get_index(void *index, t_mminfo* mminfo ){
	return (mminfo->cur_index);
}

/* Gives the head for a particular memory block*/
void* mm_get_head(void *head,t_mminfo* mminfo ){
	return ((void*)mminfo->head_ptr));
}

/* Gives the tail for a particular memory block*/
void* mm_get_tail(void *tail, t_mminfo* mminfo){
	return ((void*)mminfo->tail_ptr);
}

/* Gives the size in count of no of elements for a particular memory block*/
s32 mm_get_size(void *size, t_mminfo* mminfo){
	return (mminfo->total_elements);
}
