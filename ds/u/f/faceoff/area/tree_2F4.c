#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��K");

 set("long",@LONG
�o�̬O���Ѥѥj��W�����h��K���@, �ӳo�Ǿ�K���j
�쨬�H�Ө��A�����q, �ҥH�A�i�H�樫�b�o�W���Ӥ��ξ�߷|
�L��U��, �A�V�O�V�e���V�o�Ӥj�۵M�γy���D�ҳгy�����
�g�c, �V�O�P��A�g�����i��.....  
LONG
    );
 set("exits",([ "west":__DIR__"tree_2F1",
                    "east":__DIR__"tree_2F1",
                 "north":__DIR__"tree_2F5",
                 "south":__DIR__"tree_2F1",
    ]));

 set("no_clean_up", 0);
set("no_map",1);
 setup();
 replace_program(ROOM);
}
