inherit ROOM;
void create()
{
          set("short","�K������");
          set("long",@LONG
�ߤ@�@���q���D�����K���N�O�ة�o�Ө����̭��A�C�ѳ����ܦh�f��
�M�H�̳��g�o�̩��ӡC�i��ѩ�f�~�j�h�H�q�����D�A�ϱo�o�̦��@�ǸH
�����q���b�a�W�A�ӳq�L���H��F�U�h�A�ϱo�a���H�W�F�q������m�C
LONG
           );
	set("exits", ([ /* sizeof() == 1 */
          "westdown" : __DIR__"digging_street4",
	]));
	set("objects",([
          __DIR__"npc/driver":1,
	]));
	set("no_kill",1);
        set("outdoors","desert");
            set("world", "future");
	set("no_magic",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg != "train") return 0;
	if(!me->query_temp("do_train") ) return 0;
	me->move(__DIR__"train");
	me->delete_temp("do_train");
	tell_room(environment(me),"$N���i�F�K���C\n",me);
	return 1;
}
