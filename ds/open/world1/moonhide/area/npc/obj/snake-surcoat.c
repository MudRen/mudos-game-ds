#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name(HIW"�j�e�ܤ�"NOR,({ "hua-tai surcoat","surcoat" }) );
        set("long","�ʦ~�j�D  �j��  ����֡A�㦳���װj�ײv�P���ˤO�C\n");
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
        set("armor_prop/bar",1);
// 2003.4.11  �[ bar 1 �ҥH�� wit 1   by ksj
        set("armor_prop/wit",-1);
        set("armor_prop/con",-1);
        set("armor_prop/dodge",20);        
        setup();
}

