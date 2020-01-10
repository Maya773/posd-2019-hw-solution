# POSD 2019 作業參考

這是修有進老師 POSD 2019年的作業解答和期中上機考的答案。\
請注意作業並沒有每次滿分，但8次作業平均分數為95.375，因此放上來供來自未來的學弟妹參考。

8次作業分別用不同的 Branch 儲存，使用 `git checkout branch-name` 來切換你要參考的作業。

## 8次作業分數與扣分原因
TA 批改玩作業會寄信，告知分數與扣分原因。

| 作業 | 分數 | 扣分原因                                                               | Branch 切換語法              |
| ---- | ---- | ---------------------------------------------------------------------- | ---------------------------- |
| HW1  | 98   | 不構成等腰三角形， 沒測throw string(local端)                           | `git checkout hw/shapes`     |
| HW2  | 100  | N/A                                                                    | `git checkout hw/shapes`     |
| HW3  | 100  | N/A                                                                    | `git checkout hw/shapes`     |
| HW4  | 100  | N/A                                                                    | `git checkout hw/filesystem` |
| HW5  | 100  |                                                                        | `git checkout hw/5`          |
| HW6  | 80   | findvisitor未確實使用visitor pattern 因為還使用到型別判斷來做遞迴 扣20 | `git checkout hw/6`          |
| HW7  | 95   | build folder測試不足扣5                                                | `git checkout hw/7`          |
| HW8  | 90   | 改檔名沒有使用observer扣10                                             | `git checkout master`        |

## 2次期中考分數與扣分原因

| 考試   | 分數 | 扣分原因                                                                  | Branch 切換語法               |
| ------ | ---- | ------------------------------------------------------------------------- | ----------------------------- |
| Mid #1 | 100  | 完美拆台                                                                  | `git checkout midterm/first`  |
| Mid #2 | 92   | SetIteratorException TA測試扣3分 code扣1分 ReuseFlattenedSetVisitor 扣4分 | `git checkout midterm/second` |

