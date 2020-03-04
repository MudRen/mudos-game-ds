#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);
 set("long",@LONG
�A�ש��F�k�����W�F, �A�ݤF�ݥ|�P, �ä��O�A�Q������
���˯��Z��, �ϦӦ��I��D, �N�b�A���椧��, �Ať��b�F��
���H�m�Z���n��, �A��Ҩ쩳�|�O�֩O?  
LONG);
 set("item_desc",([
        "���@�k��":"�@���Q���~�k���k��, �ݨӨS���@�w���\\�O�O�W���h��, �V�U�����G�Z�e����",    
 ]));

 set("exits",(["east":__DIR__"bird8",
     ]));
 set("outdoors","land"); 
 set("no_clean_up", 0);
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
        return notify_fail("�A�n�������H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "down") return 0;
        message_vision(HIR"$N���n�R�����U�@���I\n"NOR ,me); 
        if (random(me->query_skill("dodge")) >= 40){  
        me->move(__DIR__"bird1.c");

message_vision(HIW"$N�I�i���@���\\�A�q"HIR"���@�k��"NOR+HIW"���U�A$N�~�M�@�v�L��..\n"NOR ,me); 
        return 1;
        } 
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
}

