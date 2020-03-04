#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K�L��");
 set("long",@LONG
�o�O�@���K�L����, �ݰ_�ӥ��u��~������, �ӥB���B�७í�B�檺�a��
�ȶȨ�H���e, �n�O�X�{����r�~�N���n���F. �u�r�r..�A���r�M�o�{�A��
�e��X�{�F�\�h���e�����c�١B���ܰ����������H!?
LONG);

 set("exits",([ "north":__DIR__"forest5",
                "east":__DIR__"forest3"]));
 //���B�n�[ mob.
 set("objects",([ __DIR__"npc/bandit":2, ]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}
void init()
{
 add_action("do_pick","pick");
}
int do_pick(string arg)
{
  object me,key;
  me=this_player();
  key = new(__DIR__"npc/obj/greenkey");
  if( !query("active_action") ) return 0;
  if( query("picked") ) return 0;
  if( me->is_fighting() || me->is_busy() ) return notify_fail("�A���b���C!\n");
  if( !arg || ( arg != "key" && arg != "�_��" ) ) return notify_fail("�A�n�ߤ���?\n");
  message_vision(HIB"$N��M�q���O����X�F�@���_��!\n"NOR,me);
  if( me->query_encumbrance() + key->query_weight() > me->query_max_encumbrance() ||
      me->query_capacity() + key->query("volume") > me->query_max_capacity() )
      key->move(environment(me)); 
  else key->move(me);
  set("picked",1);
  delete("item_desc");
  return 1;
}
