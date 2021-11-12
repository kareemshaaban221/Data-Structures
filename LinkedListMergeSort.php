<?php 
	require_once("linkedList.php");

	function linkedListMergeSort($list){
		return linkedListMergeSortOperation($list->copyList()); // O(n + nlogn)
	}

	function linkedListMergeSortOperation($list){
		// O(n log n)
		if($list->size == 1 || !$list->size){
			return $list;
		}

		$temp = splitting($list);
		$left = linkedListMergeSortOperation($temp['left']);
		$right = linkedListMergeSortOperation($temp['right']);

		return merge($left, $right);
	}

	function splitting($list){
		/*
		 * this function split linked list into two lists
		 * these lists is equal if size of the original one is even ,and vice versa
		 * $mid is the size of the first list and second size is original list size - $mid
		 * Returns => array of two linked list objects that present the splitting lists
		 * O(log n)
		*/

		$mid = floor($list->size / 2);

		$midLeft = $list->getPointerToElementAtIndex($mid - 1);
		$midRight = $midLeft->next;

		$midLeft->next = NULL;

		$leftList = new linkedList($list->getHeadPointer(), $midLeft, $mid);
		$rightList = new linkedList($midRight, $list->getTailPointer(), $list->size - $mid);

		return ['left' => $leftList, 'right' => $rightList];
	}

	function merge($left, $right){
		/*
		 * this function merge to list in one sorted list
		 * creates iterators from type node to traverse two merging lists
		 * uses conquer technique as array based merge sort
		 * Returns => sorted list to the next above step in the stack of recursive calls
		 * O(n)
		*/

		$sortedList = new linkedList();

		$i = $left->getHeadPointer();
		$j = $right->getHeadPointer();

		while($i and $j){
			if($i->data < $j->data){
				$sortedList->append($i->data);
				$i = $i->next;
			}
			else{
				$sortedList->append($j->data);
				$j = $j->next;
			}
		}

		while($i){
			$sortedList->append($i->data);
			$i = $i->next;
		}

		while($j){
			$sortedList->append($j->data);
			$j = $j->next;
		}

		return $sortedList;
	}

	function verify($list){
		$current = $list->getHeadPointer();
		$flag = true;
		while($current->next){
			if($current->data > $current->next->data){
				return !$flag;
			}
			$current = $current->next;
		}

		return $flag;
	}

	function verifyRecursively($list){
		$size = $list->size;
		if($size == 1 || !$size){
			return 1;
		}

		$head = $list->getHeadPointer();

		return $head->data < $head->next->data && verifyRecursively(new linkedList($head->next, NULL, $size-1));
	}

	$list = new linkedList();

	$list->append(2);
	$list->append(8);
	$list->append(1);
	$list->append(3);
	$list->append(6);
	$list->append(7);
	$list->append(5);
	$list->append(4);
	$list->append(0);

	$sortedList = linkedListMergeSort($list);

	echo '<pre>' ,
	verifyRecursively($list) ,
	verifyRecursively($sortedList) ,
	'</pre>';

?>