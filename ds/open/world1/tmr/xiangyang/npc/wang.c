// wang.c 王堅
#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("王堅", ({ "wang jian", "wang", "jian" }));
	set("gender", "男性");
	set("title", HIY"襄陽守備大將"NOR);
	set("age", 40);
	set("str", 35);
	set("dex", 36);
	set("long", "這是一個大宋襄陽守備主將，滿臉征塵。\n");
	set("combat_exp", 150000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("changquan", 80);
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);

	setup();
}

