#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"�p���E"NOR);
        set("long",@LONG
�o�O�@�a���E, �b���E������, �A�i�H�ݨ�b���f���ⰼ, �g�ۡy������
���z, �����٦��@�Ӥp�p������A�̭����G�O��ۤ@�ǶQ�������~, �u���x�d��
���Ӥߪ���۱b�U.
LONG
        );
        set("objects",([
  __DIR__"npc/sell_man.c":1,
]));
        set("exits",([
  "west" :__DIR__"road_11.c",
]));
        set("no_clean_up",0);
        set("light",1);
        setup();
}

