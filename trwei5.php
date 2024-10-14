<html>
<body>
<?php
	$x=0;
	$number1=$_POST["number1"];
	$number2=$_POST["number2"];
	$number3=$_POST["number3"];
	$number4=$_POST["number4"];
	$number5=$_POST["number5"];
	$rec = array($number1,$number2,$number3,$number4,$number5);
	$randlist = array(0,0,0,0,0);
	for ($num=0;$num<5; $num ++) //generating random numbers
	{
		$randlist[$num]=rand(1,20);
	for ($j=$num-1; $j>=0; $j--) // checking for duplicates
		if ($randlist[$num]==$randlist[$j])
	{
			$num--;
			break;
	}
	}
	for ($i=0; $i<5; $i ++) // comparing the random numbers to guessed numbers
	for ($j=0; $j<5; $j ++)
	{
		if ($rec[$i]==$randlist[$j])
			$x++;
		
	}
	for ($i=0; $i<5; $i++)
		echo $randlist[$i] . " "; // displaying random list
	echo "<br>";
		
	for ($j=0; $j<5;$j++)
		echo $rec[$j] . " ";  // displaying user list
	echo "<br>";
echo "You've found " . $x . " matches";
?>
	<form method= "POST" action= "trwei5.html">
		<input type="submit" value= "Try again"/>
	</form>
</body>
</html>		
				
