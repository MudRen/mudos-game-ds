#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("�A��", ({ "cloth" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���������, �O�m�Z�̱`�諸��A, ���L���祬�ƫo\n"
			   "�Q�����륩�n��, ���ӬO�����H�a�b�諸���.\n");
		set("unit", "��");
		set("material", "cloth");
		set("value",500);
	}
	set("armor_prop/shield",2);
	set("armor_prop/armor", 4);
	setup();
}
