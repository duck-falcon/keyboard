# Build Options
#   change yes to no to disable
#

DEFAULT_FOLDER = crkbd/rev1

# 容量が足りないため、LED関連の設定を disable にする
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no

# 容量が足りないので　VIA で認識されなくて良い
VIA_ENABLE = no
# 2回連続で押すとkeyが変わるなど https://docs.qmk.fm/#/feature_tap_dance
TAP_DANCE_ENABLE = yes
# リンク時最適化の有効化(ファームウェアの容量削減, 全く意味ないけど一応
LTO_ENABLE = yes
# combo(同時押しでキーが変わる) 有効化, https://docs.qmk.fm/#/feature_combo
COMBO_ENABLE = yes

