#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", YEL"�q���h�A�a���q���W"NOR);
        set ("long", @LONG
����������A�e�����A�u���ӨӡC�O�H�̨����F��
�A���ӥO�H�������ͯ���~�A�a�W�@��b����������
���٦bį�ʡAį�ʵ�~~~~~~
LONG);  
        
        set("exits", ([
        "east" : __DIR__"humid2",
        "west" : __DIR__"road3",
        ]) );
        set("objects", ([
        __DIR__"npc/corpse" : 1,
        __DIR__"npc/item/saint_water" :1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
