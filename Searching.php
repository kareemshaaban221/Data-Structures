<?php 

	function linearSearch($list, $target){ //No preconditions, O(n)
		if(is_array($list)){
			foreach ($list as $index => $value) {
				if($value == $target)
					return $index;
			}
			return -1;
		}
		else{
			return -2;
		}
	}

	function binarySearch($list, $target){ //sorted array is a precondition, O(log n) but in this case O(nlog n)
		if(is_array($list)){
			sort($list); //O(nlog n)
			$first = 0;
			$last = sizeof($list) - 1;

			while ($first <= $last){
				$midpoint = floor(($first + $last) / 2);
				if($list[$midpoint] > $target)
					$last = $midpoint - 1;
				else if($list[$midpoint] < $target)
					$first = $midpoint + 1;
				else
					return $midpoint;
			}

			return -1;
		}
		else{
			return -2;
		}
	}

	function recursiveBinarySearch($list, $target){ // validations
		if(is_array($list)){
			sort($list); //precondition

			return recursiveBinarySearchBody($list, $target);
		}
		else
			return -2;
	}
	function recursiveBinarySearchBody($list, $target){ // recursion body
		if(!empty($list)){
			$midpoint = floor(sizeof($list) / 2);
			if($list[$midpoint] > $target)
				return recursiveBinarySearchBody(array_slice($list, 0, $midpoint), $target);
				// slice take the length not the last index
			else if($list[$midpoint] < $target)
				return recursiveBinarySearchBody(array_slice($list, $midpoint + 1), $target);
				// if you don't specify the length, slice returns subarray to the last element of the original one

				// Note: in the case of 'first' or 'offset' is NOT index in the list, slice returns empty array
			else
				return $midpoint;
		}
		else
			return -1;
	}

	function verify($index){
		if($index >= 0){
			echo '<center> <h1> Element is found :) </h1> </center>';
		}
		else{
			if($index == -1)
				echo '<center> <h1> Element is not found :( </h1> </center>';
			else
				echo '<center> <h1> Invalid input XX </h1> </center>';
		}
	}

	$arr = [1, 2, 3, 10, 7, 5];
	$index = recursiveBinarySearch($arr, 10);
	verify($index);

?>