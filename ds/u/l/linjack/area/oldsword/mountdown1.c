#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D�����Y");
 set("long",@LONG
�A���e���D���N�즹����F, �e���O�@���Z�K���˪L,
�����D�̭��æ�����M��, �p�G�A�O�n�W�V����, �i��
�٦��@�q�ܪ������n��.
LONG
    );
 set("exits",([ "southeast":__DIR__"mountdown2",
                "northup":__DIR__"forest9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}