#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
���@�y���ɦ⪺�J���q�ߦb�o�̡A�q�����~���ݨӡA��
���G�O�Ψ��ɩҥ��y�Ӧ��A�A�i�H�������ݥX���O�@������
�����������A���L�_�Ǫ��ơA���M������n���j�A���ݤW�h
�ϦӦ��@�Ѳ��M����A���G�Ʊ橹�F�e�����x���H����Ѯ�
�ɥh�A�P�ɳo�̦��@�y���P�A�]�\�A�Ӭݬݥ�....
LONG
    );
 set("exits",([  "northeast":__DIR__"ten22",
              "east":__DIR__"ten8",
               "southeast":__DIR__"ten4",
              "west":__DIR__"ten10",
    ]));
set("item_desc",([
        "���P":HIG"�W���g�� : ���� : �]�a��, ���F : �Q�U���Ѿ�\n"NOR
    ]));
 set("objects", ([__DIR__"npc/sky_guard" : 1,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
        if( dir== "west" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}

