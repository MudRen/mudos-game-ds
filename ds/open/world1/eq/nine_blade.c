#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("�E���b", ({ "blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��M�I�W�����E�Ӷ������M, �۷�A�X����H�h�ϥΡC\n");
		set("material", "blacksteel");
		set("value",2000);
		set("limit_str",10);
	}
    set("weapon_prop/str",2);
    init_blade(20);
    setup();
}

