#include <ansi.h>
inherit NPC;
void create()
{
       set_name("千年巨蛙",({"thousand frog","frog"}));
        set("level",10);
        set("race", "野獸");
        set("age", 1000);
        set("long", "這是非常大的青蛙，傳說他可以活上千年。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳"}) );
        set("verbs", ({ "bite"}) );
        setup();
}
