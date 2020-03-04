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
                    __DIR__"npc/boa" : 1,
        ]));
        set("exits", ([
              "east" : __DIR__"chink02",
              "out" : __DIR__"backyard09",
        ]));
         set("item_desc", ([                    
                "stone": HIW"\n�o�����Y�e�ťզ�A���o�۰}�}�x��A�ۭ����@�D���m�⪺�ӽu�A
�۶��W�W���i�h���O�ӥ��k��Ӥ�x����x�ΡC\n"NOR,
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
        if( (int)me->query_temp("move_stone") > 2) 
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
	if (!me) return 0;
        if ((int)me->query_skill("anti_poison", 1) < 70 ){
               tell_object(me, MAG "�A�P���ߤ@�D�A���D���m�ӽu�w�g���b�A����ߤW�C\n" NOR );
               message_vision("$N��M���l�@Ÿ�A�n���O���F�r�I\n", me);
               me->apply_condition("super_poison", me->query_condition("super_poison")+random(20)+10);
               return 1;
               }   
        else {
               tell_object(me, MAG "���M�A����ߤ@�D�A���D���m�ӽu�w�g���b�A����W�C\n" NOR );
               tell_object(me, HIW "�A�s���B�\\�ծ�A�N��ߪ����m�ӽu�G�X�F�j�b�C\n" NOR );
               me->apply_condition("poison", me->query_condition("poison")+30);
               return 1;
               }
                
}
