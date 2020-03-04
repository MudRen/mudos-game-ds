// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("�q���C", ({ "laser sword","sword" }) );
	set_weight(3600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O���ӱ`�Ϊ��Z���C\n");
		set("value",1800);
		set("material", "laser");
		set("unwield_msg", "$N�N��W��"HIB"�q���C"NOR"���ð_�ӡC\n");
	}
    init_sword(10);
	setup();
}
