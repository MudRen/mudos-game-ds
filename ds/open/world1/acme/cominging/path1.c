inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�o�̬O���D���}�ݡA�p�G�A�@�����_���A�g�L�@�Ǹ��A�N�|���F�F
���ӷݪ��Ű�A�̭����\�h���@�áA�o�䪺���D���G�j�F�\�h�A����]
���\�h���ж��A�a�O�����X�{�X�ӯ}�}�A�i�H�ݪ����U���n���I�ۨǰs
�A�j���O�p�l�x�_�ӥH�ƥH�ᤧ�ΡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path9",
  "west" : __DIR__"path6",
  "north" : __DIR__"path2",
  "south" : __DIR__"yidoor",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
