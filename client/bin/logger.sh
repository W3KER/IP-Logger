ifconfig | 
    tr '\t' '|' | 
    sed "s/|inet /ip=/g" | 
    grep -v  "^|" | 
    grep -B 1 "^ip=" | 
    awk '{split($0,a,"[:]* "); print a[1]}' | 
    tr "\\n" '&' | 
    sed "s/--&/ /g"  | 
    tr ' ' '\n'$host | 
    awk '{print "http://0th.me/iplogger/?name='`hostname`'_"$0}' | 
    sed 's/&$//' |
    xargs -n 1 curl > /dev/null