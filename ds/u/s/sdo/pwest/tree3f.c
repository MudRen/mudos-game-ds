inherit ROOM;

void create()
{
	set("short", "���쪺�̳���");
	set("long", @LONG
�A�{�b�����b���쪺�̳��ݡA�o�̥R���ۨ��ѤO�q�C�A���Y�Q�W
�ݡA�o�{���@�����j�������a�B�b�b�Ť��A�ݨӨ��N�O�o�ѤO�q����
�Y�F�C
LONG
	);
	set("item_desc",([
        "����":	"�@�����j�B�����������C�n�����ǵۦۤv���O\n"
        	"�q�}�B�b�Ť�����������ۡA�åB�������V�|\n"
        	"�P����ۥ����O�q�C\n",
       	]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"tree2f",
	]));
	set("objects",([
	__DIR__"npc/treeking.c":1,
	]));

	setup();
	replace_program(ROOM);
}
