#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"���"HIW"�P��"NOR ,({ "buddha cloth","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
�o�O�ǻ������{�����諸�P��,�P�Ƭݰ_�Ӫ����{�{,��_�ӧA���k�O�|�[���\�h.
LONG
     );
        set("unit", "��");
        set("value",0);
        set("material", "steel");
        set("limit_con",30);
        set("limit_lv",20);
}
        set("armor_prop/armor",14);
        set("armor_prop/con",2);
        set("armor_prop/wit",1);      
       
        
        setup();
}


