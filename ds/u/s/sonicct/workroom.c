#include <ansi.h>
inherit ROOM;

void create()
{
 set("short", HIC"�������a"NOR);
	set("long", @LONG
�A�ݨ�@�ӫܩ_�Ǫ��ж��A�b��W�A�o�{�ܦh�ȱi���g��
�u�[�o!�V�O!�v���r�y�C �b�A���F���O�q���ǡA�A�n��ť�쯺�n
�q�q���ǶǥX�ӡA�߷Q�٬O���I���}����n�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "mulder" : "/u/m/mulder/workroom",
  "east" : __DIR__"workroom2",
"naboo" : "/u/m/mulder/area/naboo/middle",
]));
        set("objects",([
        "/u/s/sonicct/test/warrior.c":1,
        "/u/s/sonicct/test/berserk":1,
        "/u/s/sonicct/test/mage":1,
"/u/s/sonicct/test/Angel/seraphim":1,
        ]));

        set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();
        call_other("/obj/board/sonicct_b","???");
                replace_program(ROOM);
}
