#include <ansi.h>
inherit NPC;
void create()
{
  set_name("桃盛", ({ "tao sheng", "sheng" }) );
  set("long","桃盛一位方士，屬於圖龍丹派，精於燒丹製藥。\n");
  set("title", "圖龍丹派");
  set("level", 5);
  set("age", 30);
  setup();
}

