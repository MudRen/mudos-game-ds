#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name("����",({"long skirt","skirt"}) );
        set("long",@LONG
�ε����������Ȥl,���o�۰��Q�����C
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("female_only",1);
                set("unit", "��");       
                set("value",1000);          
                set("volume", 4);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",5);       
        setup();
}

