
inherit ROOM;

void create()
{
	set("short", "�ܮw");
	set("long", @LONG
�o�Ӧa�観�I���t�A���L�ݱo���̭������ΡC�A�ݨ즳�ܦh�Τ�O
�������c�l���b�̭��A���I�äS���|�ӶáA�c�l�W���ǹФw�g�ƫp�p��
�@�h�F�A�ݨӥ��`�o�̨èS���H�ӥ�����z�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room34",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
