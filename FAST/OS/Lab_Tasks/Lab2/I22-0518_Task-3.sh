#! /bin/bash
#i22-0518
echo "#! /bin/bash" > marks.sh
chmod +x marks.sh
echo date >> marks.sh
echo "echo Name: $1" >> marks.sh
echo "echo total marks: $2" >> marks.sh
echo "echo English: $3" >> marks.sh
echo "echo Urdu: $4" >> marks.sh
echo "echo Maths: $5" >> marks.sh
./marks.sh