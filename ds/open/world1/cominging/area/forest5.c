#include <path.h>
inherit ROOM;
void create()
{
        set("short", "�˪L��");
        set("long",@LONG
�o�̬O�˪L�������@���p���A�b�o�̤������\�\�h�h�����ͰʴӪ��A
�]���Ǫ��C��D�`���A�A�A�ݨӬO�اt�@�r���F��A�F�_�䦳�@���Ŧa
�A�����ܥR�����ˤl�C
LONG
        );
        set("exits", ([
  "southwest" : TMR_PAST+"area/city-door.c",
  "northeast" : __DIR__"forest4.c", 
  ]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

