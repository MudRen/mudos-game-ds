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
                    __DIR__"npc/cobra" : 2,
                    __DIR__"npc/boa" : 1,
        ]));
        set("exits", ([
              "north" : __DIR__"chink02",
              "out" : __DIR__"backyard07",
        ]));
         set("item_desc", ([                    
                "stone": HIB"\n�o�����Y�e���Q��A���o�۰}�}�H��A�۶��W�W���i�h���O�ӥk���x�ΡC\n"NOR,
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
        	
        if( (int)me->query_temp("move_stone") ) 
                return notify_fail("�A�w�g���ʹL�F�۶��C\n");
                
        if (arg == "stone" ){   
           	message_vision("$N�`�`�l�F�f��A���X�k�����۶��W����L�A�w�w�V�U���h�C\n", me); 
           	me->set_temp("move_stone", 1);
           	message_vision("$N�N�۶����U�o�\\�A��������ť��a�U�ǨӤ@�}�F���n�C\n", me); 
           	me->start_busy(5);      
           	call_out("poisoned", 5, me);
        }     
        return 1;
}

int poisoned(object me)
{
        if(!me) return 0;
        
        if ((int)me->query_skill("anti_poison", 1) < 50 ){
               tell_object(me, HIB "�A�P��۶��W�����𶶵ۤ��u�C�C�ǤF�W�ӡC\n\n" NOR );
               message_vision("$N��M���l�@Ÿ�A�n���O���F�H�r�I\n", me);
               me->apply_condition("cold_poison", me->query_condition("cold_poison")+random(30));
               return 1;
               }   
        else {
               tell_object(me, HIB "���M�@�ѳ��𶶵ۤ��u�q�۶��W�C�C�ǤF�W�ӡC\n\n" NOR );
               tell_object(me, HIW "�A�s���B�\\�ծ�A�N�I�J���u���H��ɼƹG�F�X�h�C\n" NOR );
                me->apply_condition("poison", me->query_condition("poison")+random(20));
               return 1;
               }           
}
