#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(BLU"�c��"HIR"�]"HIW"�ܭ�"NOR,({"Dreamcast cloak","cloak"}) );
        set("long",@LONG
�o��ܭ��O�q��ӨӪ��A�S�H���D�A�۶ǬO���]�諸�E
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "��");       
                set("value",900);          
                set("volume", 3);                       
                set("material", "silk");   
        }
        setup();
}

