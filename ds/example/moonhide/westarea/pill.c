#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW"�E���٦X��"NOR, ({ "nine around pill","pill" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�O�E�ѥȤk���ѤU����ءA�ƭP�Ӧ��C\n");
                set("unit","��");
                    set("value",4000);      
                    set("heal_hp",1000);           
                    set("food_remaining",1);
        }
     setup();
}

