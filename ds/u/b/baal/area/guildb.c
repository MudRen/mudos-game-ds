#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�۴Y"NOR);

 set("long",@LONG
�o�̪��в��K���w�R�h�F, ���A�����e����x�������æ��@��, �۴Y��
�]�D�֤F�\�h, �ѱ��в��̶}�l�w�R���që, �o��, ���A�@���R�Ī��Pı,
���A�h�֪����߱o��θ�, �A�Pı���P�F�\�h, �߱��]�S����i�Ӯɨ���C
�W�K�U�F. 
LONG
    );
 set("exits",([ "east":__DIR__"guilda",
                "north":__DIR__"guildc",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

