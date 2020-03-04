// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IWest[2;37;0m");
	set("long", @LONG
�A���Y��W�ѤW�A�ݨ�ܦh���b�a���������D�W�p�L�A�N���D�L��
�ܻ��ɶ��F�C�ӧA�ۤv�N�b�o�̶��}�ۡA�A�Φۤv�F�Ӫ���ı�D�F�@�D�A
�D��@�}�ܷL�z�������A�ݨӬO�ѫܻ��ǨӪ��A�A�}�l�V�۳o�ؼжi�o�C
LONG
	);
	set("world", "future");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst14.c",
  "east" : __DIR__"dmid.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
