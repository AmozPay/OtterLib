#!/bin/sh

cat > ./.git/hooks/pre-commit << EOT
#!/bin/sh
bash tools/lint.sh
EOT
