#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("�P���_��", ({ "sun armor","armor" }) );
	set_weight(11000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
�o�O�@��Q�Ω��߰��ť��y����T�_�ҡC�w�ץi�P�p�۬ۤ�A
ű�y�o���_�Ҫ��H�w�g���i�ҤF�A���L����o�󲯥Ҫ��ǻ��ˬO��
�֡C
[�i�x�s�˳�]
LONG
);
		set("unit", "��");
		set("material", "rock");
		//set("no_sell",1);
		set("no_sac",1);
		set("value",4800);
	}
	set("armor_prop/fire", 12); //���t����.
	set("armor_prop/shield",10);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}

int query_autoload() { return 1; }