#!/bin/bash
echo "=== ADDITION TESTS ==="
echo "Input: 123 + 456 | Expected: 579"
../a.out 123 + 456
echo ""
echo "Input: -123 + -456 | Expected: -579"
../a.out -123 + -456
echo ""
echo "Input: 500 + -200 | Expected: 300"
../a.out 500 + -200
echo ""
echo "Input: 200 + -500 | Expected: -300"
../a.out 200 + -500
echo ""
echo "=== SUBTRACTION TESTS ==="
echo "Input: 500 - 200 | Expected: 300"
../a.out 500 - 200
echo ""
echo "Input: 200 - 500 | Expected: -300"
../a.out 200 - 500
echo ""
echo "Input: 123 - -456 | Expected: 579"
../a.out 123 - -456
echo ""
echo "Input: -123 - 456 | Expected: -579"
../a.out -123 - 456
echo ""
echo "=== MULTIPLICATION TESTS ==="
echo "Input: 12 x 13 | Expected: 156"
../a.out 12 x 13
echo ""
echo "Input: -12 x -13 | Expected: 156"
../a.out -12 x -13
echo ""
echo "Input: 12 x -13 | Expected: -156"
../a.out 12 x -13
echo ""
echo "=== DIVISION TESTS ==="
echo "Input: 156 / 12 | Expected: 13"
../a.out 156 / 12
echo ""
echo "Input: -156 / -12 | Expected: 13"
../a.out -156 / -12
echo ""
echo "Input: 156 / -12 | Expected: -13"
../a.out 156 / -12
