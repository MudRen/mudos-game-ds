//trans1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ڤ۶ǰe��");
	set("long", @LONG
�b�o�ӹڤ۶ǰe���A�A�i�H�N�A�ۤv�����鵲�c���s���ѲզX�A�ӱN
�ۤv�ǰe�쥼�Ӫ��ɪŤ����A����W�٤@�Ӥ��i(post)�A�b�@�Ǧ��@�x�e
�j������(machine)�A�ݨӦn���O�ǰe�Ϊ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
        "down"     :   __DIR__"tree.c",

	]));
	set("item_desc", ([
	  "post" : 
"
        ================================================
         	�Y�n�N�ۤv�ǰe��L�h���ɪŤ����A��
		�N�A���q���ҥ浹�u��(show)
		�쥼��  show card1
		��{�b  show card2
		��L�h  show card3
	================================================
",
	"machine" : "�o�O�@�x�ɥ��ǰe���C\n",
	]) );
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_cast", 1);
	setup();
}

void init()
{
	add_action("do_show", "show");
}

int do_show(string arg)
{
	object me, ob;
	me = this_player();

	if( arg !="card1" && arg !="card2" && arg !="card3")
	return notify_fail("�A�n���X����???\n");

	if( arg == "card1")
	{
	ob = present("feature card", me);
	if(objectp(ob)==1)
	{
	message_vision("\n"
+ HIW"		$N�N"HIY"���ӳq����"HIW"�浹�u��...\n"NOR
+ HIW"			�u�æb���ҫ�ñҰʶǰe����...\n"NOR
+ HIW"		�@��j�P��"HIC"�ť�"HIW"�N$N�]��A\n"NOR
+ HIW"			���u������A$N�]�H�ۤ����F...\n\n\n"NOR,me);
	me->move("/open/world2/anfernee/start/login");
	destruct(ob);
	return 1;
	}
	else return notify_fail(HIW"���ӳq���ҩO??\n"NOR);
	}
	else if ( arg == "card2")
	{
	ob = present("recent card", me);
	if(objectp(ob)==1)
	{
	message_vision("\n"
+ HIW"		$N�N"HIY"�{�N�q����"HIW"�浹�u��...\n"NOR
+ HIW"			�u�æb���ҫ�ñҰʶǰe����...\n"NOR
+ HIW"		�@��j�P��"HIC"�ť�"HIW"�N$N�]��A\n"NOR
+ HIW"			���u������A$N�]�H�ۤ����F...\n\n\n"NOR,me);
	me->move("/open/world2/anfernee/start/login");
	destruct(ob);
	return 1;
	}
	else return notify_fail(HIW"�{�N�q���ҩO??\n"NOR);
	}
	else if( arg == "card3")
	{
	ob = present("past card", me);
	if(objectp(ob)==1)
	{
	message_vision("\n"
+ HIW"		$N�N"HIY"�L�h�q����"HIW"�浹�u��...\n"NOR
+ HIW"			�u�æb���ҫ�ñҰʶǰe����...\n"NOR
+ HIW"		�@��j�P��"HIC"�ť�"HIW"�N$N�]��A\n"NOR
+ HIW"			���u������A$N�]�H�ۤ����F...\n\n\n"NOR,me);
	me->move("/open/world2/anfernee/start/login");
	destruct(ob);
	return 1;
	}
	else return notify_fail(HIW"�L�h�q���ҩO??\n"NOR);
	}
}
