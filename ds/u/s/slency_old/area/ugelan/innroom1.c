// Room: /u/s/slency/area/ugelan/innroom1.c

inherit ROOM;

void create()
{
	set("short", "�ȩ�");
	set("long", @LONG
�o�̬O�@�����q���ȩСA��W���@�����Τ@�Ǥp�I�ߨѩЫȭ̭���
�A�̭��٦��@�Ӥj���E�A�ݰ_�ӬX�n�S�ΪA�A�A���T���I�r�}��b�o��
���ȫȭ̥i�H���p�����ɨ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
