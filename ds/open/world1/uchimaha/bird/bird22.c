#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�m�Z��");

 set("long",@LONG
�A�Ө�ѱ��Ъ��m�Z��, �A�ݬݥ|�P, �o�{�o�̰�
�F�@�ǥۼΥH�~�O�L�L��, �A���L�h�ݤF�ݥۼ�, �o�{
��ӳo�̬O�M���m���F�l�K�B�Z���ۼ�, �A�V�F�V�ۼ�,
�쥻�o�̪��ۼεw�׳����@��, ���p�@�Ӥ��p�ߥi��|
��o�ۼε����_, �ҥH�m�_�ӥ[�����x���C
 
LONG
    );
 
 set("exits",(["south":__DIR__"bird14",
               "north":__DIR__"bird20",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
int do_practice(string arg)
{
        object me,weapon;       
        me=this_player();

        if(!arg) return 0;
        if(!me->query_skill("birdeight") ) return 0;
        if(arg!="bird-eight") return notify_fail("�A�u��m�F�l�K�B�Z(bird-eight)�C\n");

        if(me->query_skill("bird-eight")>9 )  return notify_fail("�A���F�l�K�B�Z�w���p���F�A�b���m�B�w�L�q�F�C\n");
        if(me->query("ap") <10) 
                return notify_fail("�A�����l�����A����m�j�j�Z�C�C\n");

     message_vision("$N���_�@�f��A��J�ۼΤ��A�}�l�m�_�F�l�K�B�Z�̪������w��C\n");
        me->receive_damage("ap",10);
if(me->query("sk/bird-eight") )
                me->add("sk/bird-eight",random(me->query_int()) );
        else
                me->set("sk/bird-eight",random(me->query_int()) );

      if(me->query("sk/eight-bird" )>5000)
        {
                tell_object(me,HIY "�g�L�@�f�W�m�A�A���F�l�K�B�Z�w�g�[���N���F�C\n" NOR);
        me->delete("sk/bird-eight");
          me->set_skill("bird-eight",10);
        }
        return 1;

}

           
