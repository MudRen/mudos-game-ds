#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit ARMOR;
void create()
{
	set_name(HIC"���s�ԥ�"NOR, ({ "dragon armor","armor" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���Z�ҭ��q���t, ���L���m�O�X�_����, �ܾA�X���ӧ@��\n"
                           "��, ���L����W�֨��o�ذ��Ū��ԥ�, ����b���W�����I���ΪA.\n");
		set("unit", "��");
		set("value",40000);
		set("material","steel");
		set("limit_con",40);
		set("limit_int",10);
		set("replica_ob",__DIR__"heavyarmor.c");
	}
	set("armor_prop/dex",-3);
	set("armor_prop/dodge",-10);
	set("armor_prop/shield",25);
	set("armor_prop/armor", 45);
	setup();
}
