#!/bin/bash

# Function to display an error message and exit
error_exit() {
    echo "Error: $1"
    exit 1
}

# Function to prompt the user for input
prompt_input() {
    local prompt="$1"
    local variable_name="$2"
    
    read -rp "$prompt: " input
    if [[ -z "$input" ]]; then
        error_exit "Input cannot be empty."
    fi
    eval "$variable_name='$input'"
}

# Prompt user for image name
prompt_input "Enter the path to the image file" IMAGE

# Prompt user for file system type
prompt_input "Enter the file system type (e.g., ntfs)" FILESYSTEM

# Prompt user for destination folder
prompt_input "Enter the path to the export folder" DEST

# Create the destination directory if it doesn't exist
mkdir -p "$DEST" || error_exit "Failed to create destination directory."

# Use fls to list all files and directories
echo "Listing files and directories in the image..."
fls -r -f "$FILESYSTEM" "$IMAGE" 2>/dev/null | while IFS=$' \t:' read -r filetype filenode filename; do
    # Check for any error in fls output
    if [[ $? -ne 0 ]]; then
        error_exit "Error listing files with fls."
    fi
    
    # Check if the file type is 'r/r' (regular file) or 'd/d' (directory)
    if [ "$filetype" = "r/r" ]; then
        echo "Processing file: $filename"
        
        # Create the necessary directory structure for the file
        mkdir -p "$(dirname "$DEST/$filename")" || error_exit "Failed to create directory structure for $filename"
        
        # Extract the file using icat and redirect output to the destination
        icat -i ewf -f "$FILESYSTEM" -r -s "$IMAGE" "$filenode" > "$DEST/$filename" || error_exit "Failed to extract file $filename"
    elif [ "$filetype" = "d/d" ]; then
        echo "Creating directory: $filename"
        
        # Create the directory in the destination
        mkdir -p "$DEST/$filename" || error_exit "Failed to create directory $filename"
    fi
done

echo "Processing complete."
