#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"�L���ԥ�"NOR,({ "wu ji armor","armor" }) );
	set("long","�o�O�@��ѯQ�������B�Τ�u�s´�Ӧ�����\n"
		   "�ҡA�Q�����O�x�A�o�]�۷��K��A�s�W�n\n"
		   "���L�b���L�k�˥����@�A�b�Q�����~���е�\n"
		   "�@�h�C���A��W�䨾�m�ʯ�C\n");
	set_weight(15000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",6);
         set("material","steel");
		set("unit", "��" );
       set("value",7500);
		set("armor_prop/armor", 30);
		set("armor_prop/shield",10);
	}
	setup();
}
