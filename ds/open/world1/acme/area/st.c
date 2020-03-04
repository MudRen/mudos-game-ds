// Room: /u/a/acme/area/st.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�A�����b�@���e�s����D�A���i�e��������þr�Ӧ�C�o�̤H�n���m
�A�������s�A���x�D�Z�C���F�i���s���A�n��i�ݨ�@���ȴ̡A���f����
�@�i������r�۵P�A�W�Y�g�ۡu�ѭ��ȴ̡v�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street2",
  "south" : __DIR__"hotel.c",
  "east" : __DIR__"plaza",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
