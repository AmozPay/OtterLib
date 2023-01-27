#!/bin/sh

cat > ./.git/hooks/pre-commit << EOT
#!/bin/sh

set -euf
echo -e "\033[1;92m Linting Staged Files ...\e[0m"

files=$(git diff --diff-filter=d --cached --name-only | grep -E '\.(hpp|cpp)$')

for file in $files
do
    echo $file
    clang-format -i $file
    git add $file
done

echo  -e "\033[1;92m Adding files to current commit\e[0m"

EOT

chmod +x ./.git/hooks/pre-commit
