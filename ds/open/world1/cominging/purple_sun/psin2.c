inherit ROOM;

void create()
{
	set("short", "�s�Ǵ˪L");
	set("long", @LONG
�A���b�o��ݨ�P��𪺾�W�観�ǰO���A�j���O���򤤪��H�h�e
�Ӥs�W�h�M�䦳���Z�\�K�ޤ��Ʈɩҿ�d�U�Ӫ��O���A�b�O�����w���X
�������@��p��ܥ~�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"psin4.c",
  "south" : __DIR__"psin3.c",
  "east" : __DIR__"psin.c",
    "north" : __DIR__"psin_forest2.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("item_desc", ([
  "�O��" : "�@�Ӥj�j���O���C\n\n"
"            ��\n"
"          ������\n"
"         �� �� ��\n"
"            ��\n"
"       ������������\n"
"       ��        ��\n"
"       ��   ��   ��\n"
"       ��        ��\n"
"       �� ��  �� ��\n"
"       ��        ��\n"
"       ������������\n"
" �����D�N��ۤ���N�� �I\n",
]));

	setup();
	replace_program(ROOM);
}
