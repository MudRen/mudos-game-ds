inherit NPC;
#include "skin_drop.c"
void create()
{
    set_name("大灰狼", ({ "gray wolf", "wolf" }) );
    set("race", "beast");
    set("age", 10);
    set("long", "一頭高大的惡狼, 來勢如電, 露出白森森的獠牙。\n");
    set("attitude", "aggressive");
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance", 5);
	set("chat_msg", ({
                "「嗥~~~~」大灰狼發出一聲嗥叫。\n",
                "大灰狼發出一聲嗥叫，好像隨時都要撲上來！\n",
	}) );
	set("level", 20);
	set("skin", __DIR__"obj/langpi");
	setup();
}

