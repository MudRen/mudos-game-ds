#include <room.h> //�n�[���n�o�@��
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�j�c��");
	set("long", @LONG
�A���B�b�j�c���A�j�c�̿O�����t�A�b�A���䦳�ӵ��ǤH�ѸT��
�p�|�}�A���ɪ��ǨӴc�䤧���A�\�h�����b��W���A�a�W�٦��ѹ��b
�٭��ۥǤH�Y�Ѫ��C�Y�C�b�o�����Ҹ̡A�A���T�ĹD�G�٬O���n�Ǹo
���n�I
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"jail4",
]));
set("objects",([
    __DIR__"npc/mouse": 3,
    __DIR__"npc/prisoner" : 1,
]) );
     set("item_desc", ([ /* sizeof() == 1 */
       "���i" : "�o�����i���|�\\�b�𨤡A�Q���j�ǡA�A�i�H�յ����(roll)���C\n",
       "�|�}" : "�o�ӧ|�}�S��Sż�A��F����j���u���ݦ�b�o�̪��}�Ǥ~���D�C\n",
     ]));
	 set("no_recall",1);
	set("no_clean_up", 0);

	setup();
	create_door("north","�c��","south",DOOR_LOCKED,"jailkey");
}
void init()
{ 
         add_action("do_dig","dig");
         add_action("do_roll","roll");
}

int do_dig(string arg)
{
	object me;
	me=this_player();
	if(arg != "�|�}") return 0;
	if( me->is_busy() ) return notify_fail("�A���ʧ@�٨S�������M���వ�ʧ@�C\n");
	else {
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		me->start_busy(2);
		return 1;
	}
}

int do_roll(string arg)
{
	object me;
	me=this_player();
	if( arg != "���i" ) return 0;
	else {
		if(me->query_temp("SKYCITY/shout")>1)
		{
			message_vision("$N�����a��ʵ����i�A��M�a�O�S�X�F�@�Ӧa�D�A$N�^�i�a�D���C\n",me);
			me->move(__DIR__"injail2");
			me->delete_temp("SKYCITY/shout");
		}
		else {
			message_vision("$N�����a��ʵ����i�A���O�@�I���R�]�S���C\n",me);
		}
	return 1;
	}
}
