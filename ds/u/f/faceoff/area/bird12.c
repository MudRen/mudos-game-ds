#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�۫F"NOR);

 set("long",@LONG
��ѱ��J��аȤW�ΪZ�\�W�����D��, �K�|�b���i�}�|ĳ
, ���A�����e�N���X�Ӥѱ��̤l���b�Q�פ@�����D, �A�i�H��
�eť�ݬݥL�̦b�Q�פ�����D, ���L�A�@�w�n�����A��, �ѱ�
�i�����w���H���[�L��!
LONG
    );
 set("exits",([ "southeast":__DIR__"bird10",
    ]));
 set("objects", ([__DIR__"npc/chiang" : 1,
                  __DIR__"npc/bird_apprentice" : 3,
    ]));
set("light",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}
