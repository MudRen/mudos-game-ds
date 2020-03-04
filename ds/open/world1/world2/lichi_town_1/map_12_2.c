inherit ROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG
          [1;33m�o�̦��ʫD�`�j����A�P��L���𦳨Ǥ��P�C[0m
LONG
);
	set("item_desc",([	
	"tree" : "�o����Q�����j�A���G�ä�����(climb)�C\n",
	])	);
	set("exits",([
	"east" : __DIR__"map_12_3",
	"south" : __DIR__"map_13_2",
	"north" : __DIR__"map_11_2",
	"west" : __DIR__"map_12_1",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me;
	me=this_player();
	if(!arg) return notify_fail("�A�Q������H\n");
	if(me->is_busy()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
	if(arg=="tree" || arg=="��" || arg == "�j��")
	{
		message_vision("$N�p���l�l�����W�F�j��C\n",me);
		me->move("/open/world2/lichi_town_2/map_12_2");
		tell_room(environment(me),me->name()+"���F�W�ӡC\n",({me}));
		return 1;
	}
	else return notify_fail("�o�̨S���o�ӪF��i���C\n");
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

