//u/c/chiaa/obj/eq/crystal_neck.c

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIC"��������"NOR,({"crystal_neck","neck"}) );
        set("long","�@���Τ����s�@�Ӧ�������A�ݰ_�Ӵ�����z�C\n");    
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set_weight(5);        
                set("value",6000);          
                set("armor_prop/armor",3);  //���m5 
                set("material", "crystal");    //���� ����  
        }
        
       setup();
}
