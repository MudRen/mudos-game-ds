#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小灰熊",({ "bear" }) );
        set("level",7);
        set("race", "野獸");
      set("str",3);
       set("age", 1);
        set("long", "牠是一隻小隻的灰熊。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
