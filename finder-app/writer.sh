if [ $# -lt 2 ]; then
    echo "Error: missing arguments. Usage: $0 <writefile>"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")" || {
    echo "Error: Failed to create directory"
    exit 1
}

echo "$writestr" > "$writefile" || {
    echo "Error: Failed to write to $writefile"
    exit 1
}

exit 0
