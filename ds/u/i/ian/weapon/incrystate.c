#include <armor.h>
inherit ARMOR;
void create()
{
	set_name("�w�֥�", ({ "incrystate armor", "armor" , "incrystate","�w�֥�"  }) );
	set("long",
		"�o�O�b���j�������Ұ�檺����A�֦��٤��������m�O�A���L���\n"
		"�k�N�������N�S�����m�i���C\n");
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
		set("armor_prop/armor",  6);
		set("limit_dex",4);
		set("value", 1800);
	}
	setup();
}