// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IEast[2;37;0m");
	set("long", @LONG
���X�F���������H�s�A�]��Ӿ���ʪ������C�o�Ӿ���ʪ���O��
�s�}���A�o��O�@�ɲĤ@�ӯ���c�޾����d�����ʪ���A�i��O�@�Ӥj��
���p���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst12.c",
  "east" : __DIR__"door",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
