#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("�ˤM", ({ "bamboo blade","wood" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��M�O�w�˫d���A���ӽm�M�O�������γ~�C\n");
		set("value", 300);
		set("material", "wood");
	}
    init_blade(5);
    setup();
}
