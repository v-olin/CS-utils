# Math tools

## krs.py: Solves problems using the Chinese remainder theorem and shows steps
  
  Example: Given these equations
  ```
  x = 3 mod 4
  x = 1 mod 5
  x = 6 mod 9
  ```
  Solve for 'x' by running the command
  ```
  >python krs.py "3,4,1,5,6,9"
  ```
  Resulting in the output
  ```
  States of conditions:
  a1: 3   N1: 45  b1: 1
  a2: 1   N2: 36  b2: 1
  a3: 6   N3: 20  b3: 5

  According to a*b*N:
  3*1*45 + 1*1*36 + 6*5*20 = 771
  771 (mod 180) => x = 51 (mod 180)
  ```

# mod.py: Solves power equations with modulo and shows steps

  Example: Given this equation
  ```
  32^47 mod 17
  ```
  Solve by running the command
  ```
  >python mod.py "32,47,17"
  ```
  Resulting in the output
  ```
  32 = (17 * 1 + 15)
  15^32 * 15^8 * 15^4 * 15^2 * 15^1
  15^1 = 15
  15^2 = 225
  15^4 = 4^2 = 16
  15^8 = (10+6)^2 = 100 + 120 + 36 = 1
  15^16 = 1^2 = 1
  15^32 = 1^2 = 1
  15^47 = 1 * 1 * 16 * 4 * 15
  15^47 = 8 (mod 17)
  ```