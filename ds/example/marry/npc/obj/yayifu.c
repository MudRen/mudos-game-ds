// yayi_cloth.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�ŧЪA", ({ "yayi cloth", "cloth" }));
	set("long", "�o�O�@���s���մ֥��ŧЪA�C\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 150);
		set("armor_prop/armor", 5);
	}
	setup();
}
