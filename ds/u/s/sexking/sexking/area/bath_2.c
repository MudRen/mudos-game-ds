#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIM"�@�f"HIR"����"HIC"����"NOR"���x ");
        set("long", @LONG
�o�̬O�@�f�������󪺤��x�A���n�O�k�ͪ����A�̭��K�O����F�A
�ܦh�H�ܳ��w�w���A�]�������i�θ����O�A�ոѨ��ߡA�٥i�ɥR��O
�A�w�_�ӤQ���ΪA�A�u�n�A�������ܡA�N�V���D�q�Ӧ�l�i�h�w���a�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"girl_suds",
  "south" : __DIR__"boy_suds",
  "east" : __DIR__"bath_1",
  ]));

        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="north" )return ::valid_leave(me, dir);

        if( dir=="north" && me->query("male")  || !me->query("male") )
                return notify_fail("���O�k�ͥh���a��A�k�ͤ�B�I\n");
        if( dir!="south" )return ::valid_leave(me, dir);

        if( dir=="south" && me->query("gender")  || !me->query("male") )
                return notify_fail("���O�k�ͥh���a��A�k�ͤ�B�I\n");

        return ::valid_leave(me, dir);
}

