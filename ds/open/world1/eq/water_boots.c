#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"����u"NOR, ({ "boots" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�o�O�@���۷����u�l, �ݨӥi�H���Ѭ۷����@.\n");
                set("unit", "��");
                set("material","fur");
	set("value",3000);
	 set("armor_prop/dex",2);
                set("armor_prop/shield",1);
                set("armor_prop/armor", 14);
        }
        setup();
}
