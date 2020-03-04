#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", BLU"�D��"NOR);
        set("long", @LONG
�@�ӳ��`�`������A�������a���V���C�A�Pı����̦��F��b�V�A��
�ӡC�C�C�O���D�I�ֶ](jumpup)�a�I
LONG);
        set("objects", ([
                    __DIR__"npc/boa" : 2
        ]));
        setup(); 
}

void init()
{
        object ob;       
        if (interactive(ob = this_player())) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
               }       
       	add_action("do_jumpup", "jumpup");
}

int do_jumpup(string arg)
{
      	object me = this_player();
      	int dex = me->query_dex();
      	
      	if(me->query("hp") < 500 ) 
        	return notify_fail("�A�w�g�S����O���W�h�F�C\n");

        if(me->is_busy() ) 
        	return notify_fail("�A�����۩O�C\n");
        	
        if (objectp(present("boa constrictor", environment(me)))){
        	  me->receive_damage("hp", 50);
           	me->receive_damage("ap", 50);
       		if( dex > 20 && dex < 26) {
           		message_vision(HIR"$N�ΤO���W�@�a�A�o�S�Q�������F�������F�U�ӡI\n"NOR, me);
           		me->receive_damage("hp", 200);
           		}
       		if(dex >= 26 && dex < 32) {
           		message_vision(HIY"$N�ΤO���W�@�a�A���t�I�S�Q�������F�����A���ש�k�X�F�D��I\n"NOR, me);
           		me->receive_damage("hp", 100);
           		me->move(__DIR__"backyard06");
           		tell_room(environment(me), me->name()+"�q�D�椧�����W�ӡA�}�U�@�n�A�y��a�զa���˦b�a�C\n", ({ me }));
          		}
       		if( dex >= 32) {
           		message_vision(HIR"$N�ΤO���W�@�a�A���X�F�D��C\n"NOR, me);
           		me->move(__DIR__"backyard06");
           		tell_room(environment(me), me->name()+"�q�D�椧�����F�W�ӡA�Ҽ˯T�V�����C\n", ({ me }));
          		}
       		else { 
           		message_vision("$N�ϫl�@���A�i�O�����W�h�A�ϦӳQ�D�r�r�F�@�f�I\n", me);
           		me->receive_damage("hp", 200);
           		me->receive_damage("ap", 100);
           		}
       		}
       else { 
           	message_vision("$N�ϫl�@�a�A���X�F�D��C\n", me);
           	me->receive_damage("hp", 50);
           	me->receive_damage("ap", 50);
           	me->move(__DIR__"backyard06");
           	tell_room(environment(me), me->name()+"��M�q�D�椧�����F�X�ӡA�y�a���ߤ���C\n",({ me }));
        	}
       return 1;
}


void greeting(object me)
{
	if (!me) return;
	if( (int)me->query_temp("backyard_climb") < 2) {
        	message_vision(HIR"$N�q��W���F�U�ӡA���n���b�F�������W�I\n�٨S�^�L���ӡA�w�g�Q�������F�I\n"NOR, me);
           	write(BLU"�A�Q�������A�V�ӶV��C�C�C\n�A�P��@���ƪ����}�l�C�C�����A�ӥh�F�C�C�C\n"NOR);
           	me->delete_temp("backyard_climb");
           	me->unconcious();
           	}
        else if((int)me->query_temp("backyard_climb") == 2){
           	message_vision(HIR"$N�q��W���F�U�ӡA���n���b�F�������ǡI\n�r�O�@���A���}�o�٬O�Q�������F�I\n"NOR, me);
           	write(BLU"�A�Q�������A�V�ӶV��C�C�C�A���Q�k�k�]�N���w�F�I\n"NOR);
           	me->receive_damage("hp", 500);
           	me->receive_wound("hp", 200);
           	}
        else {
           	message_vision(HIR"$N��譸�a�L�ӡA�N�o�{�F�D��̦������I\n"NOR, me);
           	write(BLU"�A�ݨ������V�A���F�L�ӡA�֨��I\n"NOR);
           	message_vision(HIY"$N���b�b�����u�@���A����ɤO�S�����X�h�A���X�F�D��I\n"NOR, me);
           	me->receive_damage("ap", 100);
            me->receive_damage("hp", 100);
           	me->move(__DIR__"backyard06");
           	tell_room(environment(me), me->name()+"�q�D�椧�����D�W�ӡA�y�W�a����Y����C\n",({ me }));
        	}      
        me->delete_temp("backyard_climb");
}
