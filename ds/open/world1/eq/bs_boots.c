#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("�~�ֹu",({"beast boots","boots"}) );
        set("long",@LONG
�~�ְ����u�l�A��_�ӳn�n���ܵΪA�C
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",600);          
                set("volume", 4);                       
                set("material", "skin");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/dex",1);
        setup();
}


