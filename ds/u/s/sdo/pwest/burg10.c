inherit ROOM;

void create()
{
	set("short", "���~�s��");
	set("long", @LONG
�A�����b�@���s���W�A���F��ݥh�A�u���@������A������W�Y
��Ţ�n�ۿ@���A�ݨӴN��O�s�M�h�A�Q���V�g���˪L�]�O���ӥi�઺
�C�_�䪺�s�Y�W���@���x�a�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  		"northup" : __DIR__"hill1",
  		"southeast" : __DIR__"burg5",
	]));

	setup();
	replace_program(ROOM);
}
