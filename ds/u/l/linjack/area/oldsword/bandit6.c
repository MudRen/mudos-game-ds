#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L�����p�Ŧa");
 set("long",@LONG
�A�Ө�F�@��������m���Ŧa��, �i�O���M�Q��L��Ţ�n,
�ݰ_�ӧA�٨S�����}�o�Ӯ��ƪ��a��, �A�ߤ������}�l�q���F
�_��.......
LONG
    );
 set("exits",([ "northeast":__DIR__"bandit7",
                "south":__DIR__"bandit5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
