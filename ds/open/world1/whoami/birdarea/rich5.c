#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","�I�v�j�U");
 set("long",@LONG
�A�Ө�F�y�������}�@�����I�����a��, �o�̪��G�m�M���]
�S���@�ˤ��O�Q���~�H��, �ݨӦ�b�o���u�����O��������, �b
�A���e���@��ѯΦ��G�N�O�o�̪��D�H�F
LONG);

 set("objects",([ __DIR__"npc/richman" : 1, ]));
 set("exits",([ "south":__DIR__"rich4", ]));  
 set("hide_exits", ([ "east" : __DIR__"rich6.c", ]));

 setup();
}        

void init()
{
     object me = this_player();
     if( me->query_skill("perception") > 15 ){
         me->set_temp("can_east",1);
         tell_object(me,HIW"�A�������l���@�J�A���G�o�{�F�@���q���F�䪺���K�p���C\n"NOR); 
         }
}

int valid_leave(object me, string dir)
{
       if( dir=="east" && me->query_skill("perception") < 15 )
                return notify_fail("�o�Ӥ�V�S���X���C\n");
        return ::valid_leave(me, dir);
}

