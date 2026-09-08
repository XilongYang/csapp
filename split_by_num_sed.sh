#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "用法: $0 <文件1> [文件2 ...]"
  exit 1
fi

for file in "$@"; do
  [[ -f "$file" ]] || { echo "错误: 文件不存在: $file"; exit 1; }

  # GNU sed 写法（Linux 常见）
  # 1) 去掉行尾 \r（兼容 CRLF）
  # 2) 在“行号（开头或空格后的数字+空格）”前插入换行
  # 3) 删除可能新增的首个空行
  sed -E -i 's/\r$//; s/(^| )([0-9]+ )/\n\2/g; 1 s/^\n//' "$file"
done
