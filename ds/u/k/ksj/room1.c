#include <room.h>
inherit ROOM;

void create()
{
  set("short","ksj ���񪪳�");
  set("long",@LONG
�@���C�񪺤j���A�A�X��i�ʪ��C
LONG
);
  set("exits",([ 
      "south": __DIR__"room4.c",
      "east": __DIR__"room2.c",
     ]));
  set("light",1);
  setup();
}
