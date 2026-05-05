# MISRA C:2025 Single Translation Unit Test Cases

A collection of C test files for MISRA C:2025 rules that apply within a single translation unit (Appendix B).

## File Naming Convention

```
MISRAC-{major}-{minor}-{variant}-{TYPE}.c
```

| `{TYPE}` | Meaning | Expected tool behavior |
|----------|---------|------------------------|
| `NC` | Non-Compliant | Tool **should** report the rule violation |
| `C`  | Compliant     | Tool **should not** report (False Positive test) |
| `MIX` | Mixed        | File contains both compliant and non-compliant code |

Examples:
- `MISRAC-14-4-1-NC.c` — Rule 14.4, non-compliant code, violation expected
- `MISRAC-6-3-1-C.c`   — Rule 6.3, compliant code, no report expected
- `MISRAC-7-5-2-MIX.c` — Rule 7.5, mixed code

## Coverage

| Type | Count |
|------|-------|
| NC (Non-Compliant) | 146 |
| C  (Compliant)     | 13  |
| MIX (Mixed)        | 3   |
| **Total**          | **162** |

## Usage

**GCC with `-Wmisra-c`**
```bash
gcc -Wmisra-c -std=c11 MISRAC-X-Y-Z-NC.c
```

**PC-lint Plus with `au-misra5.lnt`**
```bash
pclp64_linux au-misra5.lnt gcc.lnt "-width(0)" MISRAC-X-Y-Z-NC.c
```

## Evaluation Metrics

Each test file contributes one of four outcomes for a given tool:

| Outcome | Condition |
|---------|-----------|
| TP (True Positive)  | NC/MIX file — tool detected the rule |
| FN (False Negative) | NC/MIX file — tool missed the rule |
| TN (True Negative)  | C file — tool correctly did not report |
| FP (False Positive) | C file — tool incorrectly reported a violation |

---

# MISRA C:2025 單一翻譯單元測試案例

本倉庫收錄 MISRA C:2025 附錄 B（Single Translation Unit）所有規則的 C 測試檔案。

## 檔案命名慣例

```
MISRAC-{major}-{minor}-{variant}-{TYPE}.c
```

| `{TYPE}` | 意義 | 工具預期行為 |
|----------|------|------------|
| `NC` | 非合規（Non-Compliant） | 工具**應**回報違規 |
| `C`  | 合規（Compliant）       | 工具**不應**回報（誤報測試） |
| `MIX` | 混合                   | 檔案同時含合規與非合規程式碼 |

範例：
- `MISRAC-14-4-1-NC.c` — Rule 14.4，非合規程式碼，預期偵測到違規
- `MISRAC-6-3-1-C.c`   — Rule 6.3，合規程式碼，預期無回報
- `MISRAC-7-5-2-MIX.c` — Rule 7.5，混合程式碼

## 涵蓋範圍

| 類型 | 數量 |
|------|------|
| NC（非合規測試） | 146 |
| C（合規測試）   | 13  |
| MIX（混合測試） | 3   |
| **合計**        | **162** |

## 使用方式

**GCC 搭配 `-Wmisra-c`**
```bash
gcc -Wmisra-c -std=c11 MISRAC-X-Y-Z-NC.c
```

**PC-lint Plus 搭配 `au-misra5.lnt`**
```bash
pclp64_linux au-misra5.lnt gcc.lnt "-width(0)" MISRAC-X-Y-Z-NC.c
```

## 評估指標

每個測試檔案對應四種結果之一：

| 結果 | 條件 |
|------|------|
| TP（真陽性） | NC/MIX 檔 — 工具偵測到違規 |
| FN（假陰性） | NC/MIX 檔 — 工具未偵測到違規 |
| TN（真陰性） | C 檔 — 工具正確地未回報 |
| FP（假陽性） | C 檔 — 工具錯誤地回報了違規 |
