#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "���ߤ�" NOR , ({ "red heart pill", "pill" }));
        set("long","�o�O�@���~����������ġA�O���֨����F���A�����_�A\n"
                   "����O�M���O�C\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "hp" : 30,
         "ap" : 70,
         ]));
        set("value", 500);
        setup();
}
