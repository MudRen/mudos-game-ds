#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"���r���E"NOR);
        set("long",@LONG
�o�O�@�a���E�A�b���E������A�A�ݨ�F�\�\�h�h���o�󪫩M�@��
�����A���G���O���Ө���A�����٦��@�Ӥp�p������A�̭����G�O��
�ۤ@�ǶQ�������~�A�b���E�e�����ӤH�b�w�۵o�b���A���F�䨫�N�O�B
�F�����_��C
LONG
        );
        set("objects",([
  __DIR__"npc/shopman.c":1,
]));
        set("exits",([
  "east" :__DIR__"bnorth3.c",
]));
        set("no_clean_up",0);
        set("light",1);
        setup();
}
