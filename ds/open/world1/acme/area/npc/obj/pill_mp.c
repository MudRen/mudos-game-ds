#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIW "�b�ߤ�" NOR , ({ "mp pill", "pill" }));
        set("long","������H�����F����b�ơA�W�j�]�O�C\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "mp" : 500,
         ]));
        set("value", 500);
        setup();
}
