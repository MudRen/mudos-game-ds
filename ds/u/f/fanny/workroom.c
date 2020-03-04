// Room: /u/f/fanny/workroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", WHT"�����Ъ���"NOR);
    set("long", 
    "�o�O�����Фu�@���a��A�o�̦��@����мC�A��X�س��~�Ѱs�A\n"
"�ݨӯ����ЬO�Ӱs���a�A�b�����Ъ��f�����n�n��ۥL���u�����Сv\n"
"�o�����l�A���G�ٮ���۱o��֪��C\n"
"\n"
+HIR "                    �H�������X�l�ġA\n" NOR
+HIR "                    ���D�@�G��ۻ��F\n" NOR
+HIR "                    �@�@�ۯ}���o�N�A\n" NOR
+HIR "                    �����Ф��L�H�ǡC\n" NOR
"\n"
    );
	set("exits", ([ /* sizeof() == 4 */
  "town" : __DIR__"area/town/town1.c",
  "forest" : __DIR__"area/forest/forest1.c",
  "wiz" : "/d/wiz/hall1",
  "moon" : "/open/world1/acme/area/moon/room3",
]));
	set("world", "undefine");
    set("no_clean_up", 1);
    set("no_fight", 0);
    set("valid_startroom",1);

	setup();
call_other("/obj/board/fanny_b", "???");
set("objects",([
__DIR__"box.c" :1,
]));
	replace_program(ROOM);
}
