#include <path.h>

inherit ROOM;

void create()
{
        set("short", "溪邊小路");
        set("long", @LONG
一條沿著小溪的道路，水流潺潺，不時可看到肥美的魚兒在交頭接耳
，還有十來個小孩子在溪裡戲水玩耍，道路兩旁的房舍皆是一些用木材所
造的平房，往東北走去就是此是「鬼斷森林」了。
LONG
        );
        set("world", "past");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/sign" : 1,
]));
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
   "northeast":TMR_PAST"ghost-forest/forest1",
  "west" : __DIR__"street3",
    
]));
        set("no_clean_up", 0);

        setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
  ::valid_leave();
  if( dir=="northeast" && !userp(me))
  return notify_fail("那裡只有玩家才能進去。\n");
  return ::valid_leave(me, dir);
}

