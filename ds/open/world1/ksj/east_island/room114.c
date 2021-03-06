#include <room.h>
inherit ROOM;

void create()
{
  set("short","出雲山頂");
  set("long",@LONG
這裡是出雲山的山頂，四處岩石嶙嶇，佈滿斑斑白雪，強勁的冷
風挾帶雪花旋繞在岩石之間，你注意到有部份的岩壁好像被什麼東西
磨過似的，顯得比較光滑，有些地方的岩石像是被腐蝕過。
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
