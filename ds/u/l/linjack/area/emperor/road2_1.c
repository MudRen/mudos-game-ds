#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e���f");
 set("long",@LONG
�o��O�ӫ��ҰϪ��̥~��F, �g�L�F�o�Ӥe���f, �S�|�O
�a�Q���j�D�M���R���Ѫ�, ť���o�઺�n�䤣���B���@�ɤj��
�l, �����D�O�֦b��.
LONG
    );
 set("exits",([ "southwest":__DIR__"road2_2",
                "south":__DIR__"road2_3",
                "northwest":__DIR__"center",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}