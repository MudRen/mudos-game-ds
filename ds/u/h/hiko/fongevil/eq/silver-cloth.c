#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(WHT"�ȼ�����"NOR ,({ "silver-li cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
�o�O�ѻ�������´�����@��A���ӤW�h�|�Ϯg�X�[���⪺����C
LONG
     );
        set("unit", "��");
        set("value",5000);
        set("material", "steel");
        set("armor_prop/shield",15);
        set("armor_prop/con",2);
        set("armor_prop/armor",18);        
        set("armor_prop/dex",3);          
           }
        setup();
}




