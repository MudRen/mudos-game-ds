#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("�j�M", ({ "weirblade","blade" }) );
	set_weight(12500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��M�`���񤭤�, ���q����, �n����~�බ�Q�����ʳo��\n"
                            "�j�M, ���M�������ű, �b����ӾW�Q, ���ˤO���p�C\n");
		set("value", 2500);
		set("material", "steel");
		set("limit_skill",15);
		set("limit_str",25);
		set("limit_con",15);
        }
    set("weapon_prop/dex",-2);
    set("weapon_prop/int",-1);
    set("weapon_prop/hit",-15);
    init_blade(40,TWO_HANDED);
    setup();
}
