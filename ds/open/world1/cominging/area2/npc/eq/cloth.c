#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("���\��", ({ "golden cloth","cloth" }) );
	set("long", "�@��{�{�o�G����A, �֦����������m�O�C\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
		set("armor_prop/con",    2);
		set("armor_prop/armor",  10);
		set("value", 7600);
	}
	setup();
}