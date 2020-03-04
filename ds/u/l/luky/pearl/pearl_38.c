#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "[1;36m�Կp�����]2��[m");
set("long",@LONG
�o�O�Կp�����]��2�ӡA��W���F�@�ǩ��P�����A�٦��@�x�p�B�c
�a�W�Q���O�������Ū��i���a��A���E�Ϊ���O�̵ξA���A�ɪ���
���٦����s�@������ɿO�A�h�ª��A�ݤF�o�̭����@���Ԥ���N��
���E�W�˥h(Sleep)�C
LONG
);
 set("item_desc", ([
"����":@NOTE
[1;32m
                                                  {((((((}
                                                 {)))))))))
                                                ((((( _  _))
                                               )))))) e (e((
                                               ((((((    >)))
                                              _))))))   ()/(
                                           .-'  (((((.--' )))
                   .-'''''-._          _.-'         :: (((((
                 .`          '-.    .-'     _.-''  :::)))))))
                 :              ':-:    _.-' :'   .:::((((((
                 :               .:   .:: : :     ::::)))))))
                  :.          ..::   .:: : '      ::::((((((
                   :.      �i�i::  .:::: : :  �i�i�i::)))))))
       _.-.         :.        \/  :-'-'-'-'`'-.-'`:: :((((((
  __.-'   _\       _ :.        \ /             ))):.  :))))))
 (    .-' ;;'-.-''' '':.        :             (((((:.  :((((
  ```'-..-.;._  _.-''-.\         :             ))))):.   ))))
  __.-'   _\_.`'        \        :            (((((((:. '(((
(    _.-' ;;                     :                    :. '---.__
 `'''-....;;,,,,,,,,,,,,,,,;,___:                      \:..b===='
       \!!!!!!!!!!!!!!!/                     
[m
NOTE
]) );        
set("light",1);
set("no_kill",1);
set("no_cast",1);
set("exits", ([ /* sizeof() == 1 */
"down" : __DIR__"pearl_35",
"up" : __DIR__"pearl_39",
]));
setup();
}

void init()
{
add_action("do_sleep","sleep");
}

int do_sleep(string arg)
{
int time,lv,cost;
string others;
object me;
me=this_player();
if(!me) return 0;
others=query_temp("sleeper");
time=20;
lv=me->query("level");
if (lv<6)
cost=0;
else
cost=(lv+1)/5*5;
if(query_temp("person")>0)
 return notify_fail(HIW"�A�Q�M"+others+"�@�_�γ�??...\n"NOR);
if (me->query_temp("sleep")>0)
 return notify_fail(HIW"�A���b�ιڤ�\n"NOR);
if (me->query("coin")<cost)
 return notify_fail(HIW"�A�Q��ۤv���W�������A�u�n�����o�ө��Y...\n\n"NOR);
me->start_busy(3);
write(HIG"�A���������ɤW���h\n"+"�S�h�[�A�P��h�ֺC�C�o�ΤF\n\n"NOR);
me->set_temp("time",time);
me->set_temp("sleep",1);
me->add("coin",-cost);
add_temp("person",1);
set_temp("sleeper",me->query("id"));
call_out("delay",3,me,time);
call_out("clean_bed",60);
return 1;
}

int delay(object me,int time)
{
int damage,damage1,i;
int lck;
if(!me)
return 0;
lck=me->query("lck");
time=time-1;
damage=me->query("level")*(10+random(lck))+random(10);
damage1=me->query("level")*(6+random(2))+random(3);
me->start_busy(3);
i=random(20);
if(!me)
delete_temp("pp");
if(me->query_temp("time")>0)
{
me->receive_healing("hp", damage,me);
me->receive_healing("mp",damage1,me);
me->add("force",damage1+random(20));
me->add("ap",damage1+random(30));
if(me->query_temp("damage_stab")) me->add_temp("damage_stab",-1);
if(me->query("ap")>me->query("max_ap"))
 me->set("ap",me->query("max_ap"));
if(me->query("force")>me->query("max_force"))
me->set("force",me->query("max_force"));
me->set_temp("time",time-1);
if (i<2)
tell_object(me,HIG"�A�ڨ�n�h½������..\n"NOR);
else if (i<8)
tell_object(me,GRN"�A�ڨ�A�Q�s�������l...�n�h��!\n"NOR);
else if (i<12)
tell_object(me,HIG"�A�Ϊ��n�ΪA��...�����Q�ʤF\n"NOR);
else if (i<16)
tell_object(me,HIG"�A�Ϊ��n�ΪA...���Q�_�ӤF\n"NOR);
else tell_object(me,HIG"�A�ڨ�Qbye bye school...�n�ˤ߳�\n"NOR);
call_out("delay",3,me,time-1);
}
else
{
delete_temp("person");
write(HIW"�A�ι���,ı���믫��_���֡C\n"NOR);
me->delete_temp("sleep");
me->delete_temp("time");
delete_temp("person");
return 1;
}
}
int clean_bed()
{
set_temp("person",0);
return 1;
}
