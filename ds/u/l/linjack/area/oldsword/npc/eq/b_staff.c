#include <weapon.h>
#include <ansi.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
	set_name("���ɪ���", ({ "brass cane","cane" }) );
	set_weight(18500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O��Ьɳ̰��Z���`�`�����@�ح����L��, �Q���­�,\n"
                            "���O�Y�O�q���j�i�H���ⴧ�R�����˼Ī���, �ҳy�����j�j\n"
                            "�ˮ`�O���ȬO���H�_�����C\n");
		set("value", 10000);
		set("material", "copper");
		set("limit_skill",50);
		set("limit_str",45);
		set("limit_con",25);
		set("replica_ob",__DIR__"staff");
        }
    set("weapon_prop/dex",-1);
    set("weapon_prop/str",2);
    init_staff(75,TWO_HANDED);
    setup();
}
