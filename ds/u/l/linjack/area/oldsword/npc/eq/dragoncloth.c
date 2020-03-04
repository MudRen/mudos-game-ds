#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;
void create()
{
	set_name(HIC"���s�Ԧ�"NOR, ({ "dragon cloth","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��Ԧ�W���Ϯ��ê��s�˻�R, �����O�X�ۭ��a�����Ŧ窫,\n"
                           "���L�j���O�������ժ��H�~�|��o�ئ�A, ���L�b�A�ݨ�, �o��A\n"
			   "���G�O��㦳���t�O�q����A.\n");
		set("unit", "��");
		set("value",18000);
		set("material","cloth");
		set("limit_con",20);
		set("limit_int",30);
		set("replica_ob",__DIR__"cloth.c");
	}
	set("armor_prop/dex",3);
	set("armor_prop/str",3);
	set("armor_prop/dodge",15);
	set("armor_prop/armor",10);
	set("armor_prop/show_damage",1);
	setup();
}
