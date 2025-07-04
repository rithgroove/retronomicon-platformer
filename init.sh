
echo downloading libraries
mkdir -p external
cd ./external

echo cloning retronomicon

git clone git@github.com:rithgroove/retronomicon.git retronomicon
cd ./retronomicon
USE_LUA=ON USE_PYTHON=ON  ./init.sh
cd ..

