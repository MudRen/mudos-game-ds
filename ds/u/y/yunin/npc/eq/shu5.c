#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIR"��ù�@����"NOR,({"shu lou mask","mask"}) );
        set("long",@LONG
�|�j������@���P�D�ۨϥΪ�����C
LONG
);
        set_weight(299); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "��");       
                set("value",3400);          
                set("volume", 2);   
                set("material","cold");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/con",1);
 setup();
}

