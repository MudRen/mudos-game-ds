#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("���T", ({ "cloud cloth","cloth" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���A�S�s������M�_�s��k, �����ܦ����ӱj��\n"
                           "�������m�O�窫, ���L�ݰ_�ӹ��O�t�~..:p\n");
		set("unit", "��");
		set("value",5000);
		set("material","cloth");
		set("limit_con",5);
		set("limit_int",10);
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",8);
	set("armor_prop/shield",4);
	set("armor_prop/show_damage",1);
	setup();
}
