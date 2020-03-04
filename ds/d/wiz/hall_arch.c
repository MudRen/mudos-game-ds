// Room: /d/wiz/hall6.c
#include <ansi.h>
inherit ROOM;

void create()
{
 set("short", "�]���|ĳ��");
 set("long", @LONG

  �o�̬O�j�Ův�̬ۤ��Q�׻P�}�|���a��A���U�O¾�~�ޯ�Q���U�C

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall_guild",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/arch_b", "???");
}

void init()
{
 if(this_object()->query("open")) return;
 if(userp(this_player()))
 {
   if(wiz_level(this_player()) < wiz_level("(arch)"))
   {
     message_vision(HIW"�ѤW�Ǩӫ��Y���n����:"HIR+this_player()->name()+",�A���Ť������i�i�J!!\n\n"NOR, this_player());
     tell_object(this_player(),"��M�@�}�j���N�A�ǰe��F�t�@�Ӧa��...\n");
     this_player()->move(__DIR__"hall_guild");
   } else 
   {
     message_vision(HIW"\n ��! "+this_player()->name()+" �w��Ө��]���|ĳ��!!\n\n"NOR, this_player());
     add_action("do_lock","lockhere");
     add_action("do_unlock","unlockhere");
   }
 }
 return;
}

int do_unlock(string arg)
{
	if(this_object()->query("open")) return notify_fail("�Ův�L�o�O���w�g�����F�C\n");
	message_vision(HIW"$N�����F�Ův�L�o�˸m�ϤO��!!\n\n"NOR, this_player());
	this_object()->set("open",1);
	return 1;
}

int do_lock(string arg)
{
	object *inv;
	int i;
	if(!this_object()->query("open")) return notify_fail("�Ův�L�o�O���w�g�ҰʤF�C\n");
	message_vision(HIW"$N�ҰʤF�Ův�L�o�˸m�ϤO��!!\n\n"NOR, this_player());
	this_object()->delete("open");
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
	   if(!userp(inv[i])) continue;
	   if(wiz_level(inv[i]) < wiz_level("(arch)"))
	   {
	     message_vision(HIW"�ѤW�Ǩӫ��Y���n����:"HIR+inv[i]->name()+",�A���Ť������i�i�J!!\n\n"NOR, inv[i]);
	     tell_object(inv[i],"��M�@�}�j���N�A�ǰe��F�t�@�Ӧa��...\n");
	     inv[i]->move(__DIR__"hall_guild");
	    }
	}
	return 1;
}
