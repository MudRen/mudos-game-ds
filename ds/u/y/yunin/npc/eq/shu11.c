#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(HIR"��ù�ܭ���"NOR,({"shu lo cloak","cloak"}) );
        set("long",@LONG
�|�j������@���P�D�ۨϥΪ�����C
LONG
);
        set_weight(900); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "��");       
                set("value",2100);          
                set("volume", 2);                       
                set("material", "cold");   
        }
        set("armor_prop/armor",10);       
        set("armor_prop/con",1);
setup();
}

