#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIB "海"NOR"妖", ({"water"}) );
set("long","這是五幻妖第二隻的海之妖怪，全身都是深藍色的，滿臉鬍鬚，一付大老
粗的模樣，卻靠著堅強的意志力才登上第二名的，高超的戰鬥技巧就是吃飯的
本錢。\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
}

