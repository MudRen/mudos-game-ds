// Room: /d/cham/trans.c
#include <path.h>
#include <ansi.h>
#define SendData "/u/s/shengsan/mine/senddata"

inherit ROOM;

mapping *senddata;

void create()
{
	set("short", HIC"�ŤѶǰe��"NOR);
	set("long", @LONG
�o�̬O�ǰe�ܦU�u�|�J�f���ǰe���A��W�K�F�@�i���i(note)�C
�A�ݨ�e�観�@�Ӷǻ��������i��e���C
LONG
	);
	set("exits", ([ /* sizeof() == 7 */
		"south": __DIR__"room01",
            ]));
	set("no_clean_up", 0);
	set("light",1);
        set("item_desc",(["note" :@LONG
�ǰe���ϥλ���:

	list		�C�X�i�H�ǰe���a�I�ΥN�X
	send �N�X	�ǰe��N�X�ҫ��w���a�I

LONG
]) );
	setup();
}

void init()
{
	add_action("show_sendlist","list");
	add_action("do_send","send");
}

int show_sendlist()
{
	int i,j;
	string address,comm,list;
	senddata = NATURE_D->read_table(SendData);
	if(!senddata) return notify_fail("���J�ɮץ���!!\n");
	list  = "��������������������������������������������������������������������������������\n";
	list += "���s����    �a       �I     ��           ²                   ��              ��\n";
	list += "��������������������������������������������������������������������������������\n";
	for(i=0;i<sizeof(senddata);i++)
	{

		address = senddata[i]["address"];
		comm = senddata[i]["comm"];
		list += sprintf(" (%3d ) %-22s%-48s\n",i,address,comm);
	}
		this_player()->start_more(list);
	return 1;
}

int do_send(string arg)
{
	int num;
	string locate;
	object me;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("���O�榡: send �N�X\n");

	senddata = NATURE_D->read_table(SendData);
	if(!senddata) return notify_fail("���J�ɮץ���!!\n");

	me = this_player();
	locate = senddata[num]["locate"];
	write("�ؼг]�w��: "+locate+"\n");
		message_vision("\t\t"HIW"�դ���"+NOR+"�g�X�@��"+HIW+"�զ�����y"+NOR+"�N$N�]��F�_�ӡC\n\t\t��M�զ�����y�����b�o�ӮɪŤF�C\n",this_player());
	me->move(locate);
	if(!me->query_temp("invis"))
		message_vision(HIW"$N���ۥզ�����y�w�w�a������o�̡C\n"NOR,me);
	return 1;
}
