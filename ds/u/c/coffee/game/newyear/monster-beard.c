#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"�~�~Ž"NOR, ({ "monster-beard","beard" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�~�~���GŽ�A�Q�������ʡC\n");
                set("unit", "��");
                set("value", 0);  
                set("no_put", 1);  
        }
       setup();
}
