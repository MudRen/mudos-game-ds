#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIG"�츭���c"NOR, ({ "boots" }) );
        set_weight(2100);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long",HIC"�츭�W�ԩҬ諸�c�l�C\n"NOR);
                set("unit", "��");
        set("value",3100);
                set("material","fur");
         set("armor_prop/dex",3);
        set("armor_prop/con",2);
       
                
                set("armor_prop/armor", 7);
        }
        setup();
}
