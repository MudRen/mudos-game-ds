// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "�ըF�a");
set("long", @LONG
�A�����b�@���n�n���F�a�W�C�F�y�V�ӶV���F�A�|�g�]�����X�{�U�ت��� 
���ͪ��A�ӥB�F�y�W�٦��F�@�Ǥj���Y�C�|�P�٦��ǳ\�����ʹӪ��A���O�ݰ_
�Q������A�i�঳�H��z�L�C
LONG
);
set("exits", ([ 
"east" : __DIR__"sea6",
"west" : __DIR__"sea8",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
