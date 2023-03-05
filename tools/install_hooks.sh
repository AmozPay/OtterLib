#!/bin/sh

cat > ./.git/hooks/pre-commit << EOT
#!/bin/sh


files=\$(git diff --diff-filter=d --cached --name-only | grep -E '\.(hpp|cpp)$')

if [ \${#key[@]} -ne 0 ];
then
    echo -e "\033[1;92m Linting Staged Files ...\e[0m"
    for file in \$files
    do
        echo \$file
        clang-format -i \$file
        git add \$file
    done
    echo  -e "\033[1;92m Adding files to current commit\e[0m"
else
    echo -e "\033[1;92m No source cpp or hpp files where detected in staged files\e[0m"
fi


EOT

chmod +x ./.git/hooks/pre-commit
