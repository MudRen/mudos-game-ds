#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name("�����@��",({"bu-sian hands","hands"}) );
        set("long",@LONG
��o���@�áA�W���観������Ī������C
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "��");       
                set("value",1200);          
                set("volume", 3);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/str",2);
        set("armor_prop/tec",-1); 
        setup();
}


