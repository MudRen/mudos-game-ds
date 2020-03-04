#include <room.h>
inherit ROOM;

void create()
{
  set("short","�X���s��");
  set("long",@LONG
�o�̬O�X���s���s���A�|�B�����b��A�G�������ճ��A�j�l���N
�����a�����¶�b���ۤ����A�A�`�N�즳�����������n���Q����F��
�i�L�����A��o������ơA���Ǧa�誺���۹��O�Q�G�k�L�C
LONG);
  set("exits",([ 
      "west":__DIR__"room113",
      "southeast":__DIR__"room116",
      "south":__DIR__"room115",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set_temp("ready_rb",4);
  set("no_horse_member",1);
  set("outdoors","snow");
  setup();
}            

void reset()
{
  object orochi,b;
  if( this_object()->query_temp("ready_rb") > 3)
  {
    orochi=find_living("_NPC_RED_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-red-head");
      b->move(__DIR__"room110");
    }
    orochi=find_living("_NPC_GOLD_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-gold-head");
      b->move(__DIR__"room111");
    }
    orochi=find_living("_NPC_GREEN_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-green-head");
      b->move(__DIR__"room112");
    }
    orochi=find_living("_NPC_BLUE_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-blue-head");
      b->move(__DIR__"room113");
    }
    orochi=find_living("_NPC_PURPLE_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-purple-head");
      b->move(__DIR__"room114");
    }
    orochi=find_living("_NPC_GREY_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-grey-head");
      b->move(__DIR__"room115");
    }
    orochi=find_living("_NPC_WHITE_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-white-head");
      b->move(__DIR__"room116");
    }
    orochi=find_living("_NPC_BLACK_HEAD_");
    if( objectp(orochi) )
    {
      if( !environment(orochi) )  destruct(orochi);
    }
    else
    {
      b=new(__DIR__"npc/orochi-black-head");
      b->move(__DIR__"room117");
    }
    set_temp("ready_rb",0);
  }
  else set_temp("ready_rb",this_object()->query_temp("ready_rb")+1);
  ::reset();
}
