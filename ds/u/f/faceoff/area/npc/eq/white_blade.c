#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIW"�զ���b"NOR, ({ "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��զ⪺�Ԥb, �ݨӫܨI�����ˤl�C\n");
		set("material", "steel");
		set("value",1700);
		set("limit_str",10);
	}
    set("weapon_prop/str",1);
    init_blade(20);
    setup();
}

