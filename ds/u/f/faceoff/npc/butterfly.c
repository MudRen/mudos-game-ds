#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����" , ({ "butterfly" }) );
        set("level",1);
	set("str",0);
	set("int",0);
	set("con",0);
	set("dex",0);
	set("max_hp",3);
	set("hp",3);
	set("race","���~");
        set("age",1);
        set("long","�e�O�@���ܤp�������C\n");
        set("limbs", ({ "�Y��", "����", "Ĳ��", "����", "�k��" }) );
        set("verbs", ({ "bite" }) );
        setup();
}
