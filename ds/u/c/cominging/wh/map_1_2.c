inherit ROOM;
void create()
{
	set("short", "�۾�");
        set("long", @LONG

�A�Ҩ����O�@�����j���۾�, �۾��W�観�۳\�h�H��, ���G�O�b�y�z��
�@��j��, ���G�b�۾��Ǧ��Ӫ����êK���p�}(hole)�C

LONG
);
	set("exits",([
  "west" : __DIR__"map_1_1",
  "east" : __DIR__"map_1_3",
  "south" : __DIR__"map_2_2",
]));
	set("item_desc", ([
  "hole" : "�j���e�Ǫ��U�@�ӤH�j�p���}, �A�i�H���յ�(enter)�i�h�C\n"
]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if( !arg || arg != "hole" )
		return notify_fail("�A�Q�n�i�h���̧r�H\n");
	if( me->query_temp("invis") < 2 )
		message_vision("$N�Y�ۨ��l, ���p�}�̭��p�i�h�F�I\n", me);
    me->move(__DIR__"wh_1.c");
	if( me->query_temp("invis") < 2 )
		message_vision("�u��$N�q�}�~�p�F�i�ӡ�\n", me);
	return 1;
}
