#include <room.h>
inherit ROOM;
int i=0;

void create()
{
  set("short","�����");
  set("long",@LONG
���b�o�̬O�e����A����O�@�y�Z�j������A����i�H�ݨ�@�j
�������L�A�H�e�����檺�{�׬ݨӡA�S�����O���L�k��e���A�@��
����W���F�@�ʵ���ֲ֪��������C
LONG);
  set("exits",([ 
      "east":__DIR__"room61",
      "west":__DIR__"room63",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("item_desc",([
      "�������" : "�@�赲��ֲ֪��������A�i�H�K�ǥR��(pick)�C\n",
     ]));
  set("objects",([
      __DIR__"npc/eq/wood-board":1,
     ]) );
  setup();
}            

void init()
{
  add_action("do_pick","pick");
}

int do_pick(string arg)
{
  object me=this_player(),grape;
  grape = new(__DIR__"npc/eq/agrestal-grape.c");
  if( query_temp("grape1") > 3 ) return notify_fail("������w�g�Q�K���F�A�ѤU���O�٨S�����C\n");
  if(arg !="������" )
    return notify_fail("�A�n�K����F��r�H\n");
  else
  {
    message_vision("$N�p�ߦa�K�U�@�곥����C\n",me);
    grape->move(me);
    set_temp("grape1",i++);
  } 
  call_out("delay",600,this_object());
  return 1;
}

void delay(object room)
{
  delete_temp("fungus1");
  i=0;
}

int valid_leave(object me, string dir)
{
  if( me->query("tengu") )
  {
    if( dir == "east")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
