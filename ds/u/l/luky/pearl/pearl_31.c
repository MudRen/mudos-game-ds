#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "[1;32m���R���[m");
set("long", @LONG

  �o�̦��@�j�����R����E�C�\�h�u�H���b�V�O���ت�, �٦��@��
�ت᪺�u���b�a�W�K�O�ѤH�ϥΡC�o�̪��C�@�ʪ�쳣�O�צ~��
�}���M���䦳�ӧi�ܵP[1;32m([1;36msign[1;32m)[0m�C

LONG);
 set("exits", ([
"east" : __DIR__"pearl_14",
]));
set("item_desc",([
"sign":@NOTE

�o�̥i�H��(plow)���į�

��    Ħ(green algae)
�i �i ��(coco bean)

NOTE
,
"�u��":"�o�X����l�ܱ`���]�ܴ��q, ���G�ä��@�ΡC\n",
"tools":"�o�X����l�ܱ`���]�ܴ��q, ���G�ä��@�ΡC\n",
]));
set("light",1);
setup();
}
void init()
{
 add_action("do_plow","plow");
}
int do_plow(string arg)
{
 object me,ob;
 int a,b;
 me=this_player();
if(!me) return 0;
 a=me->query("ap");
 b=20-(int)me->query_skill("product")/5;
 if(this_player()->query("class")!="worker")        
  return notify_fail("�u���u�H�~�����b�o�ت�\n");
 if(this_player()->query_temp("wood"))
  return notify_fail("�A�٦b�تF���..\n");
 if(!arg) 
  return notify_fail("�A�n�ؤ���O??'n");
 if(arg=="green algae")
 {
 if(a<400)
  return notify_fail("�A����O�����F\n");
 me->set_temp("wood",1);
 a=me->query_skill("product");
 me->set_temp("time",4);
 call_out("green",b,me);
 } 
else if(arg=="coco bean")
{
if(a<530)
 return notify_fail("�A����O�����F\n");
me->set_temp("wood",1);
a=me->query_skill("product");
me->set_temp("time",4);
call_out("coco",b,me);
}else return notify_fail("�A�Q�n�ؤ����\n");
me->start_busy(b);
return 1;
}

int coco(object me)
{
object ob;
int time,a,b;
if(!me) return 0;
time=me->add_temp("time",-1);
if(!me->query_temp("wood"))
return 1;
if(me->query_temp("time")<1)
{
me->delete_temp("no_quit");
me->delete_temp("wood");
message_vision("[1;32m$N[1;32m��@�c�c���i�i�����]�_��...[0m\n",me);
return 1;
}
if(me->query_temp("netdead"))
{
me->delete_temp("no_quit");
me->delete_temp("wood");
return 1;
}
if(me->query("ap")<530)
{
me->delete_temp("wood");
return notify_fail("�A����O�����F\n");
}
me->add("ap",-530);
ob=new(__DIR__"obj/coco");
a=me->query_skill("product")/5;
a=(int)a;
b=20-a;
tell_object(me,"[1;32m�A���b�V�O�إi�i��[0m\n");
if(me->query_max_encumbrance()<ob->query_weight()+me->query_encumbrance())
ob->move(environment(me));
else ob->move(me);
call_out("coco",b,me,time);
return 1;
}

int green(object me)
{
object ob;
int time,a,b;
if(!me) return 0;
time=me->add_temp("time",-1);
if(!me->query_temp("wood"))
return 1;         
if(me->query_temp("time")<1)
{
me->delete_temp("wood");
me->delete_temp("no_quit");
message_vision("[1;32m$N[1;32m����A, �⨯�W�ئn����Ħ�`���_��...[0m\n",me);
return 1;
}
if(me->query_temp("netdead"))
{
me->delete_temp("no_quit");
me->delete_temp("wood");
return 1;
}
if(me->query("ap")<400)
{
me->delete_temp("wood");
return notify_fail("�A����O�����F\n");
}
me->add("ap",-400);
ob=new(__DIR__"obj/green");
a=me->query_skill("product")/5;
a=(int)a;
b=20-a;
tell_object(me,"[1;32m�A���b�V�O�غ�Ħ[0m\n");
if(me->query_max_encumbrance()<ob->query_weight()+me->query_encumbrance())
ob->move(environment(me));
else ob->move(me);
call_out("green",b,me,time);
return 1;
}
