// Write by -Alickyuen@ds-
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�Ѧa����");
        set("long", @long
�o�O�@���M�����ѵ��U�����D���@�k�𮧲�Ѫ��a��A�̭��]
�m����y�Q�תO�A�i�H���U�����p���P���ΰQ�׾ԳN�F�t�]���Z���B
����ιD�㳯�C�[�A�i�H�s�񭫭n�����~�M�Ѱ�D���@�k�̨ϥΡC
long);
        set("objects", ([
                __DIR__"item/axe2" : 1,
                __DIR__"item/heaven_box" : 1,
        ]));
        set("light", 1);
        set("no_kill", 1);
        setup();
        set("stroom", 1);
        load_object("/obj/board/sky_secret_b");
}

