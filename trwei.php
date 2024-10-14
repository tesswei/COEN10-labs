<! DOCTYPE html>
<html>
	<body>

	<?php
	echo "Multiplication Practice \r\n";
	?>
	<br>
	<?php
	$number1 = rand (0,12); 
	$number2 = rand (0,12);
	echo $number1 . "x" . $number2;
	
	?>
	<form action="trwei2.php" method= "post">
		<input type= "hidden" name="number1" value="
			<?php echo $number1; ?>"/>
		<input type= "hidden" name= "number2" value="
			<?php echo $number2;?>" />
		
	<input type= "number" name="number3"/>
		<input type="submit" value="Calculate!"/>
	</form>
		
