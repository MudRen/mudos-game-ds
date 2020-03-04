#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�s���@���T�򪺤s���A���W���O�H�ۤl�B�d�کM����A��
��O�@�B�~�{�A�ƤU�h�i�H�^��s�}�U�C
LONG);
  set("exits",([ 
      "northeast":__DIR__"room90",
      "westdown":__DIR__"room59",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_1") )
  {
    if( dir == "westdown")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
