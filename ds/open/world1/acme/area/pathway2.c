// Room: /u/a/acme/area/pathway2.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�O�@�����ѫ��_�誺�p���A�o�̪������F�_�����ӥh�A�i�q����
���A�n��O���ѫ��̼��x�������C�o���p���O�H�Pı�Q���M�s�A�p������
�ǥͪ��۰��j���ѪQ��A���ɶǨӤp������s�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ndoor.c",
  "south" : __DIR__"pathway1",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
