#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(CYN"�C�ɤM"NOR, ({ "bronze blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��C�ɥ��y�����b�C\n");
		set("material", "copper");
		set("value",1700);
		set("limit_str",13);
	}
    set("weapon_prop/con",1);
    init_blade(19);
    setup();
}

