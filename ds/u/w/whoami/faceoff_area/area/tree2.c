#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�˪L");

 set("long",@LONG
�q���B�b���F���N��i�F�˪L���`�B, ���̰��F�ѱ��𤦤@
�������Ī̥H�~, �N�u���@�Ǥp�ʪ���b����, �䥦�p�y�����
���b���B�N���^�Y���F, �A�ݤF�@�ݥ|�g, �o�{�F�@���˦b���
���i�ܵP, �]�\���໡�������򴶳q�H���즹�N�^�Y..
LONG);
 set("item_desc",([
        "�i�ܵP":"�A�o�{�W�����r�]�����j�B���ӵL�k��{�M��
�A��������: ���n.....�e��.....�ѱ�.....�~....�i�i�J.......
�_....��. �z! ���ݤ��M�F....\n"
    ]));

 set("exits",([ "north":__DIR__"tree3",
                "south":__DIR__"tree1",
                "northwest":__DIR__"tree8",
    ]));
set("no_clean_up",0);
set("outdoors","forest");
 setup();
 replace_program(ROOM);
}

