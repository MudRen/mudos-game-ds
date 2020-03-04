// Room: /open/world1/cominging/area/survey.c

inherit ROOM;

void create()
{
	set("short", "�B�F�������x");
	set("long", @LONG
�o�̬O�B�F�����̥j�Ѫ�����x�A�b�o�̪��P��O�Ѧˤ�ҿv����
�A���G���I�e���˶򪺼ˤl�A�b�o���|�P���\�\�h�h������(windows)
�A�i�H��V�B�F�����|�P�A�b�ߤW�ɪ��]���]�i�٪��O�����@�[�A�i�]
�O�B�F�����S�O�c�a�����H�A�b����W���\�h�a�ϡA�]���\�h�H���@��
�A�ᦳ�ǷR�ꪺ�Pı�A�b�A���}�U�O�q���s�����ӱ�A���䪺��W����
�@���p�ȱ�(scrip)�C
LONG
	);
	set("god_club_enter", 1);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"survey_out",
  "down" : __DIR__"boo-lin.c",
]));
	set("current_light", 1);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/minstrel.c" : 1,
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "windows" : "�o�O�@�ӥѦ˰���������A���G�i�H�q�o���U(jump)��n�j��C
",
  "scrip" : "[1;36m�p�ȱ��W���g�ۡG
[1;32m�i�H�� singing �����ڰۨǺq���� ( talk with geisha ) �ڱN�i�D�A�ڷ|�۪��q�C
[0m",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
