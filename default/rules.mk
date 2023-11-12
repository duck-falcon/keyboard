# Build Options
#   change yes to no to disable
#

DEFAULT_FOLDER = crkbd/rev1

# 容量が足りないため、LED関連の設定を disable にする
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no

# VIA でも認識されるようにする
VIA_ENABLE = yes
# 2回連続で押すとkeyが変わるなど https://docs.qmk.fm/#/feature_tap_dance
TAP_DANCE_ENABLE = yes
# リンク時最適化の有効化(ファームウェアの容量削減
LTO_ENABLE = yes
