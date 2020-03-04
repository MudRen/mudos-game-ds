#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIW"�۪L�W"NOR);
  set("long", @LONG
�o�̬O�@�p���ƥ۾�L�����ݡA�۪L�K���Ӱ��q�A�A�X�G�L�k��
���U���F��A����O�L�ߵ}�����۪L�����a�A�i�n�Q�M���Y�O���U
�h(jump down)������A���W�ӡC
LONG);
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room33",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
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
  if(!arg || arg!="down" ) return 0;
  if(me->query_skill("dodge",2) <60)
  {
    message_vision("$N��������O�����A�������U�h�C\n",me);
    return 1;        
  }
  message_vision(HIW"$N����@�D�ӤW�A�����s�I�A���Q���U�۪L�C\n"NOR,me);
  me->move(__DIR__"room35");
  tell_room(environment(me),me->query("name")+"�I�i�ӱ������k�A�q�۪L�W���F�U�ӡC\n",me );
  return 1;
}
