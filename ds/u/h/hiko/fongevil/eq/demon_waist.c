#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("���ֶ��a",({"demon waist","waist"}) );
        set("long",@LONG
�Χ��Ǫ��֩һs�������a�A�Pı�Q���@�ΡA�B�a�۱j�j����C
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",25);
                set("limit_int",20);
                set("unit", "��");       
                set("value",5600);          
                set("volume", 3);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/str",2);
        set("armor_prop/dex",1);
  setup();
}

