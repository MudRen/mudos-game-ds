#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIY"未來區域、獎懲會議廳"NOR);
  set("long",@LONG
這個十分廣大而華麗的會議廳，就是由負責未來世界
的wiz開會的地方，由於是未來的關係，所以設備相
當的先進，令人嘆為觀止。
LONG
  );
  set("exits",([
  "wiz":"/d/wiz/hall1",]));
  set("light",1);
  set("objects",([
  ]));
  setup();
call_other("/obj/board/future_b","???");
}

