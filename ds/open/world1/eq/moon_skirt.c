#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HIM"月華裙"NOR,({"moon skirt","skirt"}) );
        set("long",@LONG
如月光般柔和的絲織裙子，散發著高雅的氣質。
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("female_only",1);
                set("unit", "件");       
                set("value",800);          
                set("volume", 2);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",3);       
        setup();
}


