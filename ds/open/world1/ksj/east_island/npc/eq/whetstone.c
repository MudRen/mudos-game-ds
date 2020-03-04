#include <path.h>
inherit ITEM;
int i=0;

void create()
{
  set_name("�i�M��", ({"whetstone","stone"}) );
  set("long",@LONG
�@���������Ѱ�w���Y�s�����i�M�ۡA�Ψӥ��i�Z���^�_�U�Q
(whet)�C
LONG
);
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",1);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_whet","whet");
}

int do_whet(string arg)
{
  object me,obj,stone;
  int dur;
  me=this_player();
  stone=this_object();
  if( me->is_busy() ) return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
  if( me->is_fighting() ) return notify_fail("�A�b�԰����A�S�Ű��o��ơC\n");
  if(!arg) return notify_fail("�A�n�οi�M�ۭ״_����F��H\n");
  if(!objectp(obj = present(arg, me)) ) return notify_fail("�A���W�S���o�˪F��C\n");
  if( obj->query("no_repair") ) return notify_fail("�o��F��S��k�״_�C\n");
  dur=obj->query_durable();
  if( dur < 70 ) return notify_fail(obj->query("name")+"�w�g�l�a�o�L�k�i�Q�C\n");
  if( dur > 99 ) return notify_fail(obj->query("name")+"���ݭn�״_�C\n");
  message_vision("$N���_�i�M�ۡA�J�ӥ��i$n���l���a��C\n",me,obj);
  obj->set_durable(100);
  i=i+1;
  stone->set_temp("used",i);
  if( stone->query_temp("used") > 2 )
  {
    tell_object(me,"�i�M�ۤw�g�����ϥΤF�A�A�H���b�@�ǡC\n");
    destruct(stone);
  }
  return 1;
}
