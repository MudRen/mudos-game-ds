#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�N���O�D�h�찭�����`�@�ˡA�o���K�Ǩ�B���K���F�ũG�A�S��
�n����o�䪺���ǡA���O....���G�n���S������γB�A�A�٬Oı�o��
�F��@���b�A�����k�L�ۡA��𤣪����h�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room3",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/cloak-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

