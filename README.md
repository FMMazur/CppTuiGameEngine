# Autor
Felipe Muñoz Mazur

# Build instructions:

```sh
mkdir build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -S . -B build
ninja -C build # builds everything
ninja -C build tp1_ui_test # build tests
```

# Run tests:
```sh
./build/tests/tp1_ui_test # run tests
```

## Description
A little cpp engine for a school work.

