#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
����o��O�@�ӪŶ��e�s���ӫǡA�A�j�j����ߤ������w�A�C�C
�a�f���|�P�|�P�e�{��Ϊ���W�ŵL�@���A����������A�A�ߤ��@��
ı�o���ΪA�A�P���ڡA�g���A�Ʀܥ۶������G���|���Aı�o���O��
�]���V�ۧA�����ӨӡC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/helmet-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

