#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("記憶卡Ｂ",({"memory card","card","_QUEST_ITEM_SLOVAKIA_2_" }) );
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

