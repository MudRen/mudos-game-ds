#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","�����U");
  set("long", @LONG
�o�̬O�@�B���q���������U�A�|�P�O�U�������t�y�A���餣�ɩ�
������A�q�_�������˱o�A���������H�H�a�A���y���P�򰣤F�����N
�O�����A�ݨӨS���䥦�X���F�A���D���W����(jump)�C
LONG
);
  set("no_clean_up", 0);
  set("outdoors","land");
  set("no_auc", 1);
  set("item_desc", ([
      "����" : "�����ƤV���@�������A�~�k����ơC\n",
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
  if(!arg || arg!="����" ) return 0;
  if(me->query_skill("dodge",2) <40)
  {
    message_vision( "$N�ϺɤF�ۦ��A���a�D��O�����A��򳣸����W�����C\n" ,me);
    return 1;        
  }
  message_vision(HIW"$N����@�D�ӤW�A�������򩥾��A�X���ɤO�ᨭ�v�����b�������t�@��C\n"NOR,me);
  me->move(__DIR__"room2");
  tell_room(environment(me),me->query("name")+"�I�i�¼������k�A�q�����W���F�U�ӡC\n",me );
  return 1;
}
