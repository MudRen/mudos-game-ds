#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�˪L"NOR);

 set("long",@LONG
�ǻ��b�o�Ӵ˪L�`�B���@�ʪQ��, ����֤w��C�d, �B���j
�L��, �����L���H�u���ѱ��𤦤@�������Ī�, ���L��k�Q����
�B�ᤣ��ѱ��𤦤@���Ӧ�, �]���o�ʰѤѥj��w�h�~���A�y��
���Ĭ�....
LONG
    );
 set("exits",([ "north":__DIR__"tree2",
                 "southwest":__DIR__"bird6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if( dir=="southwest" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
