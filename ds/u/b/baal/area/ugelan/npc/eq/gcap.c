#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name("�����U",({"cap","cap"}) );
        set("long",@LONG
������U�A�վB�����u�üзǨ�A�w���ݤ�����...
LONG
);
        set_weight(100); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",50);          
                set("volume", 3);                       
                set("material", "cloth");   
        }
        set("armor_prop/armor", 1);
        setup();
}

