// Room: /open/world1/tmr/frost/depositary3f.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�øg�դ���");
        set("long", @LONG
�h�ƹD�Юc�[���ؿv���ǲΪ��쵲�c�ؿv�A�Y�H��[�����F�A�����
�j��A�Υ˻\�γ��A������j���ȧ@�����~���j���ΡA���t�γ����q�C��
�øg�իh�O�ݩ�o���ؿv�A�Ӱ��C�h�A�îѸU���A���[�����D�n�ؿv���@
�A���`�O����~�H���N�i�X�C�ӳo��O�øg�ժ����ӡC
LONG
        );
        set("current_light", 3);
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/dragon-tiger" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"depositary4f",
  "up" : __DIR__"depositary6f",
]));

        set("objects", ([ /* sizeof() == 1 */
		  __DIR__"npc/dragon-elephant" : 1,
		  __DIR__"npc/bird-elephant" : 1,
		  __DIR__"npc/turtle-elephant" : 1,
		  __DIR__"npc/tiger-elephant" : 1,
		]));

        setup();
}


int valid_leave(object me, string dir)
{
		object g;
        ::valid_leave();
   
        if( dir == "up" ) {
				g = present("5f_guard", this_object());
				if( objectp(g) )  {
    	            message_vision( "$N"NOR"�צb�ӱ�f�e�A����$n"NOR"�W�ӥh�C\n", g, me);
	    	        return 0;
    			}
        }
        return ::valid_leave(me,dir);
}

