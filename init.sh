
echo downloading libraries
mkdir -p external
cd ./external

echo cloning retronomicon

git clone git@github.com:rithgroove/retronomicon.git retronomicon
cd ./retronomicon
./init.sh
cd ..

