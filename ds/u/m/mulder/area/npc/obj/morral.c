#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name( HIC "���§Q" NOR, ({"morral" }) );
	set("long", "�L�ݰ_�ӤQ���H�@�Ӷ̤l�I\n");
	set("race", "�H��");
	set("gender", "�k��");
	set("age", 30);
	set("level", 20);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("thundersword", 100);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
            (:command("exert thundersword"):),
            }) );

	set("title", "�y�L�OMud�ت��@�ӶW�Ŷ̤l�z");
	
	setup();
	
	carry_object("/obj/longsword.c")->wield();
}
	