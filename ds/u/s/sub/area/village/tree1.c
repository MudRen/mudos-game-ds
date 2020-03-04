// Room: /u/s/sub/area/village/tree1.c

inherit ROOM;

void create()
{
    set("short", "���줺��");
	set("long", @LONG
�o�̬O�����F����賡�A�ѩ�����a�Q���ư٭��A�{�b�w�g�ܦ���
�Ū��C�|�P�۷��e���A�j���i�e�ǤQ�h�ӤH�A�]���|ı�o�����C�]����
�F�W���ǯ}�l�A�ҥH���@���������u�Ӯg�i�ӡA�ϱo�o�̥R���F�w�����R
����^�C
LONG
	);
       set("item_desc",([
  "���" : "��F�W���G���ۤO�I�i�H�V�W�k��(climb up)�C\n",
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : "/u/s/sub/area/valley/map_1_2.c",
]));
	set("world", "undefine");
	set("current_light", 1);
    set("objects",([
        __DIR__"npc/village_ant_5" : 3,
    ]));

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
        if(!arg) return notify_fail("�A�n�����̪��H\n");
        if (arg != "up") return 0;
        
        message_vision("$N����۾�F�A�C�C�a���W�k���C\n" ,me);
        me->move(__DIR__"tree2");
          tell_room(environment(me),me->query("name")+"�ܯT�V�a���F�W�ӡC\n",me);
        return 1;
}
