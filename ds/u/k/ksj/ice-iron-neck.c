#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIC"�H�K�V��"HIR"(S)"NOR,({"ice-iron neck","neck"}) );
        set("long",@LONG
�H�K��s���V���A�~�[�s���T�s���񪺫��A�A�����V���۷�n�����@�C
LONG);
        set_weight(700); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2000);          
                set("volume", 2);                       
                set("material", "steel");

        }
        set("armor_prop/armor",5);       
        setup();
}

int query_autoload() { return 1; }
