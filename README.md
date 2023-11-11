## Corne V3 の Mac 用キー配列を作るためのリポジトリ

### https://zenn.dev/duck_falcon/articles/3520a609e84ed6 に当時やったことを書いた

### qmk_firmware/keyboards/crkbd/keymaps/default のなかの keymap.c と config.h を保存
### qmk_firmware/keyboards/crkbd/ のなかの rules.mk を保存

## ビルド方法
qmk_firmware ディレクトリを更新後、
```bash
qmk compile -kb crkbd -km default
```
を打つ。
QMK Toolkit でキーボードに crkbd_rev1_default.hex を書き込む。

