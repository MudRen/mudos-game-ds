inherit ROOM;

void create()
{
        set("short", "保健室");
        set("long", @LONG
這裡是保健室, 受傷的學生可以到這裡來接受治療
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
		return notify_fail("你好像不適合當醫生\n");
	write("歡迎"+me->query("name")+"走向醫生之路\n");
	me->set("class","doctor");
	return 1;
}