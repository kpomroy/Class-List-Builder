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
        $pwd = shell_exec("pwd");
        echo $pwd . "\n";
        echo "g++ -std=c++1y -o main.exe main.cpp;./main.exe " . $grade . " " . $studentFile . " " . $teacherFile . "\n";

        echo "<p>starting command shell call</p>";
        shell_exec("mkdir testing");
        shell_exec("g++ -std=c++1y -o main.exe main.cpp;./main.exe " . $grade . " " . $studentFile . " " . $teacherFile);
        echo "<p>ending command shell call</p>";

        // Print the txt file that was created with all of the data
        $textFile0 = "kindergarten.txt";
        $textFile1 = "firstGrade.txt";
        $textFile2 = "secondGrade.txt";
        $textFile3 = "thirdGrade.txt";
        $textFile4 = "fourthGrade.txt";
        $textFile5 = "fifthGrade.txt";


        // TODO: FORMAT TO PRINT ONE LINE AT A TIME
        if ($grade == "Kindergarten" && file_exists($textFile0)) {
            readfile($textFile0); // Display the contents of the text file
        } else if ($grade == "First" && file_exists($textFile1)) {
            readfile($textFile1); 
        } else if ($grade == "Second" && file_exists($textFile2)) {
            readfile($textFile2); 
        } else if ($grade == "Third" && file_exists($textFile3)) {
            readfile($textFile3);
        } else if ($grade == "Fourth" && file_exists($textFile4)) {
            readfile($textFile4); 
        } else {
            readfile($textFile5); 
        }
    
        ?>
    </body>
</html>
