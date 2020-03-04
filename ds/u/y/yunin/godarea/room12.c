#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", HIW"謎之屋"NOR);
    set("long", @LONG
一切都是謎，沒有所謂的是與非，對與錯。在你的右手邊有個發
光的石頭，[0;1;36m�[1m�[1m�[1m@[1m�[1mU[1m([1ml[1mo[1mo[1mk[1m)[0m說不定會有出乎預料的事情發生。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  
  "發光的石頭" : "[0;1;37m�[1mo[1m�[1mO[1m�[1md[1m�[1m�[1m�[1mw[1m�[1m[[1m�[1m�[1m�[1m�[1m�[1mY[1m�[1mA[1m�[1m@[1m�[1mH[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mA[1m�[1mp[1m�[1mG[1m�[1mA[1m�[1m�[1m�[1mN[1m�[1m�[1m�[1m�[1m([1mt[1mo[1mu[1mc[1mh[1m)[1m�[1m�[1m�[1m�[1m�[1mw[1m�[1m|[1m�[1mo[1m�[1m�[1m�[1m@[1m�[1m�[1m�[1m_[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mC[0m ",
]));
        set("world", "past");
                set("exits", ([ /* sizeof() == 1 */
  "out" : "/u/y/yunin/godarea/room5",
]));  
   set("no_clean_up", 0);

        setup();
}      
void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="發光的石頭" ) return 0;
        message_vision(HIR"你摸了這個奇怪的石頭，忽然飛上了天。 \n"NOR,me);
        me->move(__DIR__"room13");
          tell_room(environment(me),me->query("name")+HIR"忽然飛上了天。\n"NOR,me );
return 1;
}

