#include <ansi2.h>
#include <room.h>
#include <path.h>
inherit ROOM;

void open_war();
void end_war();

string *place=({"room64","room65","room66","room67",
        "room68","room69","room70","room71","room72",
        "room73","room74","room75","room76","room77",
        "room78","room79","room80"});
int query_tengu();

void create()
{
  set("short",HIM"���L"NOR);
  set("long",@LONG
�o�̬O���L�����L�|�A�|�P���O�j�j�p�p������A�b�v���R
������H�۷L�������n�\�A�M�ӥX�����⪺�ѪšC
LONG);
  set("exits",([ 
      "east":__DIR__"room62",
      "west":__DIR__"room69",
      "southwest":__DIR__"room73",
      "northwest":__DIR__"room64",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/karasu-tengu":3,
     ]));
  setup();
}            

void init()
{
  ::init();

  if( this_player()->query_temp("hide") > 0 ) return;
  if( this_player()->query_temp("invis") > 0 ) return;
  call_out("open_war",1);
}

void open_war()
{
  int i;
  object ob,ob1,ob2,ob3,ob4,ob5,ob6;
  ob=find_living("_NPC_BLACK_TENGU_");

  if( userp(this_player()) && objectp(ob) && query_tengu()==0 
      && !this_object()->query_temp("war_clear") )
  {
    message_vision(HIR"$N���p��Ĳ�ʾ����A�@�}�}��P���a�n�T�M���L�I\n"NOR,this_player());
    message("world:world1:vision",
    HIY"\n        "+this_player()->query("name") +HIW "Ĳ�ʤF���L�������A�y�ɤj�s�Ѫ��s��ӥX.......\n\n"
    HBK"        �¤Ѫ�"HIR"��۹D�G�ڤ��ʧA�̡A�A�̤ϭ˨ӷS�ڰաA�����@�a�I�I\n\n\n"NOR,users());

    ob1=new(__DIR__"npc/red-tengu");
    ob1->move(__DIR__"room64");
    ob2=new(__DIR__"npc/blue-tengu");
    ob2->move(__DIR__"room69");
    ob3=new(__DIR__"npc/white-tengu");
    ob3->move(__DIR__"room78");

    for(i=0;i<=7;i++)
    {
      ob4=new(__DIR__"npc/tengu");
      ob4->move(__DIR__+place[random(sizeof(place))] );
    }
    for(i=0;i<=5;i++)
    {
      ob5=new(__DIR__"npc/small-tengu");
      ob5->move(__DIR__+place[random(sizeof(place))] );
    }
    for(i=0;i<=4;i++)
    {
      ob6=new(__DIR__"npc/big-tengu");
      ob6->move(__DIR__+place[random(sizeof(place))] );
    }

    call_out("end_war",180);
    return;
  }
  return;
}

void end_war()
{
  object tengu;

  if( query_tengu() )
    call_out("end_war",30);
  else
  {
    message("world:world1:vision",
    HIY"\n\n                ���L�����n�����A���Ѫ��t�˦Ӱk�F..\n\n"NOR
    ,users() );
    set_temp("war_clear",1);
    call_out("delay",600);
  }       
  return;
}

void delay()
{
  delete_temp("war_clear");
}

int query_tengu()
{
  object tengu;

  while( objectp(tengu=find_living("tengu-war-tengu")) )
  {
    if( !environment(tengu) )
    {
      destruct(tengu);
      tengu = 0;
    }
    else break;
  }

  if( objectp(tengu) ) return 1;
  else return 0;
}

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("tengu", this_object())) && !me->query("tengu") && !random(3))
  {
    message_vision("$n���צb$N�����e���D�G���A�d�U�R�ӧa�C\n",me , guard);
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}        
