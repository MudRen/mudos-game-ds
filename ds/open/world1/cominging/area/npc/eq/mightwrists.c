#include <armor.h>
inherit WRISTS;
void create()
{
	set_name("�j�O�@��", ({ "mightiness wrists", "wrists" , "mightiness" }) );
	set("long", "�o�O�@�M�b���`�j�����`�����@���˳ơC\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("material","steel");
		set("unit", "�M");
		set("armor_prop/dex",   -1);
		set("armor_prop/armor",  5);
		set("value", 790);
	}
	setup();
}
