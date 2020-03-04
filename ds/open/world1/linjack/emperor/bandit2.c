#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","�a�D��");
 set("long",@LONG
�A�Ө�F�o�Ӧa�D���̭�, ��A�@�L�ӮɧA�N���D�Ʊ������F,
�A���e�観�\�h�����c�ٯ몺�j�s���b���ۥL�̪��y��..�ӧA��M
�N���F�L�̪��y���F!!(�p�G�L���٦b����). �|�P���@�Ǫo�Olamp
�i�H����(dough). ������G�N�O�o�Ӧa�D���Y�F.
LONG
);
 set("exits",([ "southeast":__DIR__"bandit1",
                "west":__DIR__"bandit3"]));
 //���B�n�[ mob.
 set("objects",([ __DIR__"npc/bandit3":2,
                  __DIR__"npc/bandit2":2,]));
 set("no_clean_up", 0);
 set("light",1);
 set("no_recall",1);
 setup();
}

void init()
{
  add_action("do_dough","dough");
}

int do_dough(string arg)
{
  object me;
  me=this_player();
  if(!arg || (arg != "�o�O" && arg != "lamp")) return notify_fail("�A�n��������?\n");
  if( query("doughed") ) return notify_fail("�o�O�w�g���F.\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("�A���b����!\n");
  message_vision(RED"$N�����F�o�O, �|�P�ܤ@������.\n"NOR,me);
  delete("light");
  set("doughed",1);
  set("long",@LONG
�A�Ө�F�o�Ӧa�D���_�I, ��A�@�L�ӮɧA�N���D�Ʊ������F,
�A���e�観�\�h�����c�ٯ몺�j�s���b���ۥL�̪��y��..�ӧA��M
�N���F�L�̪��y���F!!(�p�G�L���٦b����). �|�P���@�Ǥw�g�L�k
�I�۪��o�O.
LONG);
  return 1;
}
