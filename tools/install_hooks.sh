#!/bin/sh

cat > ./.git/hooks/pre-commit << EOT
#!/bin/sh
bash tools/lint.sh
EOT

chmod +x ./.git/hooks/pre-commit
