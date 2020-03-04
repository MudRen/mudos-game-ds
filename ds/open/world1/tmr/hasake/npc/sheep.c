inherit NPC;
void create()
{
    set_name("綿羊", ({ "sheep" }) );
	set("race", "野獸");
	set("age", 5);
	set("level", 10);
    set("long", "一頭雪白可愛，又肥又壯的綿羊。\n");
	set("attitude", "peaceful");
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
    set("verbs", ({ "kick", "bite" }) );
    set("skin", __DIR__"obj/yangpi");
	setup();
}

#include "skin_drop.c"
