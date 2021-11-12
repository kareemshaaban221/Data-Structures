<?php 

	function mergeSort($arr){
		if(sizeof($arr) <= 1){
			return $arr;
		}

		$temp = splitting($arr);
		$left = mergeSort($temp['left']);
		$right = mergeSort($temp['right']);

		return merge($left, $right);
	}

	function splitting($arr){

		$mid = floor(sizeof($arr) / 2);
		$res['left'] = array_slice($arr, 0, $mid);
		$res['right'] = array_slice($arr, $mid);

		return $res;
	}

	function merge($left, $right){
		$temp = [];
		$i = 0;
		$j = 0;

		while( $i < sizeof($left) && $j < sizeof($right) ){
			if($left[$i] < $right[$j]){
				$temp[] = $left[$i];
				$i++;
			}
			else{
				$temp[] = $right[$j];
				$j++;
			}
		}

		while( $i < sizeof($left) ){
			$temp[] = $left[$i];
			$i++;
		}

		while( $j < sizeof($right) ){
			$temp[] = $right[$j];
			$j++;
		}

		return $temp;
	}

	function verify($arr){
		if(sizeof($arr) == 1 || sizeof($arr) == 0)
			return 1;

		return intval($arr[0] < $arr[1] && verify(array_slice($arr, 1)));
	}

	echo verify([2, 8, 1, 3, 6, 7, 5, 4]);
	echo verify(mergeSort([2, 8, 1, 3, 6, 7, 5, 4]));

?>