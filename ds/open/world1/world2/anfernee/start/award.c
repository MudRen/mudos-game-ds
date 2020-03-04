#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "巫師獎賞紀錄區");
        set("long", @LONG
這裡是只有巫師才可進入的獎賞紀錄區，在巫師解決臭蟲之後，將可
到此公告所要 award  的對象及點數，請諸位巫師在獎賞之後請註明已獎
賞，謝謝。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
 "south" : __DIR__"bug",
]) );
        set("light",1);
        set("no_clean_up", 0);
        setup();
        call_other( "/obj/board/award_b", "???" );
}

void init()
{
 if( !wizardp(this_player()) )
 {
  write(HIR" 這裡不是玩家可進入的地方 !!! 瑪亞系統自動退出玩家 !!! "NOR);
  this_player()->move(__DIR__"bug");
 }
}
