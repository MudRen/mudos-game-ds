#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("����",({"cloth"}) );
	set("long","�@��γ¥�´������A�A�ˤ]�����m�H����C\n");
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",50);
		set("volume",2);
		set("armor_prop/armor",1);
	}
	setup();
}
