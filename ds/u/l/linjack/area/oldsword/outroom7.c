#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�Q���W");
 set("long",@LONG
�o���Q���e�Ȩ��, �Q����í�T, ��÷�M��O�w�g�ᬰ
���ª��F, �p�G�b�o�W�����Ӥj���ʧ@���Ⱦ��|�伵����.
LONG
    );
 set("exits",([ "west":__DIR__"outroom4",
                "east":__DIR__"outroom8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}