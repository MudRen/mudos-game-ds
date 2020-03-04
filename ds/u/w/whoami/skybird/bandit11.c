#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","�|ĳ�U");
 set("long",@LONG
�A�i�Ө�o�N�Pı��@�ѵ±�����, �b�A�����e���@�i
�j�Ȥl�M�W���Q�۶¦⪺����. �o��j�Ȥl���ⰼ�U���@��Q
�۪�֪��Ȥl. �Q���o�N�O�Q�פ@���p�����|ĳ�U�F, ����b
�A���e���H�@�w�N�O�o�Ӥs�몺��D�F.
LONG);
 set("exits",(["southwest":__DIR__"bandit10", 
    ])); 
 set("objects", ([__DIR__"npc/wen_tzyy_ian" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();

}

void init()
{
    object me=this_player(),ob=this_object();  
    ::init();

    if( !me->query_temp("assassinate") ) return;
    tell_object(me,"�o�̪��H���G���S�o�{�A�����N�N�����F�L�ӡE\n"); 
    add_action("do_assassinate","assassinate");
    call_out("ass",2);
}

void ass()
{
    object env,wp,me=this_player(),ob=this_object();
    env = environment(me);
    
    if( env != ob ) return;
    tell_object(me,"�s��j�Y�ػD���ϲ{�b�@�L���ƪ��I��ۧA�A�ݨӳo�O�@�ӷt��(assassinate)�o���n���|�E\n");
    return; 
}

void do_assassinate()
{
    object target,wp,me=this_player(),ob=this_object();
    string arg;  
    if( !me->query_temp("assassinate") ) return; 
//    if (!target=present(arg, environment(me))) return;
    target = find_living("Wen_Tzyy_Ian");
    message_vision("\t\n$N�����N�N��$n���I�ᱵ��K�K\n",me,target);
    message_vision("\t$N�H�a�߰_�F�@��Z���A�H�Y��$n���n�`�B��F�L�h�I�I\n",me,target);
    message_vision("\t\t$n�Q$N�𪺱��⤣�ΡA�N�o�˦��F�E\n\n",me,target);
    target->set_temp("temp/death_type",HIR"[����t��]"NOR); 
    target->die(); 
    return 0;
} 

void door_open()
{
    if( this_object()->query("exits/enter") ) return;
    this_object()->add("exits",(["enter":__DIR__"bandit14"]));
    write(WHT"\n�D���Ϥ@���A�o���᪺�۪��H�Y�}�_�F�K�K\n"NOR);
    call_out("door_closed",30); 
    return;
}

void door_closed()
{
   this_object()->delete("exits/enter");
   tell_room(this_object(), HIW"�۪��y�I�z���@�n�A��M�Q���W�F�E\n"NOR);
 
 //  write(HIW"�۪��y�I�z���@�n�A��M�Q���W�F�E\n"NOR);
   __DIR__"bandit14"->door_closed();
   return;    
}

