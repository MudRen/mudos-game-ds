#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�j�T��");
 set("long",@LONG
�A�{�b���m����@�y�j�T�Ϊ������A�ݤF�@���W�����H�A
�~���D��ӳo�O�v�ڪ����a�A�]�N�O�W�@�N�����l�A�b�ʫ�
���������A�v�ڪ����v�O�۷��a��x�A�o�]�N�O������
�Ʀ~�ӭ]�a���l�רS���]�m��������]�F.
LONG
    );
 set("exits",([   "west":__DIR__"ten18",
    ]));
set("objects", ([__DIR__"npc/meo_chung" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

