// qianting.c �e�U
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�e�U");
	set("long", @LONG
�o���O�j�Ӫ��e�U�A���K�K���A�A�X�G���\�]�ݤ��M�C���a�j�U
����������W�a���ۤ@���]���]�A�M�g�X�H�H�������C�U�W���O�Ѻ�
�j���۬W�䦨���A�W�����G�ټg�ۤ@�Ǥ���r(word)�A���t�����O��
���ⵧ�C�i�A���J�Ӭݫ�\�]�ݤ��M���C
LONG	);
	set("item_desc", ([
		"word": "��������ɬ��� �ܻT�p���h�p��\n"
	]));
	set("exits", ([
		"west"  : __DIR__"mudao02",
//          "east"  : __DIR__"mudao05",
		"south" : __DIR__"mudao04",
		"north" : __DIR__"mudao01",
	]));

	setup();
	replace_program(ROOM);
}

