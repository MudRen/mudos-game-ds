inherit ROOM;
void create()
{
  set("short", "�Ӣ� & ��ޭ��x�w");
  set("long", @LONG

�o�̬O�ΨӦs��@�ǯS�w EQ & WP ���a��A�]���|���}�l
�ϥΥH�ξ�סA����o�}�}���ꪺ�C

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

