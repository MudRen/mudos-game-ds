#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("���\\�y�a",({"gold-silk waist","waist"}) );
        set("long",@LONG
���\��´�����y�a�A�{�{�o�����H�եءC
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "��");       
                set("value",1500);          
                set("volume", 3);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}
