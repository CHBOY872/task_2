FILES="makefile *.cpp *.hpp *.sh"

if [[ -z $1 ]]
then
    echo "type a commit"
else
    git add $FILES
    git commit -m "$1"
fi