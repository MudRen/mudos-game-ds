#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"�ѥP�B����"NOR ,({ "Dreamcast cloth","cloth" }) );

        set("long",@LONG
�o���A�O�ǻ����ѥP�b�B�s�����X�P�B�������E
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_level",25);
                set("unit", "��");       
                set("value",1200);          
                set("volume", 2);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",40);
        set("armor_prop/show_damage",1);
        set("armor_prop/dex",1);
        set("armor_prop/int",2);
        setup();
}

