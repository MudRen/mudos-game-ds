#include <room.h>
inherit ROOM;

void create()
{
  set("short","ksj ���u�@��");
  set("long",@LONG
�@���U�����u�@�ǡA�|�P������W�����F�g��u��Τ��������A
�𨤩�ۤ@�x�F���@�T�A�_�ۻ]�𪺤����W�����A�e������W���j��
�O�W�g���F�]�p�ϼˤέp�⦡�C
LONG
);
  set("exits",([
      "east":__DIR__"room1.c",
      "north":__DIR__"temp-room.c",
      "east_island":__DIR__"east_island/room1.c",
      "lost_island":"/open/world1/ksj/lost_island/room1.c",
      "cyaneous":__DIR__"cyaneous/room1.c",
     ]));
  set("light",1);
  set("objects",([
      __DIR__"robot.c":1,
     ]) );
  setup(); 
  load_object("/obj/board/ksj_b");
}
