#include <room.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","���㪺�p��");
 set("long",@LONG
���L�F�B�F�����~�@�p�q���@������, �A�Ө�F�@�B�ᬰ
���ê��p��, ���L�J���[��P��A�N�|�o�{�o�����������ӫ�
�e��, ���ӬO�]���D�`�[�o�䳣�H�Ϩu��, �~�|�ɭP�o���ܦ�
�o�ˤl��.
LONG
    );
 set("exits",([ "northeast":COMINGING_PAST+"area/river7",
                "southwest":__DIR__"path2",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}
