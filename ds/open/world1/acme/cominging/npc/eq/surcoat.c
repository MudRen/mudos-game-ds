#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name(HIY"�����j��"NOR,({ "joh ji surcoat","surcoat" }) );
	set("long","�o�O�@��x�L�Ҭ�۪��j��A�j����L�۲r�ꪺ�ˤl�A�Q���n�ݡC\n");
	set_weight(6000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",4);
        set("material","fur");
		set("unit", "��" );
		set("value",1100);
		set("armor_prop/armor", 9);
		set("armor_prop/shield",2);
	}
	setup();
}
