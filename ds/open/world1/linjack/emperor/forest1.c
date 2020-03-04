#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","�K�L�J�f");
 set("long",@LONG
�o�̬O�@�B�K�L���J�f, �|�P�����u�۷���t, �u�������}����V
�����u�|�٩��G. �A�b�o�̰��y�F�@�U, �o�{�e��K�L�L��Z��, �A��
�ܵL�k�o�{�i�H�q���̶i�h�o���K�L, ���A�i�b����J�ӧ��(search).
�o�䦳�Ӽлy(sign). �A�̦n���J�Ӫ��ݬݤW���b�g����.
LONG);

 set("exits",([ "south":__DIR__"road4",]));
 set("item_desc",([
     "�p�Ż�":"�A��F�Ѥj�b��, �`��ݨ�Ӥp�p���Żئ��G�i�H��\n
�A�p(squeeze)�i�h�K�L�����C\n",
     "�лy":"�лy�W�g��: ���B�M�I! �е���P��...! ����a�o����..! �`�N!\n",
        "sign":"�лy�W�g��: ���B�M�I! �е���P��...! ����a�o����..! �`�N!\n",
]));
               
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}
void init()
{
  add_action("do_squeeze","squeeze");
  add_action("do_pick","pick");
}
int do_squeeze(string arg)
{
  object me;
  me=this_player();
  if(!arg) return notify_fail("�A�n�p�i���� ?\n");
  if( arg != "�p�Ż�" && arg != "�Ż�")
    return notify_fail("�o�Ӧa�観�Ŷ����A�p�i�h�� ?\n");
  message_vision("$N�Y�ۨ��l�w�O���i�F�o���K�L��.\n",me);
  me->start_busy(2);
  me->move(__DIR__"forest2");
  return 1;
}

void clear_pick() {
        set("picked",0);
}

int do_pick(string arg)
{
  object me,key;
  if( !query("active_action") ) return 0;
  if( query("picked") ) return 0;

  me=this_player();
  if( me->is_fighting() || me->is_busy() ) return notify_fail("�A���b���C!\n");
  if( !arg || ( arg != "key" && arg != "�_��" ) ) return notify_fail("�A�n�ߤ���?\n");

  key = new(__DIR__"npc/obj/greenkey");
  message_vision(HIB"$N��M�q���O����X�F�@���_��!\n"NOR,me);
  key->move(me);
  set("picked",1);
  add("item_desc",([ "�ݰ_�өǩǪ����":"�o���S�S����n�ݪ�..\n" ]));
  call_out("clear_pick", 600 + random(150) );
  return 1;
}

