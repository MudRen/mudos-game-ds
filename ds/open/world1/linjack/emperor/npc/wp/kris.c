#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�u�M", ({ "kris" }) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����֨����s�M, �M���s�����񴶳q�M�ӱo�F�`,\n"
                            "�o�ؤM�j�������O��L�j�s�b�ϥΪ��C\n");
		set("value", 100);
		set("material","iron");
	}
    init_blade(13,EDGED);
    setup();
}
