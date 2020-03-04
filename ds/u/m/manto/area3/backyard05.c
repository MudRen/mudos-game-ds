#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�o�O�Ӥ��j�����A�����@�ﰲ�s�A�@���p�ˡC����غ��F�U�����A
�ڭ��y�H�C�_�����@�D��۪��K��(door)�A�i�H�q���t�@�Ӱ|�l�C
LONG);
        set("exits", ([
              "south" : __DIR__"backyard04",
        ]));

        set("item_desc", ([                    
                "door": "\n�o�D�K������I���A�ݨӨS���X�ʤ��u�O�������ʡC�u�O�_�Ǭ�
��|���p���K���b���A�N�s�@��H���i�H½�V(climb)���䪺�G��C\n",
        ]));
        setup(); 
}

void init()
{

        add_action("do_climb", "climb");
        add_action("do_push", "push");
        add_action("do_smell", "smell");                  
}

int do_climb(string arg)
{
        int dex, i = 0;
        object me = this_player();    
            
        dex = me->query_dex();     
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("�A�����۩O�C\n");
        	
       	if (dex < 18 )
       	
        	return notify_fail("�o�G�����G�A�A�o���]½���L�h�C\n");
       	
       	if (dex > 17 && dex < 25){  
           	message_vision("$N����b�G��W�@���A�@½���K�a�F�L�h�C\n", me);
           	i = 1;
        	}
        
       	if (dex > 24 && dex < 36){  
           	message_vision("$N�B�\\���𻴻��@�a�A�K�D�F�L�h�C\n", me);
           	i = 2;
        	}
        
       	if (dex > 35){  
           	message_vision("$N�}�y�����@�I�A�����D�_�A�ƤF�i�h�C\n", me);
           	i = 3;
        }    
        me->set_temp("backyard_climb", i);
        me->move(__DIR__"backyard06");
        me->start_busy(2);
        return 1;   	    
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        
        str = me->query_str();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("�A�����۩O�C\n");
        	
        if( !arg || arg=="" ) return 0;
        
       	if (arg == "door" ){
       		if (str < 10 )
               		return notify_fail("�A�ϥX�F�Y�����O��A�i�N�O�����ʳo�K���C\n");
               		
       		if(str < 20)
           			message_vision("$N�ϥX�����O����V�K���A�i�K���u�����ʤF�@�U�C\n", me);

       		if(str > 19) 
           		message_vision("$N���l�B��A���x�������V�K���C\n", me);
           		message_vision("�K����M���}�A$N�@�S�d���u�F�i�h�C�K���o�S�X�W�F�C\n", me);
           		me->receive_damage("hp", 200);
           		me->receive_damage("ap", 100);
           		me->move(__DIR__"backyard06");
           		message("vision", "�uť�Ԫ��@�n�A�@�ӤH�v�q�K���X�u�F�L�ӡI\n",environment(me), ({me}));
           		return 1;
           		
       		}
       	else return 0;        
}

int do_smell(string arg)
{
        int con = this_player()->query("con");

      	if ( con > 29 && con < 37)
         	write("�A�����l�F�l��A��M�Pı��᭻�������a���Ѹ{���C���D���X�O�q����Ӫ��C\n");      
      	if ( con > 36 )
         	write("�A�����l�F�l��A��M�Pı��᭻�������a���Ѹ{���C�n���O�q�K�����䪺�|�l�ƨӪ��C\n");       
      	if ( con < 30 )
         	write("�A�����l�F�l��A���O��ڪ��᭻�A�A���־K�F�C\n");                     
       	return 1;        
}

int valid_leave(object me)
{        
       me->delete_temp("backyard_climb");
       return ::valid_leave(me);
}