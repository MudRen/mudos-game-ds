#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("����j�M", ({ "two-handed great blade","blade" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��M�`���񤻤�, �_���L��, ���L���M�Q���W�Q, �u�O�j�j�̤]\n"
                            "�������i���ʦ��M, �Y�O�u�O�y�z��, ���ȳs�O���X�T����O�]�S���C\n");
		set("value", 5000);
		set("material", "steel");
		set("limit_skill",25);
		set("limit_str",35);
		set("limit_con",25);
        }
    set("weapon_prop/dex",-3);
    set("weapon_prop/int",-3);
    set("weapon_prop/hit",-5);
    init_blade(60,TWO_HANDED);
    setup();
}
