#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�p�D�F");
        set("long", @LONG
�o�O�@�y�p�D�F�A�D�F�������ۮ�B�۴Ȥw�ݯ}�����A�Ӭݤ��U�A�a
�W�����M�����A�|�P���F�W�W�]���Q�L����l���貪�A�D�F����O���k
���A�o�k�����q�����A�|�����O�����ǥۡA���b�G�Q�ӤV�B������X���j
�۶��A�W�Y�����ǷL������w�N�U�ӡC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"lake-road2",
	]));
         set("item_desc", ([       
        "�k��" : "�@�����q�������A�ˤ]�����k���C\n",
        "�j�۶�" : "��X��k���W�A�ݨӭ˥i�e�U�G�B�T�H�C\n",
        ]) );

	set("outdoors","land");
	set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
 	object me;
	me=this_player();
	if (arg != "�k��") return 0;
	
        message_vision("�u��$N��B���åΡA�C�C�a���W�F�k���C\n" ,me);
        me->move(__DIR__"highstone");
          tell_room(environment(me),me->query("name")+"��ݼN�N�a���F�W�ӡC\n",me);
	return 1;
}



