#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("���M", ({ "great blade","blade" }) );
	set_weight(35000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�M�����T��ɥN�������Ϊ��j�M, ���L�ΤM�̤@�����M�N����Q��\n"
                            "�­�, �¤O���l, �F�դ���, �ä��A�X���Ӫ񨭧@�ԡC\n");
		set("value", 7000);
		set("material", "steel");
		set("limit_skill",15);
		set("limit_str",35);
		set("limit_con",25);
        }
    set("weapon_prop/dex",-5);
    set("weapon_prop/int",-1);
    set("weapon_prop/hit",-15);
    set("weapon_prop/dodge",-10);
    init_blade(80,TWO_HANDED);
    setup();
}
