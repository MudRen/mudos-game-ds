inherit ROOM;
void create()
{
  set("short", "ＥＱ & ＷＰ倉儲庫");
  set("long", @LONG

這裡是用來存放一些特定 EQ & WP 的地方，因為尚未開始
使用以及整修，而顯得破破爛爛的。

LONG
);
  set("exits", ([
  "up" : "/open/world1/tmr/area/hotel",
  ]) );
  set("hide_exits", ([ 
      "down" : "/open/world1/cominging/guitar.c",
      "east" : "/open/world1/kkeenn/classroom",
                     ]));
  set("no_clean_up", 0);
  set("objects",([
     "/open/check_man":1,
     "/open/world1/moonhide/pool/npc/obj/machine":1,
]));
  set("light",1);
  set("no_fight",1);
  setup();
  replace_program(ROOM);
}

