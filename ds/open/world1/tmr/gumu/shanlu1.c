// shanlu1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o���s���L�۲׫n�s�D�p�ӤW�A�s���K�ۥ��z�w�X�A�u�e�\�@�H�o
�L�A�ζշ����I�m�C�����B��h�C�s�s��¶�A�C��}�U�A�ʨ������ɦ�
�����A�y�ɥO�H����~�n�A�Q�n���S�@�n�C���n�U�O�@���Ŧa�C���_�W
�N�O�׫n�s�D�p�C
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"southdown" : __DIR__"kongdi",
		"northup"   : __DIR__"zhufeng",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

