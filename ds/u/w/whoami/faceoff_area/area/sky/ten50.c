#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"���p"NOR);
 set("long",@LONG
�ǻ����p�b�C�~��V�汵���ڡA�L�a�Ŧ⪺����N���p
��������p���s����½�˦ӥX�A�b���p�W�Φ��@���~�H����
���A�ӧY�Ϥ��O���Ӯɸ`�A���p���N�h���A�b�s�W�椣�X�@
�جO�ܱ`������.
LONG
    );
 set("exits",([  "southdown":__DIR__"ten49",
                 "north":__DIR__"ten51",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

