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
        echo "You chose grade " . $grade;

        // Create a folder for the user where the processing will take place. It will be named a random number (so that it's different for each submission).
        $rand_number = rand();
        while (file_exists($rand_number)) {
            $rand_number = rand();
        }
        $command_mkdir = escapeshellcmd("mkdir " . $rand_number);
        $output_mkdir = shell_exec($command_mkdir);

        // Copy the files into the folder.
        $output_cp = shell_exec("cp List* " . $rand_number);
        $command_cp2 = escapeshellcmd("cp main.cpp " . $rand_number);
        $output_cp2 = shell_exec($command_cp2);
        $output = shell_exec("cd " . $rand_number . ";g++ -std=c++1y -o main.exe main.cpp;./main.exe " . $grade . ";cd ..");

        // Print the output from the C++ program to the webpage.
        echo $output;
        
        // Delete the folder
        array_map("unlink", glob($rand_number . "/*"));
        rmdir($rand_number);

        ?>
    </body>
</html>
