#include <ansi.h>
inherit ITEM;

#define BOSS "/open/world1/tmr/crush_bone/npc/nightbane.c"


void create()
{
    set_name(HIY"碎骨帝印"NOR, ({"emperor stamp", "stamp","_EMPEROR_STAMP_"}));
    if( !clonep() ) {
        set("long", @LONG
這是一顆像獸骨刻成的帝印，上頭用不知名的字體寫著兩字，
你猜測應該是「碎骨」之類的字號。
LONG
                );
        set("value", 100);
        set("unit", "個");
        set("weight", 10);
        set("value",10);
        } else
                   set_default_object(__FILE__);
    setup();
}

