#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG 
�A�S���F�n�@�q�ɶ�, �A�Y�W�������w�g�p�U�B�몺�y�U, 
�A��_�Y�ө��W��F��, �ש�ݨ쳻�F!!�A�ߤ����Ѫ������U
��, �]���A���V�O�ש󦳤F�N��, ��O�A�[�ָ}�B, ���W�e�h�C
LONG
    );
 
 set("no_clean_up", 0);
 set("outdoors","land"); 
 setup();
}           

void init()
{
  add_action("do_jump","jump"); 
}

int do_jump(string arg)
{        
       object me; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n���L����H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "���@�k��") return 0;
        if (random(me->query_skill("dodge")) >= 20){
        message_vision(WHT"�u��$N�I�i�W�m�\\�[�����\\�A�V�W�@�D�K�������L�v�L�ܤF..\n"NOR ,me);
        me->move(__DIR__"bird7.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
        return 1;
        }
          if ( me->query("level") <= 5 ) {
                message_vision( "�u��$N�¤�¸}�a���k�������h�C\n"NOR ,me);
                me->move(__DIR__"bird7.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
                return 1;
        }

        message_vision(HIR"$N�}�@�ơA���髫���ֳt�U�Y�I�I\n"NOR ,me); 
        me->start_busy(4+random(3));        switch(random(7)){
        case 0:
            me->receive_wound("left_leg",2);
            me->receive_wound("right_leg",2);
            me->receive_wound("left_arm",2);
            me->receive_wound("right_arm",2);
            me->receive_wound("head",2);
            me->receive_wound("body",2); 
        me->move(__DIR__"bird5.c");
        message_vision(HIC"$N���t�����A�ߨ诸í�}�B�A�S���줰��ˮ`�E\n"NOR ,me); 
        return 1; 
        case 1:
            me->receive_wound("left_leg",4);
            me->receive_wound("right_leg",4);
            me->receive_wound("left_arm",4);
            me->receive_wound("right_arm",4);
            me->receive_wound("head",4);
            me->receive_wound("body",4); 
        me->move(__DIR__"bird4.c");
        message_vision(HIC"$N���t�����A�ߨ诸í�}�B�A�S���줰���Y�����ˮ`�E\n"NOR ,me); 
        return 1;
        case 2:
            me->receive_wound("left_leg",6+random(10));
            me->receive_wound("right_leg",6+random(10));
            me->receive_wound("left_arm",6+random(10));
            me->receive_wound("right_arm",6+random(10));
            me->receive_wound("head",6+random(10));
            me->receive_wound("body",6+random(10)); 
        me->move(__DIR__"bird3.c");
        me->receive_damage("hp",me->query("hp")*2/3);
        message_vision(HIC"$N���t�����A���O�٬O����F�ˮ`\n"NOR ,me); 
        return 1;
        case 3:
            me->receive_wound("left_leg",10+random(10));
            me->receive_wound("right_leg",10+random(10));
            me->receive_wound("left_arm",10+random(10));
            me->receive_wound("right_arm",10+random(10));
            me->receive_wound("head",10+random(10));
            me->receive_wound("body",10+random(10)); 
        me->move(__DIR__"bird2.c"); 
        me->receive_damage("hp",me->query("hp")*7/10);
        message_vision(HIR"$N�����@�L�A�t�I�����H��..\n"NOR ,me); 
        return 1;
        default:
            me->receive_wound("left_leg",20+random(50));
            me->receive_wound("right_leg",20+random(50));
            me->receive_wound("left_arm",20+random(50));
            me->receive_wound("right_arm",20+random(50));
            me->receive_wound("head",20+random(50));
            me->receive_wound("body",20+random(50)); 
        me->move(__DIR__"bird1.c");
        me->receive_damage("hp",me->query("hp")*19/20);
        message_vision(HIW"$N�q"HIR"���@�k��"NOR+HIW"���ݱ��F�U��..$N�w�g���צ�y�����F..\n"NOR ,me); 
        return 1;
       }}          


