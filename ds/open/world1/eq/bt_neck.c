#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name("�д�����",({"bu-tie neck","neck"}) );
        set("long",@LONG
�Ѥ@�ʹs�K���¦�]�l�Ҧꦨ������A�㦳���R�H�ߪ��\�ΡC
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",200);          
                set("volume", 3);                       
                set("material", "wood");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}


