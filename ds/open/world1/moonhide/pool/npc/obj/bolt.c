#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIR"�z�P���b"NOR,({"bomb-bolt","bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long",HIR"�ܹFù�һs���b�A���ˤO�j�j�C\n"NOR);
        }
set("value", 8000);
set_weight(2000);
set("amount",30);                
set("bullet/damage",200+random(111));        
set("bullet/unit","��");        
set("bullet/name",HIR"�z�P���b"NOR);      
set("type","small");            
setup();
}

