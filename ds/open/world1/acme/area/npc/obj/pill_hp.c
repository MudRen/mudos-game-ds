#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIW "�ٻ" NOR , ({ "hp pill", "pill" }));
        set("long","�@����_���^�ͪ����ġC\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "hp" : 1000,
         ]));
        set("value", 500);
        setup();
}
