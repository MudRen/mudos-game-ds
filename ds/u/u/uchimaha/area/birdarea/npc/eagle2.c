#include <ansi.h>
inherit NPC;
void create()
{
       set_name("老鷹",({"eagle"}));
        set("level",8);
        set("race", "野獸");
        set("age", 8);
        set("long", "這是一隻老鷹。\n");
        set("limbs", ({ "頭部", "身體", "腳", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
        carry_object(__DIR__"eq/fist.c")->wield();
}
