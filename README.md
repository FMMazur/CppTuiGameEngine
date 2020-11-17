# Author
Felipe Muñoz Mazur

**Needs at least c++ 17**

## Linux
### Build instructions:
#### Ninja
```sh
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -S . -B build
ninja -C build # builds everything
ninja -C build tp1_ui_test # build tests
```
#### Makefile
```sh
cmake -S . -B build
make -C build
```

### Run tests:
```sh
./build/tests/tp1_ui_test # run tests
./build/tests/tp1_ui_test -s # show success
```

#### Check memory leak at linux:
```sh
valgrind --leak-check=yes -s ./build/tests/tp1_ui_test
```

#### Expected result
```sh
...
== ??? == ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
#??? expected to be a number
```

## Windows
> Suggestion:
> Use cmake-gui

### Generate Visual Studio project:
```bat
cmake -G "Visual Studio 16 2019" REM for vs 2019
cmake -G "Visual Studio 15 2017" REM for vs 2017
```

## Description
A little cpp engine for a school work.


### Project Info
  * A1 - Game
    * Scene List
      * [x] add scene
      * [x] remove scene
      * [x] remove all scenes
      * [x] get scene pointer by name
      * [x] iterate scenes
    * [x] display game in output

  * A2 - Scene
    -[x] get and change name
    * Game Object List
      * [x] add new game object
      * [x] remove game object
      * [x] remove all game objects
      * [x] get game object pointer by name
      * [x] iterate game objects
    * [x] display scene

  * A3 - Game Object
    * [x] get and change name
    * Game Object List - childs
      * [x] add new game object
      * [x] remove game object
      * [x] remove all game objects
      * [x] get game object pointer by name
      * [x] iterate game objects

    * Component List
      * [x] add new component
      * [x] remove component - (except transform)
      * [x] remove all components - (except transform)
      * [x] get component pointer by name
      * [x] iterate components

    * [x] display game object

  * A4 - Component
    * [x] get class name
    * [x] display component

  * A5 - tests
    * [x] Create
    * [x] Edit
    * [x] Display

* Goals
  * [x] encapsulation
  * [x] inheritance
  * [x] polymorphism

* Extras
  - Templates
  - Unit tests
  - Utils Classes and Structs
    - Color
    - Comparator
    - Texture
    - Vector2
    - Vector3
    - Vertex

