<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="author" content="Kevin Pomroy, Sam Alamutu, Kira Safferstein">
        <title>Class Lists</title>
        <meta name="description" content="This page shows the results of class lists being built.">
        <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    </head>
    <body>
    	<header>
    		<h1>Class Lists</h1>
    	</header>
        
        <?php
        
        $grade = $_POST["grades"];
        $studentFile = $_POST["student-file"];
        $teacherFile = $_POST["teacher-file"];
        echo "<p> You chose grade: " . $grade . "</p>";
        echo "<p> Student file: " . $studentFile . "</p>";
        echo "<p> Teacher file: " . $teacherFile . "</p>";
  
        // Make command line call to execute main
        // Passing in grade and file strings
        // DEBUGGING PRINTS
        // $pwd = shell_exec("pwd");
        // echo $pwd . "\n";
        // echo "g++ -std=c++1y -o main.exe main.cpp;./main.exe " . $grade . " " . $studentFile . " " . $teacherFile . "\n";

        shell_exec("mkdir testing");
        shell_exec("g++ -std=c++1y -o main.exe main.cpp;./main.exe " . $grade . " " . $studentFile . " " . $teacherFile);

        // Print the txt file that was created with all of the data
        $textFile0 = "kindergarten.txt";
        $textFile1 = "firstGrade.txt";
        $textFile2 = "secondGrade.txt";
        $textFile3 = "thirdGrade.txt";
        $textFile4 = "fourthGrade.txt";
        $textFile5 = "fifthGrade.txt";

        echo "<table>";
        if ($grade == "Kindergarten" && file_exists($textFile0)) {
            $lines = file('kindergarten.txt');
            
            foreach($lines as $line) {
                echo "<tr>";
                echo "<td>";
                echo $line;
                echo "</td>";
                echo "<tr>";
            }
            
        } else if ($grade == "First" && file_exists($textFile1)) {
            $lines = file('firstGrade.txt');
            
            foreach($lines as $line) {
                echo "<tr>";
                echo "<td>";
                echo $line;
                echo "</td>";
                echo "<tr>";
            }

        } 
        else if ($grade == "Second" && file_exists($textFile2)) {
            $lines = file('secondGrade.txt');
            
            foreach($lines as $line) {
                echo "<tr>";
                echo "<td>";
                echo $line;
                echo "</td>";
                echo "<tr>";
            } 
        } 
        else if ($grade == "Third" && file_exists($textFile3)) {
            $lines = file('thirdGrade.txt');
            
            foreach($lines as $line) {
                echo "<tr>";
                echo "<td>";
                echo $line;
                echo "</td>";
                echo "<tr>";
            } 
        } 
        else if ($grade == "Fourth" && file_exists($textFile4)) {
            $lines = file('fourthGrade.txt');
            
            foreach($lines as $line) {
                echo "<tr>";
                echo "<td>";
                echo $line;
                echo "</td>";
                echo "<tr>";
            } 
        } 
        else {
            $lines = file('fifthGrade.txt');
            
            foreach($lines as $line) {
                echo "<tr>";
                echo "<td>";
                echo $line;
                echo "</td>";
                echo "<tr>";
            } 
        }
        echo "</table>";

        echo '<img src="M3OEP_plot.png" alt="Graph image"/>';
        
        ?>
    </body>
</html>