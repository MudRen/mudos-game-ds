#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("記憶卡Ａ",({"memory card","card","_QUEST_ITEM_SLOVAKIA_1_" }) );
    set("long",@LONG
這是一片遊戲機常用到的記憶卡。
LONG
        );
        if(!clonep() )
        {
                set("value",0);
                set("unit","片");
        }
        setup();
}

