#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"�W�s�Ĥ@�����J�f�e"NOR);
        set ("long", @LONG
�Ѧ��A���訫�N�O�x�Τ����F�A�A��������
ť��}�}�[���n�P�L���������򪺱�Ĳ�n�A���I
����.....
LONG);  
        
        set("exits", ([
        "west" : __DIR__"warrior1",
        "east" : __DIR__"dragon7",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
