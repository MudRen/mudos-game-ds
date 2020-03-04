// Room: /d/wiz/hall6.c
#include <ansi.h>
inherit ROOM;

void create()
{
 set("short", "�]���|ĳ��");
 set("long", @LONG

  �o�̬O�j�Ův�̬ۤ��Q�׻P�}�|���a��M���U�O¾�~�ޯ�Q���U�C

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall5",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/arch_b", "???");
}

void init()
{
 if(query("open")) return;
 if(userp(this_player()))
 {
   if(wiz_level(this_player()) < wiz_level("(arch)") && getuid(this_player())!="tmr")
   {
     message_vision(HIW"�ѤW�Ǩӫ��Y���n����:"HIR+this_player()->name()+",�A���Ť������i�i�J!!\n\n"NOR, this_player());
     tell_object(this_player(),"��M�@�}�j���N�A�ǰe��F�t�@�Ӧa��...\n");
     this_player()->move(__DIR__"hall5");
   } else 
   {
     message_vision(HIW"\n ��! "+this_player()->name()+" �w��Ө��]���|ĳ��!!\n\n"NOR, this_player());
   }
 }
 return;
}

