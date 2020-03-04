#include <room.h>
inherit ROOM;

void create()
{
  set("short","���}");
  set("long",@LONG
�o�̬O���ۥC�������W�i�h���ѵM���}�A�P�D���a�W���G�ۤ���
�W�����e�A���}���䦳�@�����������ݰ_�Ӹ����䪺�������b�A�S��
�������~�a������A�����W���������t�n���������{�ʡC
LONG);
  set("exits",([ 
      "south":__DIR__"room54",
      "southeast":__DIR__"room55",
      "southwest":__DIR__"room53",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("light","0");
  set("king-room",1);
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
      __DIR__"npc/apeman-king":1,
     ]) );
  setup();
}            

void init()
{
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object me,claw;
  me=this_player();
  if(!arg || arg!="����") return 0;
  if(!objectp(claw=present("climb claw",me) ) )
    return notify_fail("�A�ʥF�X�A���u��A�L�k�k�n�����C\n");
  if ( (me->query("class1") == "thief") && (me->query_skill("hide") > 60) )
  {
    message_vision("$N��������A�L�n�L���a���W���������F�C\n",me);
    me->set_temp("hide",1);
    me->move(__DIR__"room57");
    tell_room(environment(me),"��������G���I���R�C\n",me );
    return 1;
  }
  message_vision("$N��}�åΡA�p�߽w�C�a���W���������F�C\n",me);
  me->move(__DIR__"room57");
  tell_room(environment(me),me->query("name")+"�w�w�a�q�����U���W�ӤF�C\n",me );
  return 1; 
}
