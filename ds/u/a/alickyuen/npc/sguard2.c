#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"�i�f�i��-�O��"NOR, ({ "CocaCola","guard" }) );
	set("long", "�o�O�t�d�i�f�i�֤j�H�w��������H�C\n");
	set("race","�����H");
	set("age", 100);
	set("level", 50);
                set("chat_msg", ({
  HIY"�O�߻��G�S�ƪ��N�֨���C\n"NOR,
}));
                set("chat_chance_combat", 14);
                set_skill("unarmed", 100);
	setup();
}
