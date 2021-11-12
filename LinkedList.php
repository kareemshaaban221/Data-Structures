<?php 
	
	class node {

		public $data;
		public $next;
		
		function __construct($data){
			$this->data = $data;
			$this->next = NULL;
		}

		function __debugInfo(){
			return [
				"data" => $this->data
			];
		}

		// function __clone(){
		// 	$this->next = clone $this->next;
		// }
	}

	class linkedList {

		private $front;
		private $tail;
		public $size;

		function __construct($head=NULL, $tail=NULL, $size=0){
			$this->front = $head;
			$this->tail = $tail;
			$this->size = $size;
		}

		function __debugInfo(){ // O(n)
			$info = [];
			$current = $this->front;
			while ($current){
				array_push($info, $current->data);
				$current = $current->next;
			}

			return $info;
		}

		function copyList(){ // O(n)
			$copy = new linkedList();
			$current = $this->front;
			while($current){
				$copy->append($current->data);
				$current = $current->next;
			}
			return $copy;
		}

		function is_empty(){
			return !$this->size;
		}

		function size(){
			return $this->size;
		}

		function getHeadPointer(){
			return $this->front;
		}

		function getTailPointer(){
			return $this->tail;
		}

		function getPointerToElementAtIndex($index){
			$temp = $index;
			$current = $this->front;
			while($temp > 0 and $current){
				$current = $current->next;
				$temp--;
			}
			return $current;
		}

		function get_front(){
			return $this->front->data;
		}

		function get_back(){
			return $this->tail->data;
		}

		function prepend($data){ // O(1)
			$new = new node($data);
			$new->next = $this->front;
			$this->front = $new;

			if($this->is_empty()){
				$this->tail = $new;
			}

			$this->size++;
			return $this->front;
		}

		function append($data){ // O(1)
			$new = new node($data); //new->next == null

			if($this->is_empty()){
				$this->front = $new;
				$this->tail = $new;
			}
			else{
				$this->tail->next = $new;
				$this->tail = $new;
			}

			$this->size++;
			return $this->tail;
		}

		function extend($list){
			$res = new linkedList();
			$current = $this->front;
			while($current){
				$res->append($current->data);
				$current = $current->next;
			}
			$current = $list->getHeadPointer();
			while($current){
				$res->append($current->data);
				$current = $current->next;
			}

			return $res;
		}

		// function extendInPlace($list){
		// 	if($this->tail){
		// 		$this->tail->next = $list->getHeadPointer();
		// 		$this->tail = $list->getTailPointer();
		// 	}
		// 	else{
		// 		$this->front = $list->getHeadPointer();
		// 		$this->tail = $list->getTailPointer();
		// 	}
		// }

		function search($key){ // O(n)
			$current = $this->front;
			while ($current){

				if($current->data === $key)
					return $current;

				$current = $current->next;
			}
			return $current;
		}

		function insert($data, $index){ // O(n)
			// special cases
			if($index <= 0 || $this->is_empty()){
				return $this->prepend($data);
			}
			else if($index >= $this->size){
				return $this->append($data);
			}
			else{
				// searching O(n)
				$position = 0;
				$current = $this->front;
				while ($position != $index - 1){
					$current = $current->next;
					$position++;
				}

				// inserting O(1)
				$new = new node($data);
				$new->next = $current->next;
				$current->next = $new;

				$this->size++;
				return $current->next;
			}
		}

		function delete($index){
			$pos = $index;
			$current = $this->front;

			if($index <= 0){

				$this->front = $current->next;
				$current->next = NULL;

				$this->size--;
				return $current;

			}
			else if($index >= $this->size){
				$pos = $this->size - 1;
			}

			while ($pos > 1){
				$current = $current->next;
				$pos--;
			}
			$target = $current->next;
			$current->next = $target->next;
			
			$target->next = NULL;
			$this->size--;
			return $target;
		}
	}

	// $list = new linkedList();
	// $list->prepend(10);
	// $list->prepend(15);
	// $list->append(10);
	// $list->append(15);
	// $list->insert(4, 3);
	// $list->delete(4);

	// $l = new linkedList();
	// $l->extendInPlace($list);

	// unset($list);
	// var_dump($l);

	// echo '<pre>' , var_dump($list->search(15)) , '</pre>';
	// echo '<pre>' , var_dump($list) , '</pre>';
	// echo $list->get_front() . '<br>';
	// echo $list->get_back() . '<br>';
	// echo $list->size();
	// echo $list->is_empty();

	// $node = new node("node");
	// var_dump($node);
?>