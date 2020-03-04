#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
�o�̬O���Z�j���Ŭu����A��Ӿ���ϥΤ�O�f�ءA���䦳���d
�x�A�j�D�����O�����˪��Ŭu�A�������h�����ˤ�h�D�`���ġC
LONG);
  set("exits",([ 
      "east":__DIR__"room12",
      "enter":__DIR__"bathroom",
     ]));
  set("light", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up",0);
  set("valid_startroom", 1);
  set("map","hotel");
  set("objects",([
      __DIR__"npc/bath-lady":1,
     ]) );
  setup();
}      

int valid_leave(object me, string dir)
{
  if( dir!="enter" )return ::valid_leave(me, dir);
  if( dir=="enter" && me->query_temp("bathe") <=0 || !me->query_temp("bathe") )
    return notify_fail("�A�٨S�I�w�����O�ΩO�I\n");
  return ::valid_leave(me, dir);
}
