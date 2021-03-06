// Room: /d/cham/trans.c
#include <path.h>
#include <ansi.h>
#define SendData "/u/s/shengsan/mine/senddata"

inherit ROOM;

mapping *senddata;

void create()
{
	set("short", HIC"藍天傳送站"NOR);
	set("long", @LONG
這裡是傳送至各工會入口的傳送站，牆上貼了一張布告(note)。
你看到前方有一個傳說中的光波輸送器。
LONG
	);
	set("exits", ([ /* sizeof() == 7 */
		"south": __DIR__"room01",
            ]));
	set("no_clean_up", 0);
	set("light",1);
        set("item_desc",(["note" :@LONG
傳送站使用說明:

	list		列出可以傳送的地點及代碼
	send 代碼	傳送到代碼所指定的地點

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
	if(!senddata) return notify_fail("載入檔案失敗!!\n");
	list  = "�������稙��������������������稙�������������������������������������������������\n";
	list += "�蠸s號��    地       點     ��           簡                   介              �鱋n";
	list += "�������嘵��������������������嘵�������������������������������������������������\n";
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
		return notify_fail("指令格式: send 代碼\n");

	senddata = NATURE_D->read_table(SendData);
	if(!senddata) return notify_fail("載入檔案失敗!!\n");

	me = this_player();
	locate = senddata[num]["locate"];
	write("目標設定為: "+locate+"\n");
		message_vision("\t\t"HIW"白水晶"+NOR+"射出一粒"+HIW+"白色光源球"+NOR+"將$N包圍了起來。\n\t\t突然白色光源球消失在這個時空了。\n",this_player());
	me->move(locate);
	if(!me->query_temp("invis"))
		message_vision(HIW"$N乘著白色光源球緩緩地降落到這裡。\n"NOR,me);
	return 1;
}

