#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIC "風"NOR"妖", ({"wind"}) );
set("long","這是一隻風之妖怪，二十年前被秦始皇收服，看上去形體好像是虛幻的，
但是力量不是你想像的那麼弱喔。\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
}
