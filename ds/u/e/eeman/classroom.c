inherit ROOM;

void create()
{
        set("short", "�O����");
        set("long", @LONG
�o�̬O�O����, ���˪��ǥͥi�H��o�̨ӱ����v��
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
	"up"	:	__DIR__"workroom",
	]));

        set("light", 1);

        set("no_clean_up", 0);

        setup();
}

void init()
{
	add_action("do_join","join");
}

int do_join()
{
	object me;
	me = this_player();

	if(me->query("class"))
		return notify_fail("�A�n�����A�X�����\n");
	write("�w��"+me->query("name")+"���V��ͤ���\n");
	me->set("class","doctor");
	return 1;
}