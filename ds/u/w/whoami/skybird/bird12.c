#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�۫F"NOR);

 set("long",@LONG
��ѱ��J��аȤW�ΪZ�\�W�����D�ɡA�K�|�b���i�}�|ĳ�A 
���A�����e�N���X�Ӥѱ��̤l���b�Q�פ@�����D�A�A�i�H�ͫeť
�ݬݥL�̦b�Q�פ�����D�A���L�A�@�w�n�����A��A�ѱ��i����
�w���H���[�L�̡E
LONG
    );
 set("exits",([ "southeast":__DIR__"bird10",
    ]));
 set("objects", ([__DIR__"npc/chiang_chin_liu" : 1,
                  __DIR__"npc/bird_apprentice" : 3+random(2),
    ]));
set("light",1); 
set("outdoors",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}

