#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A�{�b�Ө�F�_�A�L���`�B, �o����S������F��, 
�u����Ǫ����O, �M���W���X�ڤp��, �e��K�O�H�̱`
�`�g�����h�A�a�a�C
LONG
    );
 
 set("exits",(["west":__DIR__"en20",
               "east":__DIR__"en22",
             ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
