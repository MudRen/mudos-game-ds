#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���N�t�Y"NOR);
 set("long",@LONG
�ݨӳo�����N�t�Y�w�g����Y�F, �A���T�P�F�@�f��, ���Y�W�C�@����
�N�b�A�@�i�J�L�̪����u�d��ɫK������ۧA����, �ϳo�����Y�ܪ��󤣩�
�L�F, �A���F���B�Y�W��j�����], ���S�F�@�f��, ���򩹫e���h...
LONG
    );
 set("exits",([ "south":__DIR__"guilde",
                "north":__DIR__"center4",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
