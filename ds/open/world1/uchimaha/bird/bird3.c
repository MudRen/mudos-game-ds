#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�S�L�F���֮ɶ�, �Aı�o�o�Ӯk��������H, ���O
���`�H�үદ�W�Ӫ�, �A���n�_�ߤS�[�`�F�@��, �쩳
�b�o�k�����W������F��, ���O�A�����ߤߤ]�[�`�F�@
��, ���Ӫ��S���H�쩳�O�֩O?

LONG
    );
 
 set("exits",(["up":__DIR__"bird4",
               "down":__DIR__"bird2",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
