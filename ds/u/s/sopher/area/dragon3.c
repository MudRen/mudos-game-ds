#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"�}�����j�D"NOR);
        set ("long", @LONG
�H�ʪ��}�}��A�A���e�����B���@�y�Ӯc�A����
�N�O�W�s�x�ΦU�F���Τ��Ϊ�����F�C�Ӧb�A��_��
�A�}�}���ϥT�T�W�@�A���̤j���N�O�L��F�A�����u
�O�ӭx�Υ����A���S�Q�쳺�M�W�Ҧp�����e�j�I
LONG);
        
        set("exits", ([
        "south": __DIR__"dragon2",
        "north": __DIR__"dragon7",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 2,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
