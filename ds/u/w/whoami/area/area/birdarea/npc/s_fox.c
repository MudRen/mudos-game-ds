#include <ansi.h>
inherit NPC;
void create()
{
       set_name("小狐狸",({"small fox","fox"}));
        set("level",10);
        set("race", "野獸");
        set("age", 14);
        set("max_hp",5000); 
        set("max_ap",5000);
        set("max_mp",5000);
        set("long", "這是一隻小小的狐狸。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

