// Room: /d/wiz/hall1.c

inherit ROOM;

void create()
{
 set("short", "巫師交誼廳");
 set("long", @LONG

  這裡是巫師聊天討論的地方，如果巫師們要開會的話，也多半會選在這
裡舉行。往東是巫師會客室，是巫師接待玩家的地方。北邊是巫師們報告
工作計劃與工作進度的簡報室。從樓梯往上走可以到各類型的巫師討論區
，最頂樓的密室是DS高峰會議廳，門禁相當嚴格。這裡還有三個造型相異
的門，可以分別通到三大時代的工作討論廳。這裡有個佈告欄，張貼的都
是巫師們必須知道的重要通知與公告，一定要看完才可以離開喔。

LONG
        );
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "future" : "/open/world3/meetroom",
    "past"   : "/open/world1/meetroom",
    "now"    : "/open/world2/meetroom",
    "north"  : __DIR__"jobroom",
    "up"     : __DIR__"hall_area",
    "east"   : __DIR__"entrance",
//    "west"   : __DIR__"testroom",
    "down"   : __DIR__"meetroom",
  "game" : "/open/world1/wilfred/club/dragon/online",
 ]));
  set("objects",([
// __DIR__"npc/npc_wiz":1,
// "/obj/box":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/wizard_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("非玩家角色不能進入開放區域。\n");
        return ::valid_leave(me, dir);
}

