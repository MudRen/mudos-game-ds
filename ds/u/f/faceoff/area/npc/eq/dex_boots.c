#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIW"���n�u"NOR, ({ "boots" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�o�O�@���ѨB�����һs�����u�l, �ݨӬ۷�öQ!\n");
                set("unit", "��");
	set("value",10000);
                set("material","fur");
	 set("armor_prop/dex",2);
	set("armor_prop/con",1);
                set("armor_prop/shield",2);
                set("armor_prop/armor", 16);
        }
        setup();
}
