#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A�{�b�Ө�F�_�A�L���`�B, �o����S������F��, 
�u����Ǫ����O, �M���W���X�ڤp��, �e��ݰ_�Ӫh��
�ܭ�, �i��֨�h�A�a�a�F, �o�����@�����F�詵���U
�h�C
LONG
    );
 
 set("exits",(["west":__DIR__"en7",
               "east":__DIR__"en19",
             ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
