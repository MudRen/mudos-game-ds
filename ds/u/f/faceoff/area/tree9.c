#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�Ѥѥj��"NOR);

 set("long",@LONG
�A�O�ɤd���U�W, �ש��b�o���ǻ���������e��, �A�ߤ�
���P�ʨϧA�X�G�n�y�U�\��, �A�|����F�沴�e������, �u����
�ڿ������, �K���a�a, �������G�z���F��, �G�M�n�@�ʯ���!�N
�b�A�ߤ����P�ʩ�o�ʯ��줧��, �A���M�|�Y�o�{��K�W���G..
....
LONG
    );
set("exits",([ "southwest":__DIR__"tree5",
    ]));
 set("item_desc",([
        "��K":"�A�|�Y�����Y�W����K, �o�{�b�ڳ����@�鲪��, 
���G���H�W�U�o�ھ�K, �A�۫H�H�A�����\\��¦, �n���W��K�ä��x��.\n"

    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_jump","jump");
}





int do_jump(string arg)
{        object me;
        me=this_player();
       if (arg != "��K") return 0;

        message_vision("�u��$N���l�@�D, ���M���W�F��K! !\n"  ,me);
       me->move(__DIR__ "tree10");
return 1;
}






