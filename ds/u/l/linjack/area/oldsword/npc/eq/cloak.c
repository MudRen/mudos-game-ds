#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name("����ܭ�", ({ "cloak" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��T���M������W, ���L�ݰ_�ӴN���H�@�ثܴ��q���Pı.\n");
		set("unit", "��");
		set("value",1000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_dex",10);
	}
	set("armor_prop/armor",5);
	set("armor_prop/shield",1);
	setup();
}
