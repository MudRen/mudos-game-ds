#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG
�A�n���e���b�k���W���@�B�y�L�Y�X������, ��O�A�M�w
�A�{�b�Ө�F�_�A�L���`�B, �o����S������F��, �u����
�Ǫ����O, �M���W���X�ڤp��, �e��ݰ_�Ӫh��ܭ�, �i��֨�
�h�A�a�a�F, �o�����@�����F�詵���U�h�C
LONG
    );
 
 set("exits",(["west":__DIR__"en19",
               "east":__DIR__"en21",
             ]));
 set("no_clean_up", 0); 
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}           

