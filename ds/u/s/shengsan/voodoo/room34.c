
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�̬O�@�����Y�A���B���B�B���γ��A�b�A���F��O�@�y�ܮw�A��
�b�A������O�q���Ҥ��Фαоª����D�A�n��N�O���F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room36",
	    "west" : __DIR__"room35",
	    "south": __DIR__"room33",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
load_object("/u/p/pudon/war2/tfighter");  
load_object(CLASS"fighter/soul");
	replace_program(ROOM);
}
