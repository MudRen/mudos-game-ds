#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIY"�F��"HIW"����"NOR,({"Dreamcast neck","neck"}) );
        set("long",@LONG
�o�O�@���a���F��������A�ڻ������i��ĳ���\�ġE
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",200);          
                set("volume", 3);                       
                set("material", "wood");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}

