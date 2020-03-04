#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"���D"NOR);
        set("long", @LONG
�o�����t�����D�b�s�������驵���A�����q����B�C�e�����D���V��
�V�t�A�A�֭n�ݤ����F��F�C�a�W�����۴X�Ӥ���A���G�٥i�H�ϥ�
(use fire)�C�o�̪Ů�ÿB�A�٧����ۤ@�Ѩ�󪺨��D�A�A�@���L��
�Kı�o�Y���o�w�A���O���r�F�C
LONG);                
        set("exits", ([
              "west" : __FILE__,
              "east" : __DIR__"lane03",
              "north" : __DIR__"lane04",
              "south" : __FILE__,    
        ]));
   set("objects", ([
       __DIR__"obj/fire" : 1,
       ]));
        setup(); 
}


void init()
{    
  	object me = this_player();
     	if (random(me->query_skill("anti_poison")) <50 && me->query_con() < 50){ 
        	tell_object(me, HIB "�A���M�P��I�l�@��A��ӬO�o�̪��Ů�ÿB�B�y�q���Z�C\n" NOR );      
             	tell_room(environment(me), me->name()+"��M�y���ܱo�������ݡA�ò`�`�a�l�F�f��C\n" NOR,({ me }));
             	me->receive_damage("hp", 50);
             	me->receive_damage("mp", 50);
             	me->receive_damage("ap", 50);
             	}           
        add_action("do_use", "use");
        add_action("do_push", "push");
}


int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write("�A�I�U�F����A�o�{�e���۾��W���@�}�f�A���Q���۰���F�A�����ण���(push)�}���C\n");
             this_player()->set_temp("marks/��", 1);
             return 1;
       }
}

int do_push(string arg)
{
        object me = this_player();
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("�A�����۩O�C\n");
        	
        if (arg == "stone"){    
        	if (me->query_temp("marks/��") ) {
          		if(me->query("class1") != "�ѱ���" ){
               			me->add("hp", -(1+random(100)));
               			me->add("ap", -(1+random(100)));
               			me->add("mp", -(1+random(100)));
               			message_vision(HIR "$N�B��r�O�V���ۤ@���A���G�����S���}���A�ϦӾ_�ˤF�ۤv�C\n" NOR, me);
               			me->unconcious();
               			return 1;
               			}
           		else{
            			message_vision("$N�X�x����ۡA�r�a�@���N���۱��}�@���_�p�F�X�h�C\n", me);  
            			me->move(__DIR__"laneout");
            			message("vision", me->name() + "�q�å۰���p�F�X�ӡC\n",environment(me), ({me}) );
            			this_player()->delete_temp("marks/��");
            			return 1;
          			}
        		}
       		}
        else {
            	write("�A�Q������H\n");
            	return 1;
        	}
}
