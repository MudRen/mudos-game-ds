#include <ansi.h>
inherit NPC;
void create()
{
 set_name("巨蛇",({"viper",}));
 set("long",@LONG
一隻很大的蛇, 應該是這個蛇穴的主人吧!.
LONG
    );
 set("race","野獸");
 set("attitude", "aggressive");
 set("level",20);
 set("limbs", ({ "頭部", "身體", "尾巴" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
