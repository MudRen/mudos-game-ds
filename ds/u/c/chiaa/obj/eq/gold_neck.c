//u/c/chiaa/obj/eq/gold_neck.c

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIY"������"NOR,({"gold_neck","neck"}) );
        set("long","�@���ª����y�Ӧ�������A�ݰ_�ӻ��Ȥ����C\n");    
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set_weight(10);        
                set("value",5000);          
                set("armor_prop/armor",3);  //���m3   
                set("material", "gold");    //���� ��   
        }
        
       setup();
}
