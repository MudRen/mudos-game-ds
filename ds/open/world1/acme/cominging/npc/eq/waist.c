#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
	set_name("�¦���y" ,({ "blackre waist","waist" }) );
	set("long","�o�O�@���x�L�Ҭ�����y�a�C\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set_weight(100);
        set("material","cloth");
		set("unit", "��" );
		set("value",400);
		set("armor_prop/armor", 2);
		set("armor_prop/hit",1);
	}
	setup();
}
