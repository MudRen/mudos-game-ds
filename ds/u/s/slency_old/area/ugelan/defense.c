// Room: /u/s/slency/area/ugelan/defense.c

inherit ROOM;

void create()
{
	set("short", "���㩱");
	set("long", @LONG
�o�̬O�@���M���@�޵����@�˳ƪ��ө��A��W���۬·㺡�ت��@��
�A�A�i�H�M���ať��Ϋ�V���M�K���n���A�o�̪��ͷN�Q�������Ať��
�o�̩ҥX�����@�㤣�ȫ~���u�}�A�B����X�z��A���n�i�H�^���D�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
