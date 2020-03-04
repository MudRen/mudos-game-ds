#include <ansi.h>  
inherit ROOM;
 
void create()
{
  set("short", "���}�`�B - �j�ѩ~");

  set("long", @LONG
������@���A�b���·t���}�ޤ��A���G���ط������ƪ��ͪ��A
�F�F���n�T���_���o�X�A�A�p���l�l�����b�@�ǡA�Y�O�H�K�å��F��
���i��|�X�{���򮣩ƪ��ͪ��A�@�ǰ�۳\�h�G�ꪺ���e�C
LONG
  );
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"snake-room1",
     ]));
  set("item_desc",([
      "�G�ꪺ���e" : "�\\�h�Q�٭���@�b���U�تG��A���N�O�S�����⪺�G��H\n",
     ]));
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_throw","throw");
}

int do_throw(string arg)
{ 
  object me=this_player(),ob=this_object(),mobp,z; 
  if(ob->query_temp("throwed")) return notify_fail("��観�H��L�F�C\n");
  if(!arg||arg!="fruit") return notify_fail("�A�n�ᤰ��?\n");
  if(!objectp(z=present("fire fruit",me) ) )
    return notify_fail("�A�S���F��i�H��� ? \n");
  message_vision("$N�N�����G��V�}�޲`�B...\n"
                 "��M�ĥX�@�����D�I�]�U���������G�I\n",me);
  destruct(z);
  me->start_busy(2);  
   mobp=new(__DIR__"npc/hua-snake"); 
  mobp->move(environment(this_player()));   
  mobp->kill_ob(this_player()); 
  ob->set_temp("throwed",1); 
  call_out("stop_throwed",600,ob);
  return 1;
}

void stop_throwed(object ob)
{
  if(!ob) return; 
  ob->delete_temp("throwed");
}

