#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name(HIW"���l���s��"NOR,({ "prince cloth","cloth" }) );
        set("long","���q�˩Ҭ諸���l���s��C\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "��" );
        set("value",20000);
        }  
       setup();
}

