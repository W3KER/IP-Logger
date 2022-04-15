<html>
    <body>        
        <pre>
Kepler Device List
===================
<?php

$MAX_DEVICES = 100;
$MAX_IP_LENGTH = 39;
$MAX_NAME_LENGTH = 32;
    
$file = 'devices';

$in_list = array();
$out_list = array();
$clist = explode("\n", file_get_contents($file));

foreach ($clist as $row) {
    $device = explode(" : ", $row);
    if($device[0]!="" && $device[1]!="") $in_list[$device[0]] = $device[1];
}

$newdevice_name = $_GET["name"];
$newdevice_ip = $_GET["ip"];

$nameLen = strlen($newdevice_name);
$ipLen = strlen($newdevice_ip);

if($nameLen>0 && $nameLen<$MAX_NAME_LENGTH && 
   $ipLen>0 && $ipLen<$MAX_IP_LENGTH &&
   count($in_list)<$MAX_DEVICES) {
    $in_list[$newdevice_name] = $newdevice_ip;
}

foreach ($in_list as $deviceName => $deviceIP) {
    if($deviceIP!=-1)
    array_push($out_list, $deviceName." : ".$deviceIP);
}

$out = implode("\n",$out_list);
file_put_contents($file, $out);
echo $out;

?>
        </pre>
    </body>
</html>