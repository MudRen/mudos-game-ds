#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "天雲居");
        set("long", @LONG
這裡只有一座雕像。
LONG
        );
        
       set("exits", ([ /* sizeof() == 1 */
 "west" : "/d/wiz/entrance",
        ]) );

  set("light", 1);

  setup();
}

void init()
{

 if( !wizardp(this_player()) )
 {
  write(HIR" 這裡不是玩家可進入的地方 !!! 瑪亞系統自動退出玩家 !!! "NOR);
  this_player()->move(__DIR__"bug");
 }
}
