<!DOCTYPE html>
<html>
<body>
<?php	
	$found = 0;
	$number = $_POST ["number"];
	$number1 = array(0,0,0,0,0);
	for ($num=0; $num<5; $num ++)
	{

		$number1[$num]=rand(1,20);
	}
	for ($i=0; $i<5; $i ++)
	{

	if ($number==$number1[$i])
		$found=1;
	}
	if ($found==1)
		echo "You got it";
		
	else 
		echo "Wrong";	
	
	
	$size=count ($number1);
	for($i=0; $i < $size; $i++)
		echo $number1 [$i] . " ";
	
?>
	<form method= "POST" action="trwei3.html">
		<input type="submit" value="Try again"/>
	</form>
</body>
</html>
