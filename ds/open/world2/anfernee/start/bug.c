inherit ROOM;

void create()
{
        set("short", "臭蟲回報區");
        set("long", @LONG
為了增進本Mud的功能，當然需要各位玩家的幫忙以及協助，回報Bug
可以讓夢幻七域更加的完善，也可以讓各位玩得更盡興，當然，回報Bug
將會視情況有所獎賞。
LONG
        );

        set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/wiz/entrance", 
  "enter" : "/open/world1/tmr/area/hotel",        ]) );
 set("hide_exits", ([ "north" : __DIR__"award" ]));
        set("objects", ([
        __DIR__"npc/banker" : 1,
        ]) );
        set("light",1);
set("no_recall",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("no_kill",1);
        setup();
        call_other( "/obj/board/bug_b", "???" );
}



