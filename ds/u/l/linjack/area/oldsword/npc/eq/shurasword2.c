#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("�C�ؤj�C", ({ "great sword","sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��j�C�Q�����j, �ӥB�_���L��, ���Q���W�Q�C\n");
		set("value",12500);
		set("material", "crimsonsteel");
		set("wield_msg","$N�u��v�a�@�n�w�w��X�@��$n���b�⤤.\n");
		set("unwield_msg","$N�N�⤤��$n�w�w���^�C�T�����C\n");
		set("limit_skill",30);
        	set("limit_str",50);
	}
    set("weapon_prop/dex",-2);
    set("weapon_prop/parry",-5);
    set("weapon_prop/int",-2);
    set("weapon_prop/str",2);
    set("weapon_prop/hit",-5);
    init_sword(50);
    setup();
}
