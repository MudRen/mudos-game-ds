// Room: /u/l/luky/workroom.c
#include <ansi.h>  //�Y�n�Φ��C�⪺���[����
#include <room.h> //�n�[���n�o�@��
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short","�o���q�|");  //�u�ԭz
 set("long","\n"
	+"  �o�̬O�@�Ӽo���q�|, �|�g���O�@�Ƿl�a���u��M�U��...���L�A�o�{\n"
	+"���䦳���p�Ĥl�諸�B�ʾc(boots), ���G���Z�s���C�o�̫ܾA�X��Ĥl��\n"
	+"�����K��a..�γ\\���w�g�O�Y�ǫĤl�̪���a�F�C\n"
 ); //���ԭz

 set("exits", ([  //���ж��s�����X�f��V���ɮ�
 "north": __DIR__"quest2",
 "out": __DIR__"hall4",
 ]));
 set("item_desc", ([
     "boots" : "�@���զ⪺�B�ʾc, �γ\\�A�i�H�յۧ�J�Ӫ��j�d(search)�ݬݡC\n",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 create_door("north","�¦��K��","south",DOOR_LOCKED,"redkey");
 setup();
}

void init()
{
 add_action("do_open","open");
}

int do_open(string arg)
{
 object me,jail,boy;
 
 me = this_player();
 
 if(arg=="door" || arg=="north")
 {
  jail = load_object("/d/wiz/quest2");
  if(!jail) return 0;
  boy=present("boy",jail);
  if(!boy) return (int)call_other("/cmds/std/open", "main", me, arg);
  if(!call_other("/cmds/std/open", "main", me, arg)) return call_other("/cmds/std/open", "main", me, arg);
  message_vision("��M�@�Ӥp�Ĥl�q�K���᭱���F�X�ӡC\n",me);
  boy->move(this_object());
  message_vision(YEL"$N(boy)��:�ڧѤF�a�_�ͤF...���§A�ϤF�ڤ@�R!!\n",boy);
  message_vision(HIY"$n�ѰJ���P�E$N�����U�C\n"NOR,me,boy);
  tell_object(me,HIC"\n���ߧA�����F�@�ӳ�²�檺����!!, �{�b����Ȧ��I�߱o�F�a!\n\n"NOR);
  return 1;
 }
 return 0;
}

int do_search(object me,string arg)
{
 object key;
 if(!arg) return 0;
 if(arg == "boots")
 {
  if(this_object()->query_temp("key"))
  {
   message_vision("$N���_�ൣ�B�ʾc�ˬd�F�@�f..���O�S������s�o�{, �u�n��^��B�C\n",me);
   return 1;
  }
  message_vision("$N���_�ൣ�B�ʾc�ˬd�F�@�f..��M���X�@���_�͡C\n",me);
  key = new("/u/l/luky/redkey");
  key->move(this_object());
  this_object()->set_temp("key",1);
  return 1;
 }
 return 0;
}

void reset()
{
	this_object()->delete_temp("key");
	::reset();
}