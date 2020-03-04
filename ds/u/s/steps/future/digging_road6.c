// Room: /future/area/digging_road6.c

inherit ROOM;

void create()
{
	set("short", "�o���K��");
	set("long", @LONG
�A�����ۤ@���o���K���W�A�A���ɥi�ݨ줣���q�u��۫������ѡB
�K���^�q�ϡA�]�i�ݨ�I�t���K�S�B�Q�r�굥�u�㶶���K�����訫�V�q��
�C�w�o���K���Ǫ����F����A���o�a�ӤF�@����N�C
LONG
	);
	set("world", "future");
	set("outdoors","desert");
	set("no_clean_up", 0);
	set("item_desc",([
	"����":"�Ʈ�������������W������C\n",
	]) );

	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"digging_road7",
	  "east" : __DIR__"digging_road5",
	]));

	setup();
	replace_program(ROOM);
}
