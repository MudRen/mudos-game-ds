#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�s�M", ({ "cutless" }) );
	set_weight(5500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����֨����s�M, �M���s�����񴶳q�M�ӱo�F�`,\n"
                            "�o�ؤM�j�������O��L�j�s�b�ϥΪ��C\n");
		set("value", 500);
		set("material","steel");
		set("limit_skill",25);
		set("limit_dex",10);
	}
    set("weapon_prop/hit",20);
    init_blade(25);
    setup();
}
