//u/c/chiaa/world2/blackly_forest/forest_entranceway.c

#include <ansi.h>   

inherit ROOM;
void create()
{
        set("short", "�˪L�J�f�B");
        set("long", @LONG
�o�̬O�·t�˪L���J�f�B,���u�ϩ��Ӥ��i�˪L�̭�,
�ϤH�����ΪA���Pı,�]���H���ͬO���O�Ӧ^�Y���Q�k!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east"       : __DIR__"road2",          //�L���p��2
  "west"       : __DIR__"stream_road",    //����p��

]));
       
            setup();
replace_program(ROOM);
}

