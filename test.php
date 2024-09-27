<?php
// URL mà bạn muốn chuyển hướng đến
$new_url = "file:///etc/passwd";

// Thực hiện chuyển hướng
header("Location: " . $new_url);
exit(); // Dừng thực thi code sau khi chuyển hướng
?>
