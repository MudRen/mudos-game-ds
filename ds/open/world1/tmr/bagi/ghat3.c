// Room: /open/world1/tmr/bagi/ghat3.c

inherit ROOM;

void create()
{
	set("short", "�s�D�e�f");
	set("long", @LONG
�A���B�b�@�B�s�D�e�f�A�s�D���F�_�B��_���F�G�����A���f�B����
�F�@���ܸy�����C�۸O�A����n�������L�ɪ��ˤl�A��۳o�@���կ��
���a�A�ߤ��_�F���檺�Pı�C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "�۸O" : "�A���}�F�۸O�W�Y���n���A�X�{�F�@��r�G�u�F�q�N��A�詹�H��C�v
",
]));
	set("outdoors", "snow");
	set("current_light", 1);
	set("no_clean_up", 0);
	set("world", "past");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"ghat2",
  "northwest" : __DIR__"ghat5",
  "northeast" : __DIR__"ghat4",
]));

	setup();
	replace_program(ROOM);
}
