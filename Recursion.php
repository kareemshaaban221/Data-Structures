<?php 
	require_once('LinkedList.php');

	function sum($values){
		if(!$values){
			return 0;
		}

		return $values[0] + sum(array_slice($values, 1));
	}

	function quickSort($arr){
		$n = sizeof($arr);
		if(!$arr || sizeof($arr) == 1)
			return $arr;

		$pivot = $arr[0];
		$lesser = [];
		$greater = [];
		for($i = 1; $i < $n; $i++){
			if($arr[$i] > $pivot)
				array_push($greater, $arr[$i]);
			else
				array_push($lesser, $arr[$i]);
		}

		// echo 'lesser ' . var_dump($lesser) . '<br>';
		$res = quickSort($lesser);
		array_push($res, $pivot);
		// echo 'greater ' . var_dump($greater) . '<br>';
		return array_merge($res, quickSort($greater));
	}

	function quickSortLinkedList($list){ // O(2n log n) => O(n log n^2)
		$size = $list->size;
		if(!$size || $size == 1){
			return $list;
		}

		$current = $list->getHeadPointer();
		$pivot = $current->data;
		$lesserList = new linkedList();
		$greaterList = new linkedList();
		$current = $current->next;
		while($current){ // O(n log n)
			$data = $current->data;
			if($data < $pivot){
				$lesserList->append($data);
			}
			else{
				$greaterList->append($data);
			}
			$current = $current->next;
		}

		$res = quickSortLinkedList($lesserList);
		$res->append($pivot);
		return $res->extend(quickSortLinkedList($greaterList)); // O(n log n)
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

	$sortedList = quickSortLinkedList($list);

	echo '<pre>' ,
	var_dump($list) ,
	var_dump($sortedList) ,
	'</pre>';
?>