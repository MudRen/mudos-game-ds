#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "�ѹ�" , ({ "mouse" }) );
	set("level",2);
	set("race","���~");
	set("age",6);
	set("long","�e�O�@��ż�������p�¹��C\n");
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	setup();
}
