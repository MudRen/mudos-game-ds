inherit ROOM;

void create()
{
	set("short", "�˪L�`�B");
	set("long", @LONG
�g�L�������@�q���A�ש󨫨�˪L���`�B�F�C�b�o�̥i�H������
�����P����o���˪L�������ӵL�a�L�ɪ��ͩR�O�C���L�ӷP���A���G
�Pı��b�o���񦳤@�ѤQ���j�j���O�q�A���O���ѤO�q�Pı�D�`�ũM
�A���a������ķN�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"path3",
  		"north" : __DIR__"path5",
	]));

	setup();
	replace_program(ROOM);
}
