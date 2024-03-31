#! /bin/bash
touch marks.sh
chmod +x marks.sh
echo "#! /bin/bash" > marks.sh
echo "date" >> marks.sh
echo "echo \"Name: $1\"" >> marks.sh
echo "echo \"total: $2\"" >> marks.sh
echo "echo \"eng: $3\"" >> marks.sh
echo "echo \"urdu: $4\"" >> marks.sh
echo "echo \"maths: $5\"" >> marks.sh
./marks.sh

