#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"�溸���Ե�"NOR);
        set ("long", @LONG
���}�F�}�����j�D�A�o�̵y��N�M�A�A������h
�A���@�a�A�ȳB�A���G�ണ�ѵ��A��������W�s�x�Ϊ�
��Ƴ�!
LONG);
        
        set("exits", ([
        "west" : __DIR__"dragon6",
        "east" : __DIR__"dragon2",
         ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}    
