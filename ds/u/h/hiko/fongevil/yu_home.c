#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���T�f");
set("long",@LONG
�o�̬O�b�`�s���o�@��²��T�f�A�A���i�ӫKı�o�G�m
����²��A�ӥB�@�����F�賣�O�۵M���o���A�i�Q�Ӫ��o�̪�
�H���g�`�M�~�ɥ�y�A�𭱤W��ۤ@�Ǯ��~������A�a�W�]��
���~�ֵ������C
LONG
    );
 set("exits",([
"east":__DIR__"home_1",
"north" : __DIR__"home_3",
"west" : __DIR__"home_2",
"out" : __DIR__"mu13",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             




