#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIR"���Y�b"NOR, ({ "ghost blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��M�`�W�観�@�Ӱ��Y���M, �ݨӦ��@�ѯ������O�q�C\n");
		set("material", "blacksteel");
		set("value",2000);
		set("limit_str",10);
	}
    set("weapon_prop/int",1);
    init_blade(18);
    setup();
}

