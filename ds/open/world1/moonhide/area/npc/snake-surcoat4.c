#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name(HBK"�j�e�ܤѦa"NOR,({ "tan-di surcoat","surcoat" }) );
        set("long","�ʦ~�j�D �j�a �������W��֡A���ѲH�H�������A�a���A���F�W�����ǡC\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "��" );
        set("value",15000);
        }  
        set("armor_prop/armor", 13); 
        set("armor_prop/bio",-1);
        set("armor_prop/sou", 1);
        set("armor_prop/str",-1);
        set("armor_prop/dodge",20);        
        setup();
}

