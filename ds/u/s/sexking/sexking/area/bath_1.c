#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIM"�@�f"HIR"����"HIC"����"NOR" ");
        set("long", @LONG
�o�O�@���z�R���ת�����A�|�P�R���۲M�s�ڭ��A�̭��K�O����F�A
�ܦh�H�ܳ��w�w���A�]�������i�θ����O�A�ոѨ��ߡA�٥i�ɥR��O
�A�w�_�ӤQ���ΪA�A�u�n�A�������ܡA�N�V���D�q�Ӧ�l�i�h�w���a�C
LONG
        );
        set("exits", ([
  "east" : __DIR__"map_9",
  "west" : __DIR__"bath_2",
  "up" : __DIR__"bath_3",
]));
set("objects",([
       __DIR__"npc/mo" : 1,
    ]) );
 
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
        call_other( "/obj/board/fushun_b.c", "???" );
}

int valid_leave(object me, string dir)
{
        if( dir!="west" )return ::valid_leave(me, dir);

        if( dir=="west" && me->query_temp("suds") <=0 || !me->query_temp("suds") )
                return notify_fail("�A�٨S���I������w����I\n");

        return ::valid_leave(me, dir);
}


