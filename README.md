# C++ development sample

## test platform

### Commands

build

``` bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE=ON
cmake --build build
```

test

``` bash
ctest --test-dir build
```

report

``` bash
lcov --capture --directory build --output-file coverage.info
lcov --remove coverage.info '/usr/*' '*/test/*' '*/gtest*' --output-file coverage.filtered.info
genhtml coverage.filtered.info -num-spaces 4 -s --legend -o coverage_report
```

launch html report

``` bash
cd coverage_report
python3 -m http.server
```

### Troubleshooting

#### gcov failed

``` bash
Capturing coverage data from .
Subroutine read_intermediate_text redefined at /usr/bin/geninfo line 2623.
Subroutine read_intermediate_json redefined at /usr/bin/geninfo line 2655.
Subroutine intermediate_text_to_info redefined at /usr/bin/geninfo line 2703.
Subroutine intermediate_json_to_info redefined at /usr/bin/geninfo line 2792.
Subroutine get_output_fd redefined at /usr/bin/geninfo line 2872.
Subroutine print_gcov_warnings redefined at /usr/bin/geninfo line 2900.
Subroutine process_intermediate redefined at /usr/bin/geninfo line 2930.
Found gcov version: 11.4.0
Using intermediate gcov format
Scanning . for .gcda files ...
Found 1 data files in .
Processing gtest_main.cpp.gcda
/home/taka/cpp_dev/build/CMakeFiles/test_myabs.dir/test/gtest_main.cpp.gcno:version 'B23*', prefer 'B14*'
geninfo: ERROR: GCOV failed for /home/taka/cpp_dev/build/CMakeFiles/test_myabs.dir/test/gtest_main.cpp.gcda!
```

Solution:
check version of gcc and gcov is same mejor version

``` bash
gcc --version
gcov --version
```

If they are different, it needs to specify the version explicitly.

## References

- [業務効率化の道具箱（5）Google Testを使ってみよう【その1】](https://monoist.itmedia.co.jp/mn/articles/2210/20/news021.html)
- [GoogleTest + CMakeでC++の実践的なユニットテスト環境を構築する：その２（カバレッジ表示）](https://qiita.com/iydmsk/items/0021d1ef14660184f396)
