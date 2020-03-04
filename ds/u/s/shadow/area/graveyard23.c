/**
 * Shadow's area [��o���� - �q������ - graveyard23]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
#define SHADOW_GRAVEYARD "/u/s/shadow/area/"

inherit ROOM;

void open_war(object me, object ob);
void end_war();
int query_ghost();

void create()
{
	set("short",HIG"�q������"NOR);
	set("long",
"�@�y���j������A�ѩ^�۬I�a���a������������F��A��Ǵ���\n"
"���@�s���O�ЮJ�A�j����M�G��y����A�a�W�h�����ۤ@�Ǩѩ^����\n"
"�Ϊ�����C���Y�V���@�ݡA�~�M���@"HIR"���e"NOR"�a�Q���٤��W�A�b�ſ���\n"
"�������Ƨr�Ʀa�A���H�ť���ߡI\n"
	);
	set("light", 0);
	set("exits",([
		"south": __DIR__"graveyard22",
	]));
	
	set("item_desc",([
		"���e": @LONG
    �b�Ť����������e�A�Τ@���ʳ�÷ô�b���󪺾�٤W�A���W���j
���窫���w�ƥh�F�C��A���i�H�Q�����O���̦��ɪ����A�_�h���
�|��ܳo�˪��覡�׵��ۤv���ͩR�A�ݵ۰��e�A�A�ߤ����_�F�@�Ѽ�
�����N�A��M���_�F�Q��L���U�Ӫ����Y(get)�C
LONG
	]));   
	
	setup();	
}

void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
	object me, room, manager;
		
	if (!arg)
		return 1;
	else if (arg != "���e")	{
		return notify_fail("�A�n���ƻ�O�H\n");
	}	else {
		me = this_player();
		room = environment(me);
		
		if ( room->query_temp("get") )
			return notify_fail(HIG"�@�}�����]�o�b�Ů𤤡A�ƻ�Ƥ]�S��...\n"NOR);
		else {
			room->set("open_war",1);
			call_out("open_war", 3, me, room);
			/* �� ppl �L�k recall & south */
			room->set_temp("get", 1);
			room->set("exits",([]));
			room->set("no_recall","���󪺳������Ѧa�ॢ�F�ǰe�O�q�C");
		}
	}
	return 1;
}

void open_war(object me, object ob)
{
	int i;
	object g, ghost;
	
	if( !ob->query("open_war") ) return;

	/* Start GraveyardWar */
	message("world:world1:vision", HIW"\n\t"+me->name(1)+"���J�F�q�����T�ϡ�\n"NOR, users());
	message("world:world1:vision", HIR"\n\t�����@�}���������A�q�����Ѫź��_�@�Ѹ{����B\n"NOR, users());
	message("world:world1:vision", HIR"\n\t����k�����y�s�n�T����ӤѪ�...�� �t �� �� �� �L �j��\n\n"NOR, users());
	
	/* �I�s�X����k�� */
	ghost = new(__DIR__"npc/ghost");
	ghost->move(ob);
	
	/* �I�s�X�q���޲z��*/
	g = new(__DIR__"npc/manager");
	g->move(__DIR__"graveyard23");

	/* ���ͬ����H */
	for(i=0; i<1; i++)
	{
		g = new(__DIR__"npc/dead1");
		g->move(__DIR__"graveyard21");
	}
	/* ���ͭ��ͪ� */
	for(i=0; i<1; i++)
	{
		g = new(__DIR__"npc/dog1");
		g->move(__DIR__"graveyard21");
	}
	
	
	call_out("end_war", 180);
	return;
}

void end_war()
{
	object ghost;
	
  if( query_ghost() )	call_out("end_war",30);
	else {
		message("world:world1:vision", HIR"\n\t�@�n�Y�F���y�s�����ۤ��ΦR�D�����H�ι�@�H���A�G��}�F���h�A���u�b�q�����ѪŤ�...\n\n"NOR, users());
		this_object()->set("open_war",0);
	}       
	return;
}

int query_ghost()
{
	object ghost;

	while( objectp(ghost = find_living("GraveyardWar")) )
	{
		if( !environment(ghost) )	{
			destruct(ghost);
			ghost = 0;
		}
		else break;
	}
	if( objectp(ghost) ) return 1;
	else return 0;
}
