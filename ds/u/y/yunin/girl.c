#include <ansi.h>
inherit NPC;
void create()
{

        set_name(HIM"小君"NOR, ({ "little jim","jim" }) );
        set("long",
        HIC"他是麻將館的第一把交椅，陪了客人打麻將已有十幾年，每個人使用過都說棒。\n"NOR
        );
        set("class","fighter");
        set("gender","female");
        set("age",24);
        set("level",100);
setup();   
   
}

