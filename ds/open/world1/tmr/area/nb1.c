// Room: /u/t/tmr/area/nb1.c

inherit ROOM;

void create()
{
	set("short", "�b�l���f");
	set("long", @LONG
�b�A���e�O�@�y�v��¤Ѵ򭱤W�����۾��A���f���i�۸O�C�V�_����
�A�����b�򤤦��|���y�Ъ١A�ئb�@�Ӥ����O�p�q�٬O�b�q�����a�W�C��
�F�O���j���O�A�ѩ�M�Ӫ����A���P�g�H�A�o�j�P�p���A�@���p�ߴN
�|�b�̭��g���A��a�~���]���������i�h�C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "�۸O" : "�@�i���J�Ө誺�۵P�A�W�Y�Φ���g�ۡu�b�l���v�C
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"round4",
  "northup" : __DIR__"nb2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
