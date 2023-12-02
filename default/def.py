
# ファイルを開く
with open('def.txt', 'r') as file:
    # 各行を読み込んでリストに格納する
    lines = file.readlines()

# 改行文字を削除する
lines = [line.strip() for line in lines]

for s in lines:
  print(f"NI_{s},")

print("\n")
for s in lines:
  print(f"const uint16_t PROGMEM cm_{s}[] = {{NI_SHIFT_R, NI_{s}, COMBO_END}};")
print("\n")

for s in lines:
  print(f"COMBO(cm_{s}, NI_{s}),")
print("\n")

for s in lines:
  print(f"""case NI_{s}:
  if (record->event.pressed) {{""")
  t = list(s)
  for c in t:
    print(f"    tap_code(KC_{c});")
  print("""  }
  return false;""")