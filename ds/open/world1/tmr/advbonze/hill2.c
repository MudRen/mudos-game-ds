#include <path.h>

inherit ROOM;

void create()
{
        set("short", "�ⶳ�p�Фs�}�U");
        set("long", @LONG
�A�������b�@���s�D�W�A���ⶳ�p���s�}�U�A�A���ɥi�ݨ�P
�򦳤��֪��ⶳ�x�M�|���s�p�W���h�C�۶ǭⶳ�p�p���W���y�¶���
�������j����A�����Q�ƤH���A����Ф����t���A�ǻD�S����t���H
�A�ר�@�͡A�]�S�����|�ʨ����j���򹳡C
LONG
        );
        set("world", "past");
        set("exits", ([ /* sizeof() == 3 */
                "north" : __DIR__"hill3.c",
                "south" : __DIR__"hill1.c",
        ]));
        set("outdoors","forest");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


