#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("�j�ƥ֥�", ({ "consolidate leather armor","armor" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��֥Ҹg�L�h�������s, �֤w�g�w�촶�q�L����\n"
                           "�H��J�Ҥ�, ���]�]���ϥΪ̬��ʤ��W�|��������K�C\n");
		set("unit", "��");
		set("value",3000);
		set("material","leather");
		set("limit_con",18);
		set("limit_dex",12);
	}
	set("armor_prop/dex",-1);
	set("armor_prop/shield",5);
	set("armor_prop/armor",15);
	setup();
}
