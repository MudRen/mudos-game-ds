#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIR"��ù�����"NOR,({"shu lo neck","neck"}) );
        set("long",@LONG
�|�j������@���P�D�ۨϥΪ�����C
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",1000);          
                set("volume", 2);                       
                set("material", "cold");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/con",1);
        setup();
}

