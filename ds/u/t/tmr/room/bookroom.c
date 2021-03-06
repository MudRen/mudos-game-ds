// Room: /u/t/tmr/room/bookroom.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "小奇奇的書房");
        set("long", @LONG
一踏進此問房間，由滿室的名貴書、畫，你就覺得
此間主人定是個愛好風雅的清士，只聞窗外鳥聲啼啼，
一縷陽光映得滿室明亮，令人神清氣爽，眼前有張舒
適的床，你看了就想好好地躺在上面休息(rest)。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
	  "north" : (: look_door,     "north" :),
	]));

        set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"t1.c",
	]));

       create_door("north", "木門", "south", DOOR_CLOSED);
        set("objects", ([ /* sizeof() == 1 */
	  __DIR__"npc/dragon" : 1,
	]));
        
	set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_rest","rest");
}
int do_rest()
{
  object me;
  me=this_player();
  tell_object(me, HIW "你伸長了懶腰，「哇~~~~啊~~~~~」的大大地打了一個哈欠.\n\n\n" NOR );
  tell_object(me, HIW "眼睛一閉，隨即就在香軟錦美的水床睡著了.....\n\n" NOR );
  tell_object(me, HIB "zzzZZZZzzz......\n\n\n" NOR );
  tell_object(me, HIB "【十秒經過】......\n" NOR );
  tell_object(me, HIW "你睜開了眼睛，嗯，精神回復了，再來打拚了...\n" NOR );
  return 1;
}
