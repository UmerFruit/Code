#! /bin/bash
echo 'enter name:'
read name1 name2 name3
echo entered names: $name1, $name2, $name3

read -p username: uservar
echo $uservar

read -sp password: pass
echo
echo $pass

echo enter names
read -a  names
echo ${names[0]},${names[1]}

echo lol enter num
read
echo you entered $REPLY