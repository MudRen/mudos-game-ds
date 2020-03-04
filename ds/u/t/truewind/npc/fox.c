// This is a npc made by npcmaker.
#include <ansi.h>
inherit NPC;

void create()
{
	set_name( WHT"銀狐"NOR, ({ "fox" }));
	set("long", "這是一隻只在高山上出沒的雪狐，牠毛色潤澤光滑，非常健康。\n");
	set("age", 1);
	set("level",1);
	set("race", "beast");
	set("verbs", ({ "bite", "claw" }) );
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("chat_chance", 10);
        set("chat_msg", ({
           (: random_move :),
           ("銀狐靜靜的四處張望著。\n"),
}) );
        
	setup();
}
