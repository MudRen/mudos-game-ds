// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�\\�U�A�ȥx"NOR);
	set("long", @LONG
��������^�R���䤤�A�n���H�K�ߡC���ɪ���^�ϧA���جy�s�Ѫ�
�����C��W���F�@�T���e(picture)�A�Z�j�i���C�A�ȥx�W�����¦⪺��
�ت�(note)�C�p�G�ݭn�i�H�ЪA�ȤH�����A�A�ȡC
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room108",
	    "south": __DIR__"room109",
	    "west" : __DIR__"room080",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

