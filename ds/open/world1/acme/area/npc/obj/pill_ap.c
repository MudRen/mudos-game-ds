#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIW "���द" NOR , ({ "ap pill", "pill" }));
        set("long","��_���ˡA�W�j���l�����ġC\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "ap" : 500,
         ]));
        set("value", 500);
        setup();
}
