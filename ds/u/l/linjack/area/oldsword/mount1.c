#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","山崖邊");
 set("long",@LONG
你來到了這峭壁的最頂端了, 你往四周看一看, 似乎附近還有一
些平台地可以讓一些人站在這邊. 這裡冷風颼颼, 你不禁打了個寒噤,
若往東邊望去, 真是一處看日出日落的好地點! 雲海籠罩你的下方,
而你的視野則無限寬廣, 令人心曠神怡. 不過小心別摔下去了, 下去
可就沒得救了! 你往西邊看, 有一座不大不小的古亭, 正發出耀眼的
銀白光線, 應該就是傳說中的古劍亭了!
你發覺東邊的山壁下好像不太對勁. 不過你應該爬不下去..
LONG
    );
 set("exits",([
               "west":__DIR__"oldsword",
               "southdown":__DIR__"mount2",
               "eastdown":__DIR__"secret1",]));
 set("no_clean_up", 0);
 setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="eastdown" && !(me->query_temp("hall",1)) )
  return notify_fail("你想跳下去? 發神經啊?\n");
 else if( dir=="eastdown" && me->query_temp("hall",1) )
  write(HIW"\n你小心翼翼的縱身而下 ...\n\n"NOR);
 return ::valid_leave(me, dir);
}


