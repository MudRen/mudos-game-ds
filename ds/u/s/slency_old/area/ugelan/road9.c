// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�@���C�۾Q������D�A�H�s�����c���A��D�W�����֪��F�l�b�a�W
���B�A�]���ǤH���b��Ǽ��ۦ̲ɵ��F�l�Y�A��D�������Ӥp���l�A�M
�D���u���q�����_�_�X�A�Ѹ��H�Ѵ����ΡA�ѳo�̩��F���_���O�@���H
�ӤH������D�C	
LONG
);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road10",
  "east" : __DIR__"road8",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}