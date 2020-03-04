#include <ansi.h>  
inherit ROOM; 
void create()
{
        set("short", "���}��");
        set("long", @LONG
������@���A�b���·t���}�ޤ��A���G���ط������ƪ��ͪ�
�A�F�F���n�T�A���_���o�X�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : "/open/world1/cominging/area/fgo2.c",
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
  object me=this_player(),ob=this_object(),mobp; 
  if(ob->query_temp("throwed")) return notify_fail("��観�H��L�F�C\n");
  if(!arg||arg!="fruit") return notify_fail("�A�n�ᤰ��?\n");
  message_vision("$N�N"+ob->name(1)+"��V�}�޲`�B...\n"
                 "��M�ĥX�@�����D�I�]�U���������G�I\n",me);   
  me->start_busy(2);  
  mobp=new(__DIR__"hua-snake"); 
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
