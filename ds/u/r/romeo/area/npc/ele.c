#include <ansi.h>
inherit NPC;
void create()
{
set_name(YEL "電"NOR"妖", ({"electricity"}) );
set("long","這是五幻妖的老大電之妖怪，模糊的身影，無比的電量，全身發出金黃色
的光芒，有著銳不可當的氣勢。\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
}
