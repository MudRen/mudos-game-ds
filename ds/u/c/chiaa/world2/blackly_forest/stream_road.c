//u/c/chiaa/world2/blackly_forest/stream_road.c

#include <path.h>    //�p�|�q�D

inherit ROOM;
void create()
{
        set("short", "����p��");
        set("long", @LONG
�A���@���u�ۤp�˪��D��,���y���,���ɥi�ݨ�ά�������b�������,
�٦��X�Ӥp�Ĥl�b�˸��������A�A���F�䨫�h�N�O"�·t�˪L"�F!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east"  : __DIR__"forest_entranceway",     //�˪L�J�f�B
]));
       
            setup();
replace_program(ROOM);
}

