#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"�s�˹u"NOR, ({ "dragon boots","boots" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�s�֥��y���u�l!\n");
                set("unit", "��");
        set("value",5000);
        set("material","fur");
        }
        set("armor_prop/dex",1);
        set("armor_prop/str",1);
        set("armor_prop/dodge",4); 
        set("armor_prop/armor", 20); 
        set("limit_lv",25);
        set("limit_str",40);
        setup();
}

