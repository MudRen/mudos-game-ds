#include <room.h>
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
�o�̬O���˸޲����˪L�A�ѩ󰭩Ǫ��Ϯ��ϱo���𾮭��A���~�@
���E�������A���b�o��Pı�����D�D���A���ɦ��_�Ǫ��s�n�q�˪L��
�ǨӡA���ת����ϱo�|�P�R���@�ѻG�䪺���D�A��U���@��G�סA
�G�פW���F�@�ǿ����C
LONG);
  set("exits",([ 
      "east":__DIR__"room50",
      "west":__DIR__"room48",
      "south":__DIR__"room44",
      "north":__DIR__"room54",
     ]));
  set("item_desc",([
      "�G��" : "�@�藍��o�O����ʪ����G�סA���o�j�P���ͯ���A�G�פW���F�@�ʦתۡC\n",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
     ]) );
  setup();
}            

void init()
{
  add_action("do_pick","pick");
}

int do_pick(string arg)
{
  object me=this_player(),fungus;
  fungus = new(__DIR__"npc/eq/carrion-fungus.c");
  if(query_temp("fungus1")) return notify_fail("�o�ʦת��٨S�����O�C\n");
  if(arg !="�ת�" )
    return notify_fail("�A�n�䤰��F��r�H\n");
  else
  {
    message_vision("$N�����l�q�G�פW�K�U�@�ʦתۡC\n",me);
    fungus->move(me);
  } 
  set_temp("fungus1",1);
  call_out("delay",600,this_object());
  return 1;
}

void delay(object room)
{
  delete_temp("fungus1");
}
