#include <ansi.h>
inherit ROOM;
string look_string();
void create()
{
  set ("short", HIG"封印塔林"NOR);
  set ("long", @LONG
你一走到這裡，看到了壯觀非凡的景象，到處可見大小不一
的天然塔林，景象之壯觀讓你不禁感嘆大自然的奧妙，傳說中這
裡有極不可思議的事情，勾起了你冒險的精神，內心的滿腔熱血
已經開始沸騰起來，你躍躍欲試，想要破除這個陰森森的謎題。
LONG
);
        set("light",1);
        set("no_clean_up", 0);
        set("outdoors","land");
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"fu_11",
  "southwest" : __DIR__"fu_3",
  "west" : __DIR__"fu_3_1",
  ]));
        setup();
}
