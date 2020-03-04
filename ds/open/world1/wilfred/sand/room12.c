#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIC"�Y�칡�ȴ�"NOR);
  set ("long", @LONG
�o�O���W�ߤ@���ȴ̡A�������ڼ����A�@�ͷN����k�]�M�O�H
���P�A�u�n�O�i�ӦY�����ȤH�A���i�H�ɱ����Y�칡�A���A�F��۷�
�K�y�A�O�۷����H�z�z�ֹD���p���C
LONG
);
  set("exits", ([
  "west" : __DIR__"room11",
]));
  set("objects",([
  __DIR__"npc/npc33" : 1,
  __DIR__"npc/npc32" : 1,
]));
  set("light",1);
  set("no_clean_up", 0);
  set("no_recall",1);
set("no_goto",1);
  set("valid_startroom", 1);
  setup();
}

void init()
{
  add_action("do_put","put");
  add_action("do_run","run");
}

int do_run()
{
  write("���p�G��A���D�G�o��ȭ��A�z�٬O�X�F���A�γo�ӫ��O�a�C\n");
  return 1;
}
int do_put()
{
  write("���p�G��A���D�G�o��ȭ��A�z�٬O�X�F���A�γo�ӫ��O�a�C\n");
  return 1;
}

int valid_leave(object me, string dir)
{
  int i, j=0;
  object *obs = deep_inventory(me);
  for(i=0; i<sizeof(obs); i++)
  {
    if(obs[i]->query("id") == "cheap leg"  ||
       obs[i]->query("id") == "cheap wine" ||
       obs[i]->query("id") == "cheap soup" )
    {
      message_vision("$N��U�@��$n�C\n",me,obs[i]);
      destruct(obs[i]);
      j++;
    }
  }
  if(j) message_vision("���p�G�s����a�W���F�覬�B���b�C\n",me);
  return ::valid_leave();
}