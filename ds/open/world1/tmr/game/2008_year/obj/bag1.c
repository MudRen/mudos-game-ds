#include <ansi.h>
inherit ITEM;
inherit __DIR__"bag_base";

void create()
{
        set_name(HIR "小福袋" NOR,({"small happiness bag", "bag", "__MOUSE_BAG__"}) );
        set("long",@LONG
這是一個喜氣洋洋的福袋，上面畫有一隻可惜的黃金鼠圖樣，用來慶祝
２００８年鼠年活動，可說是開春搶福袋 福氣處處在，你可以打開(open)
福袋，看看你能獲得什麼好東西。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
        }
        set("value", 100);
        //福份
        set("happiness", 1);
	    setup();
}


