#include <ansi.h>
inherit NPC;
void create()
{
          set_name("四不像",({ "neither fish nor fowl","fowl" }) );
           set("level",12);
             set("str",5);
             set("con",18);
      set("int",6);
        set("race", "野獸");
        set("age", 6);
        set("long", "牠是一隻長得像驢，蹄像馬，頭長了鹿角，有個牛尾的四不像。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴","鹿角" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
