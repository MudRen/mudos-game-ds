#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIG"�~��"NOR);
  set("long", @LONG
�o�̬O�@��L�ڪ��j��쪺��_��A�o�̪��a�ո����A��_��O
�@�����j���ƥ۾�L�A�۪L�ʧ��K���A�[�W�P�򩥾��~��U�Ӫ�����
�ϱo�i�J�۪L�����|�Q���_�A�γ\�i�H�λ��\���L�h�C
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "southwest" : __DIR__"room26",
      "southeast" : __DIR__"room24",
      "northeast" : __DIR__"room30",
     ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  set("no_auc", 1);
  set("item_desc", ([
      "�۪L" : "�����ƤV���@�������A�~�k����ơC\n",
     ]));
  setup();
}

void init()
{
  add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg!="�۪L" ) return 0;
  if(me->query_skill("dodge",2) <60)
  {
    message_vision("$N��������O�����A���_��K���F�U�ӡC\n",me);
    return 1;        
  }
  message_vision(HIW"$N����@�D�ӤW�A�����s�I�A�a���W�F�۪L�C\n"NOR,me);
  me->move(__DIR__"room33");
  tell_room(environment(me),me->query("name")+"�I�i�¼������k�A�q�۪L�U���F�W�ӡC\n",me );
  return 1;
}
