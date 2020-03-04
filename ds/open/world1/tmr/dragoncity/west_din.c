// Room: /open/world1/dragoncity/west_din.c

inherit ROOM;

void create()
{
	set("short", "�B�r��");
	set("long", @LONG
�o�̬O�Y�s���諰���B�r��f�C�V��@���q�V�ժ���A
�_���M�n���O�@���������C�ۤj��A�q�V�����C�F���O�@��
�W�\����[���˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"westgate1",
  "south" : __DIR__"westroad2",
  "north" : __DIR__"westroad",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}
