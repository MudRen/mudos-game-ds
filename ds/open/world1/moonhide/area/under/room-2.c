#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
��W�_�X�@�}�H�C�⪺�����A�b�a�O�ƹL���J�t�@�䪺�𤤡A��
���ٺw�۲ӲӤp���A�s���ۥj�Ӫ��x�����A�����ٷ|�ǨӰ}�}���༲
���������n�T�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room2",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/cloth-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


