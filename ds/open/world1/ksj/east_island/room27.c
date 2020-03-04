#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","��a");
  set("long",@LONG
�o�̬O�A�ЮǪ��@���j��a�A��a�W�����Z���ν����C��A�O��
���Ψө񪪬��b���a��A��a�W���@�ǧ|�}�A���O�����ɦ���B���n
���C
LONG);
  set("exits",([ 
      "east":__DIR__"room22",
      "south":__DIR__"room26",
      "north":__DIR__"room28",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("item_desc",([
      "���O" : "�@�O�θy�����O�A���ɶǨ���B���n���C\n",
     ]));
  set("objects",([
      __DIR__"npc/spot-snake":2,
     ]) );
  setup();
}            

void init()
{
  add_action("do_search","search");
}

int do_search(string arg)
{
  object me=this_player(),snake;
  snake = new(__DIR__"npc/golden-snake.c");
  if(query_temp("snake1")) return notify_fail("�A�F½���A�@�L����C\n");
  if(arg !="���O" )
    return notify_fail("�A�n�䤰��F��r�H\n");
  else
  {
    message_vision(HIY"$N�����O�F½½��½½�A��M�\\�h�D�v�g«�ӥX�I\n\n"NOR,me);
    new(__DIR__"npc/golden-snake.c")->move(environment(me));
    new(__DIR__"npc/snake1.c")->move(environment(me));
    new(__DIR__"npc/snake1.c")->move(environment(me));
    new(__DIR__"npc/snake2.c")->move(environment(me));
    new(__DIR__"npc/snake2.c")->move(environment(me));
    new(__DIR__"npc/snake3.c")->move(environment(me));
    new(__DIR__"npc/snake3.c")->move(environment(me));
    new(__DIR__"npc/snake4.c")->move(environment(me));
    new(__DIR__"npc/snake4.c")->move(environment(me));
    new(__DIR__"npc/snake5.c")->move(environment(me));
  } 
  set_temp("snake1",1);
  call_out("delay",900,this_object());
  return 1;
}

void delay(object room)
{
  delete_temp("snake1");
}
