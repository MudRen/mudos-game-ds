#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"HIW"�d�j�۪L"NOR);
        set("long", @LONG
�o�̬O�@�B���a�A��B���O���j���ƥ۾��A����b���t���۪L
�����A���خ��߷P�A�����D�|������Ǫ��]�X�ӡA�a���O�p�p���ۦ�
�A�L�k���X����Ӫ��A���r�r����o�I��C
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"room39",
            "west" : __DIR__"room44",
            "south" : __DIR__"room38",
            "north" : __DIR__"room42",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
        set("objects",([
           __DIR__"npc/huge-turtle":1,
        ]));
        setup();
}
