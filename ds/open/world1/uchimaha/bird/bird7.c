#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�ש��F�k�����W�F, �A�ݤF�ݥ|�P, �ä��O�A
�Q���������˯��Z��, �ϦӦ��I��D, �N�b�A���椧
��, �Ať��b�F�䦳�H�m�Z���n��, �A��Ҩ쩳�|�O��
�O?  

LONG
    );
 
 set("exits",(["east":__DIR__"bird8",
               "down":__DIR__"bird6",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
