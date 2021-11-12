<?php 

	$arr = [];
	array_push($arr, 1);
	array_push($arr, 2);
	array_push($arr, 3);
	// array_shift($arr);
	// echo array_unshift($arr, 2) . '<br>';
	array_splice($arr, 1, 0, 3); 	//for adding value at index 1
	array_splice($arr, 1, 1, NULL); //for deleting a single value from index 1
	var_dump($arr);
	// echo '<pre>' . var_dump(array_merge($arr, [5, 6, 7])) . '</pre>';


	/* Notes:
	
		1- pop returns value of popped element

		2- unshift inserts given element in the beginning of an array

		3- unshift returns the new size of the array after unshifting
		
		4- shift deletes element from the beginning of an array

		5- splice is used to insert values at any position in an array

		6- splice take args (array, position, length, inserted_item[int, array])

		7- splice main function is to remove subarray from position argument with length = `length` argument
		   and replace it with the forth argument `inserted_item`.
		
		8- splice is also used to delete a value from any position in an array

	*/
?>