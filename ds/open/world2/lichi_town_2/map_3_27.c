inherit ROOM;
void create()
{
	set("short", "�M��");
        set("long", @LONG

[1;33m�šš�    [31m�z�s�{       �z�s�{[m                 �j      [0m
[1;33m      ��  [31m�u�q�t       �u�q�t[m                 �j      [0m
[1;33m�áá�[0;33m��[1;33m�j[31m�|�r�}[32m /[31m��[32m\\[31m �|�r�}�\ [37m  �ššššš�[0m�j      [0m
[1;33m�áá�[0;33m��[1;33m�j[32m      ///|[35m��[32m\    ��[33m��[32m��[37m ��          ��      [0m
[1;33m�áá�[0;33m��[1;33m�j[32m        _|_       /_|![37m  �i��          ��    [0m
[1;33m�áá�[0;33m��[m�áááá�\_/�ááá�\_/��[1;37m���i��          ��  [0m
[1;33m�ááá�        �ššš�    [1;37m        ���i��          ��[0m
[1;33m              �y��      ��  [1;37m          ���i�i�i�i�i�i�i[0m
[1;33m                �y�áááâj[1;37m            ���i�i�i�i�i�i[0m

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_27",
	]));
	set("light",1);
        setup();
}
/*
string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}
*/

void init()
{
	object me,out;
	me=this_player();
	out = find_object(__DIR__"map_4_27");
	if(out) out->set("full",1);
	me->add_busy(1);
	call_out("sleep",0,me);
	call_out("wakeup",6,me);
	call_out("leaveroom",7,me);
	call_out("empty",7,out);
	return;
}

void sleep(object me)
{
	if(!me) return;
	me->remove_all_enemy();
	message("system","\n�A���b�ɤW�����εۤF..\n\n",me);
	me->disable_player_cmds("�A���b��ı�C\n");
	//this_object()->disable_player(" <�����H��>");
	me->set_temp("block_msg/all", 1);
	return;
}

void wakeup(object me)
{
	if(!me) return;
	me->set("hp",me->query("max_hp"));
	me->set("mp",me->query("max_mp"));
	me->set("ap",me->query("max_ap"));
	me->wakeup(0);
	me->start_busy(1);
	me->delete_temp("malo/inn");
	return;
}

void leaveroom(object me)
{
	if(!me) return;
	tell_room(this_object(),"�A���F���i�y���F�X�h�C\n");
	me->move(__DIR__"map_4_27");
	tell_room(environment(me),me->name()+"�q�ж��̨��F�X�ӡC\n",({me}));
	return;
}

void empty(object room)
{
	room->delete("full");
	return;
}