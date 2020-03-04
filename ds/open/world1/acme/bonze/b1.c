// Room: /open/world1/acme/bonze/b1.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�A���i�@�B�H�Ϩu�ܪ��s�D���A�|�襪�k���O�����θy������A
�B���F���u�A�]���פF�A��i�����u�F���U�|�g�A�A����ı�a�����x
Ÿ����A�ϩ��b���ê����O���A���F��b�s���A���@�|�@�ʡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"b2",
"northwest" : TMR_PAST"area/lake-road3",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
