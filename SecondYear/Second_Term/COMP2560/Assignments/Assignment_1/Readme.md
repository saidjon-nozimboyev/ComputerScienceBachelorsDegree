minifs_assignment/
├── minifs.c
├── minifs.h
├── README.md
└── screenshots/
    ├── text_test.png
    ├── empty_file_test.png
    ├── binary_test.png
    └── directory_limit_test.png


## Testing Results

### Text File Test
The file was added, extracted, and compared successfully.

![Text file test](screenshots/text_test.png)

### Empty File Test
Empty files were added and extracted successfully.

![Empty file test](screenshots/empty_file_test.png)

### Binary File Test
The extracted binary file matched the original.

![Binary file test](screenshots/binary_test.png)

### Directory Limit Test
MiniFS rejected an attempt to add a seventeenth file.

![Directory limit test](screenshots/directory_limit_test.png)