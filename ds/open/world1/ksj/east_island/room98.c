#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�s���@���T�򪺤s���A���W���O�H�ۤl�B�d�کM����A�n
�䪺�s����F�@�Ǹ��۸�H�B�C
LONG);
  set("exits",([ 
      "east":__DIR__"room97",
      "west":__DIR__"room99",
      "south":__DIR__"room100",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/berserk-huge-pig":1,
     ]) );
  setup();
}            
