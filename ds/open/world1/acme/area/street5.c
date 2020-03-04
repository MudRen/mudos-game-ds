// Room: /u/a/acme/area/street5.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̬O���ѫ����F��A���F��ݥh�i�ݨ�@�Ӱ��j�������A���F
���h�i�X�ѫ��A�]�ѫ����t���o�i�A�ϱo���Ӥѫ��������W�h�F�A�d�g
�a�W�`�`����F�@��������������C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street4",
  "south" : __DIR__"bank",
  "east" : __DIR__"edoor",
]));
	set("no_clean_up", 0);
        set("outdoors","land");
	setup();
	replace_program(ROOM);
}
