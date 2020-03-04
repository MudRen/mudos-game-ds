// Room: /u/a/alickyuen/area/inn3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;36mST�DSOFT�I�a�U�G��[2;37;0m");
	set("long", @LONG
�o�جO�o�����]���a�U�G�ӡA�G�ǳ��O�@�Ʊƪ��ж��A�O�Ψӯ�����
�H���C�p�A�����D���ܡA�i�H�߰ݳo�̪��ѭ��C
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"inn4",
  "up" : __DIR__"inn2",
]));
set("objects", ([
__DIR__"npc/keeper2" : 1,
]));
set("no_kill",1);
set("no_cast",1);
set("no_exert",1);
set("no_fight",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
        add_action("typepush","push");
}
int valid_leave(object me, string dir)
{
        if( dir!="north" )return ::valid_leave(me, dir);

        if( dir=="north" && me->query_temp("pushpass") <=0 || !me->query_temp("pushpass") )
                return notify_fail(HIW"_____________\n"NOR
                           HIW"�U�п�J�K�X�U\n"NOR
                           HIW"_____________\n"NOR
                                  HIW"�U���U���U���U\n"NOR
                                  HIW"�U���U���U���U\n"NOR
                                  HIW"�U���U���U���U\n"NOR
                                  HIW"�U�Ӣܢ�Ӣ�U\n"NOR
                                  HIW"�U__________�U\n"NOR
);

        return ::valid_leave(me, dir);
}
int typepush(string arg)
{
object me;
me=this_player();
if(!me->query_temp("bookroom") ) return notify_fail("�A�S���q�ж��C\n");

if (arg!="5" ) return notify_fail("�K�X���~�I�I\n");
{
tell_object(me,"�K�X���T�C\n");
me->delete_temp("bookroom");
me->set_temp("pushpass",1);
}
return 1;
}