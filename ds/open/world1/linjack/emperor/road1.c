#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D���W");
 set("long",@LONG
�q�L�F�o�q�p��, �A�ש󨫨�j���W�ӤF, �G�M�M
�B�F�����ण�Ӥ@��. ���O�A�`�O�ݤ��칳�B�F������
���骺�H��b�o��X�{.
LONG
    );
 set("exits",([ "northeast":__DIR__"path2",
                "southwest":__DIR__"road2",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}
