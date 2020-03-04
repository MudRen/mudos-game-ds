#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�|�l");
        set("long", @LONG
�o�Ӱ|�l�����u���X���p��A�o���ۤW�ʰ諸���Y�C�o�ǥ��Y���j
���p�A�j�p�@���ЫΡA�p�p�@���n�J�C�A�o�{����G��U���@���`���A�U
������լլݤ��M������F��C���ᦳ�D�K��(door)�A���L�w�g���W�F�C
�@�ѪѪ��{����ƨӡA�ϧA�֭n���äF�C
LONG);
        set("exits", ([
              "northwest" : __DIR__"backyard07",
              "jumpdown" : __DIR__"lake01",
        ]));

        setup(); 
}

void init()
{
     	object me = this_player();
        add_action("do_climb", "climb");
        add_action("do_push", "push");
               
}

int do_climb(string arg)
{
        int dex;
        object me = this_player();

        dex = me->query_dex();

        if (me->is_busy() || me->is_fighting() )
        	return notify_fail("�A�����۩O�C\n");
        	
       	if (dex < 18 )
        	return notify_fail("�o�G�����G�A�A�o���]½���L�h�C\n");
       	if (dex > 17 ){  
           	message_vision("$N����b�G��W�@���A�@½���K�a�F�L�h�C\n", me);
           	me->move(__DIR__"backyard05");
           	message("vision", me->name() + "�q�|�l�̭�½�F�L�ӡC\n",environment(me), ({me}) );
           	return 1;
           	}     
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        str = me->query_str();

       	if( !arg ) return 0;
       	if (arg == "door" ){        
       		if( (int)me->query_skill("anti_poison", 1)){
           		message_vision("$N�ۤU���l�A���x�������V�K���C\n", me);
           		message_vision("�K����M���}�A$N�@�S�d���u�F�i�h�C�K���o�S�X�W�F�C\n", me);
           		me->receive_damage("hp", 100);
           		me->receive_damage("mp", 50);
           		me->move(__DIR__"backyard05");
           		message("vision", "�uť�Ԫ��@�n�A�@�ӤH�v�q�K���X�u�F�L�ӡI\n",environment(me), ({me}));
           		}
       		if (str < 21 )
               		return notify_fail("�A�ϥX�F�Y�����O��A�i�N�O�����ʳo�K���C\n");
      		else {  	
           		message_vision("$N�ϥX�����O����V�K���A�i�K���o�������ʡC\n", me);
           		me->receive_damage("hp", 300);
           		me->receive_damage("mp", 150);
           		}       
       		}
       return 1;        
}