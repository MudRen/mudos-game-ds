#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���_��");
        set("long", @LONG
�o�̬O�a�U�������Y�A�b��D���k�䦳�@�a�𬣽��ת���a�A���o
���@���j�����A��ӬO�����j�W���S��D�㩱�A�n��O���a�U�����n��
�D�����A�Ӧb�_��h�O�@�����j������A�b�W�����@�ǯʼw�ȫȪ��y��
�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec11.c",
     "east":__DIR__"house.c",
     
]));
        set("light",1);

        setup();
        replace_program(ROOM);

}
