#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIY"��ù����"NOR,({"shu-lou gold mask","mask","gold mask"}) );
        set("long",@LONG
�֦���ù���㭱������A���H�ݤF���H�ӷX�C
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "��");       
                set("value",2000);          
                set("volume", 2);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/int",2);
        setup();
}


