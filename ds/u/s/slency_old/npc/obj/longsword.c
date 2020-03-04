// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIC"�@��"HIW"�ѼC"NOR, ({ "sword" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@�⯫�P��P���P�C�M�֦��������O�q, ����q�j���u���@�Ӥ祪�k, �۷�M�աC\n");
		set("value", 5400);
		set("material", "steel");
		set("wield_msg", "$N�N����V�Ѫ�, �ѪŬ�M����"HIW"�@���ե�"NOR"�g�V$N�⤤, ��^��$N�⤤�w���F�@��$n�C\n");
		set("unwield_msg", "$N�N�⤤��$n���Ť��@��, �~�M�̪Ů����F!!�A���T�h�çA�O���O����C\n");
	}
    init_sword(10000);
	setup();
}
