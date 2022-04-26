<?php

$servername = "localhost";
$username = "admin";
$password = "123456g23";
$dbname = "FYP";

//Create connection
$conn= new mysqli("$servername", "$username", "$password", "$dbname");

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
//else 
//Connection Successfully.
?>