#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("������m", ({ "thinly dress","dress" }));
	set_weight(300);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",300);
		set("armor_prop/dex",1);
		set("armor_prop/armor",1);
		set("armor_prop/dodge",1);
		set("female_only",1);
	}
	setup();
}