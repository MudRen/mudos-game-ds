#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�_��");
        set("long", @LONG
�o�̬O�۶��P�۶����������_�A���u���t�C�A����Pı��|�P���F�F
�n�O�U�جr�Ϊ��檺�n���A�@�ѪѸ{�����]�����ۤ@�Ǩ�󪺮𮧡C�A�o
�{�e�����@�۶�(stone) �����o�X�H�H�����~�C
LONG);
       set("objects", ([
                    __DIR__"npc/cobra" : 4,
        ]));
        set("exits", ([
              "south" : __DIR__"chink01",
              "west" : __DIR__"chink03",
              "out" : __DIR__"backyard08",
        ]));
         set("item_desc", ([                    
                "stone": HIR"\n�o�����Y�e���E��A���o�۰}�}����A�۶��W�W���i�h�������O�ӥ����x�ΡC\n"NOR,
        ]));
        setup(); 
}

void init()
{
        add_action("do_push", "push");      
}

int do_push(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("�A�����۩O�C\n");
        	
        if( !me->query_temp("move_stone") ) return 0;
        if( (int)me->query_temp("move_stone") > 1) 
                return notify_fail("�A�w�g���ʹL�F�۶��C\n");
                
        if (arg == "stone" ){   
           	message_vision("$N�`�`�l�F�f��A���X�������۶��W����L�A�w�w�V�U���h�C\n", me);            
           	me->add_temp("move_stone", 1);
           	message_vision("$N�N�۶����U�o�\\�A��������ť��a�U�ǨӤ@�}�F���n�C\n", me);
           	me->start_busy(5);      
           	call_out("poisoned", 5, me);
        	return 1;
        } 
        return 0;    
}

int poisoned(object me)
{
        if(!me) return 0;
        
        if ((int)me->query_skill("anti_poison", 1) < 60 ){
               tell_object(me, HIR "�A�P��۶��W���������𶶵ۤ��u�C�C�ǤF�W�ӡC\n\n" NOR );
               message_vision("$N��M���l�@Ÿ�A�n���O���F���r�I\n", me);
               me->apply_condition("hot_poison", me->query_condition("hot_poison")+random(50));
               return 1;
               }   
        else {
               tell_object(me, HIR "���M�@�Ѫ������𶶵ۤ��u�q�۶��W�C�C�ǤF�W�ӡC\n\n" NOR );
               tell_object(me, HIW "�A�s���B�\\�ծ�A�N�I�J���u����������ɼƹG�F�X�h�C\n" NOR );
                me->apply_condition("poison", me->query_condition("poison")+random(20));
               return 1;
               }               
}
