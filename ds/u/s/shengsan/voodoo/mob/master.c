#include <path.h>
inherit NPC;

void create()
{
	set_name("�Ŭr�оɮv", ({"master"}) );
	set("race", "�H��");
	set("gender", "�k��");
	set("level",55);
	set("age", 40);
	set("long", "�@��Ŭr�Ъ��ɮv���b�оɥL���{�̪Z��\n");
        set_skill("blade",100);

	setup();

	add_money("coin",500);
	carry_object(SHENGSAN+"voodoo/eq/leggings")->wear();
}
