inherit ROOM;

void create()
{
	set("short", "�}�]��");
	set("long", @LONG
�b�A�����e�X�{�F�@�j���۾��A�۾������k���䳣���X�f�A�ݰ_
�Ӳ`�������A�����D�̭��|���Ǥ���˪��M�I�C�A���T�C�ܰ_�ӡA�{
�u��ҡG�y�ڨs�����~�򩹫e�i�A�٬O�ਭ���}�o�Ӻ��ª��}�]�H�z
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  		"northwest" : __DIR__"gcave2",
  		"out" : __DIR__"hill1",
  		"northeast" : __DIR__"gcave3",
	]));

	setup();
	replace_program(ROOM);
}
