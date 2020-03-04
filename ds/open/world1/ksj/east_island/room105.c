#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s�y");
  set("long",@LONG
�Ө�o�̷ū׺������C�A���]�ܭ��F�A����N�N�a�Pı�ܤ���
�A�A�s���W�����@���ϰ쵲���@���B���A�V�H�]�\������(break)�C
LONG);
  set("exits",([ 
      "south":__DIR__"room107",
      "northwest":__DIR__"room104",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/four-head-snake":1,
     ]) );
  setup();
}            

void init()
{
  add_action("break_wall","break");
}

int break_wall(string str)
{
  if(this_object()->query_temp("opened") != 0) return 0;
        
  if(str=="�B��")
  {
    object me;
    me=this_player();
    if(me->query_str()<40 )
    {
      message_vision(HIR"\n$N�@�����V�B���A--�n-- �@�n�T�A�B�������L�l�C\n"NOR,me);
      return 1;
    }
    message_vision(
      HIW"\n$N�@�����V�B���A--��-- �@�n�T�A�B���H���S�X�@�Ӭ}�f�C\n"NOR,me);
    set("long", @LONG
�Ө�o�̷ū׺������C�A���]�ܭ��F�A����N�N�a�Pı�ܤ���
�A�A�s���W���@�Ӥs�}�A�������_�z�X�H��C
LONG
    );

    set("exits",([ 
        "south":__DIR__"room107",
        "northwest":__DIR__"room104",
        "enter":__DIR__"room106",
       ]));
       
    set_temp("opened",1);
    return 1;
  }
}

void reset()
{
  set("long", @LONG
�Ө�o�̷ū׺������C�A���]�ܭ��F�A����N�N�a�Pı�ܤ���
�A�A�s���W�����@���ϰ쵲���@���B���A�V�H�]�\������(break)�C
LONG
  );
  set("exits",([ 
      "south":__DIR__"room107",
      "northwest":__DIR__"room104",
     ]));
  delete_temp("opened");
  ::reset();
}
