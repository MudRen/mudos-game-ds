#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"�W�s"HIR"�x��"HIW"�����f"NOR);
        set ("long", @LONG
�o�̴N�O�W�s�x�Ϊ������F�A���򯫤u���J��޳N
�A�O�H���T�����@��A�����N�𮧤��@�p�A��b�L�k�P
�ǻ����̱j���W�s�x���p�Q�b�@�_�C�����f���ۨ��u
���çL�A���G�O�n�o��\�i�~��i�J��C
LONG);
        
        set("exits", ([
        "south": __DIR__"road1.c",
        "north": __DIR__"dragon2",
         ]) );
        set("objects", ([
        __DIR__"npc/guard2" : 2,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
