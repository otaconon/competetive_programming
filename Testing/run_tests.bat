@echo off
setlocal enabledelayedexpansion

:: Set the C++ source file and executable name
set "CPP_FILE=Stefan.cpp"
set "EXECUTABLE=stefan"

:: Compile the C++ program
echo Compiling %CPP_FILE%...
g++ -o %EXECUTABLE%.exe %CPP_FILE%
if %ERRORLEVEL% neq 0 (
    echo Compilation failed!
    exit /b 1
)
echo Compilation successful.

:: Set directories for inputs and expected outputs
set "INPUT_DIR=stefan_tests/in"
set "OUTPUT_DIR=stefan_tests/out"

:: Loop through all .in files in the INPUT_DIR
for %%F in (%INPUT_DIR%\*.in) do (
    :: Get the base name of the input file (without extension)
    set "input_file=%%~nxF"
    set "base_name=%%~nF"
    
    :: Define the expected output file and the file to store the actual output
    set "expected_output_file=%OUTPUT_DIR%\!base_name!.out"
    set "actual_output_file=!base_name!_actual.out"
    
    :: Run the executable with the input file and redirect the output to a temporary file
    %EXECUTABLE%.exe < %%F > !actual_output_file!
    
    :: Check if the program ran successfully
    if !ERRORLEVEL! neq 0 (
        echo Program failed with input %%F!
        exit /b 1
    )
    
    :: Compare the actual output with the expected output
    fc !actual_output_file! !expected_output_file! > nul
    if !ERRORLEVEL! neq 0 (
        echo Wrong %%F!
    ) else (
        echo Ok %%F!
    )
    
    :: Optionally, remove the actual output file after the comparison
    del !actual_output_file!
)

echo All tests completed.
pause
