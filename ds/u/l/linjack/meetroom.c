#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIB"古劍亭"NOR);
 set("long",@LONG
你一陣暈眩, 就來到了這個傳說中的古劍亭, 裡面掛滿了天下名劍,
若是在豔陽高照的時刻, 此地便金光閃閃, 若從低處仰望, 便會覺得此
處散發著一道神聖無比的淡金光芒, 而凡人又不可能攀爬至此, 當然會
將此地傳說為一處仙境. 若是平時, 則光芒會褪去五分, 不過能到古劍
亭的人反而覺得四處的鐵銀反光, 散發淡淡邪氣.
LONG
    );
 set("exits",([
               "wiz":"/d/wiz/hall1",]));
 set("light",1);
 set("objects",([
		__DIR__"area/test/npc/shura":1,
 ]));
 set("valid_startroom", 1);
 setup();
 call_other("/u/l/linjack/linjack_b","???");
}
int valid_leave(object me, string dir)
{
 if( dir=="west" && !wizardp(me) )
  return notify_fail("那裡只有巫師才能進去。\n");
 return ::valid_leave(me, dir);
}
