#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"洞穴"NOR);
 set("long",@LONG
這個洞穴從四周的石壁上源源不絕的向外冒出不屬於這
個世界的寒氣，其嚴寒的程度讓你舉步艱難，還是趕快從這
裡出去吧....
LONG
    );
 set("exits",([  "out":__DIR__"ten52",
    ]));
 set("objects", ([__DIR__"obj/cold_stone" : 1,
    ]));
set("no_clean_up",0);set("item_desc",([
       "岩壁":HIW"四周的岩壁寒冷的讓你害怕，而岩壁上有一個奇怪的突起物....?\n"NOR,
       "突起物":HIW"看起來似乎是一個被凍結在岩壁上的鋼環....是做什麼用的呢?\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten54");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要膜拜什麼?\n");
        if( a!="鋼環" )
                return notify_fail("有這種東西嗎?\n");
      if (me->query("level") > 27)
     {
        message_vision(HIW"$N誠心的跪下膜拜鋼環, 忽然一陣煙霧飄過, $N失去了蹤影! \n"NOR,me);
          me->move(where1);
        return 1;
     }
     else 
     {
        message_vision(HIW"$N誠心的跪下膜拜鋼環，但鋼環的奇寒幾乎將$N凍死!! \n"NOR,me);
        return 1;
     }

}


