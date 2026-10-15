# Image Steganography in C

## Overview

Image Steganography is a command-line application developed in C to hide a secret text file inside a BMP image using the **Least Significant Bit (LSB) technique**.

The application supports both encoding and decoding. During encoding, the secret file's metadata and contents are embedded into the image data to generate a stego image. During decoding, the application extracts the embedded information and reconstructs the original secret file.

## Features

- Hide a text file inside a BMP image.
- Extract the hidden file from a stego image.
- Use LSB-based bit manipulation for data embedding and extraction.
- Validate command-line arguments and supported file extensions.
- Check image capacity before encoding.
- Store a magic string to identify valid encoded data.
- Preserve the BMP header and copy remaining image data.
- Handle encoding and decoding errors through status values.

## Technologies Used

- **Programming language:** C
- **Concepts:** Bitwise operations, file handling, pointers, structures, functions, command-line arguments and error handling
- **File format:** BMP
- **Development environment:** GCC and Linux/Ubuntu

## How It Works

### 1. Encoding

1. Accept a source BMP image and a secret text file through command-line arguments.
2. Open the required files.
3. Check whether the image has sufficient capacity for the hidden data.
4. Copy the 54-byte BMP header to the output image.
5. Encode a magic string to identify the hidden data.
6. Encode the secret file extension length and extension.
7. Encode the secret file size.
8. Encode the secret file contents using LSB-based bit manipulation.
9. Copy the remaining source image data to complete the stego image.

### 2. Decoding

1. Open the stego image and output destination.
2. Start reading the encoded data after the 54-byte BMP header.
3. Extract and validate the magic string.
4. Decode the secret file extension length and extension.
5. Decode the original secret file size.
6. Extract the secret file contents.
7. Write the extracted bytes into the reconstructed output file.

## Project Structure

```text
stegnography/
├── encode.c
├── encode.h
├── decode.c
├── decode.h
├── magic.h
├── type.h
├── test_encode.c
├── beautiful.bmp
└── README.md
```

The repository also contains sample and output files. The structure above highlights the main source files.

## Compilation

Compile the source files using GCC:

```bash
gcc test_encode.c encode.c decode.c -o stego
```

## Usage

### Encode a secret text file

```bash
./stego -e beautiful.bmp secret.txt stego.bmp
```

- `-e`: Select encoding mode.
- `beautiful.bmp`: Source BMP image.
- `secret.txt`: Secret text file.
- `stego.bmp`: Output image containing the hidden data.

### Decode the hidden file

```bash
./stego -d stego.bmp
```

The decoder uses the encoded extension and file size to reconstruct the hidden file. Check the program's argument-validation rules for the supported output filename options.

## Key Learning Outcomes

- Understanding how individual bits can be manipulated in C.
- Applying bitwise operations to encode and decode data.
- Working with binary files using standard C file I/O.
- Using structures to organize encoding and decoding information.
- Managing command-line arguments and validating inputs.
- Understanding file metadata, image headers and error handling.

## Limitations

- The implementation is designed around BMP images.
- The current argument validation is intended for text files with a `.txt` extension.
- Encoding is limited by the available image capacity.
- LSB steganography hides data but does not encrypt it. Additional encryption would be required to protect the contents against someone who discovers and extracts the hidden data.

## Author

Monika M V

GitHub: [mvmonika04](https://github.com/mvmonika04)
