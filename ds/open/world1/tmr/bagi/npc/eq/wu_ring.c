#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name("������",({"storm ring","ring"}) );
        set("long",@LONG
�@�T�a���Ŧ������٫��A�N�_�Ӧ��ѲM�D���Pı�C
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�u");       
                set("value",1200);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("limit_con",20);
        set("limit_int",30);
        set("armor_prop/armor",3);       
        set("armor_prop/int",3);
        setup();
}

