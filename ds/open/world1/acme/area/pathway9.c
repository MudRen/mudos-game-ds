// Room: /u/a/acme/area/pathway9.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�A�����b�p�Y�����A���B�j���}�}�A���ɪ����_���F�A�A�o�{�b����
���ۤp�p���i�ܵP�A���W�Y�o�G���F�p�p�����F�A�u�Y���Y�{���@���X��
�ӲӤp�p���r�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"pathway8",
  "east" : __DIR__"hills",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

     set("item_desc", ([
        "�i�ܵP" : "�W�Y�����i�ݨ�|�Ӥj�r�y�p�߬y�F�z�A�p�J�y�F���W��(jump up)�C\n",
     ]));
	setup();
	replace_program(ROOM);
}
