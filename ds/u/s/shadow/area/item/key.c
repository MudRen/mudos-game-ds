inherit ITEM;

void create()
{
  set_name("寶箱鑰匙", ({ "treasure box key", "key" }));
  set("long", @LONG
    一把早已鏽蝕的鑰匙，特殊的形狀讓你不由得多看了幾眼，鑰匙
的末端似乎有著暗紅色的木屑殘留著。
LONG
  );
  set_weight(1);
  set("unit", "隻");
  setup();
}
