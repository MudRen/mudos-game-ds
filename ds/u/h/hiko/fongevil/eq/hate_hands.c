#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name("���",({"hate hands","hands"}) );
        set("long",@LONG
�ѩ�D�H�O�t��Ӧ��A�]����𷥭����@�áC
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
        

                set("unit", "��");       
                set("value",3200);          
                set("volume", 3);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",2);       
        set("armor_prop/con",1); 
        setup();
}

