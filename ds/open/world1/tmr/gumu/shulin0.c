// shulin0.c ��L
// Java Oct.10 1998
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�p��L");
        set("long", @LONG
���b�p��L���A�A�u�D�����^�n�A�@�ѲH�H�շϡA�a�۷���
���᭻�A�۱K�L�`�B�ǥX�C�@�s�ťզ⪺�e���b�A���ǭ��ӭ��h�C
�u���@���۸O(stele)�ߦb����B�C���F�O�@���Ŧa�C�䥦��V
�ɬO�Z�K����L�C
LONG    );
        set("outdoors", "forest");
        set("item_desc", ([
                "stele" : 
HIW"

                        �׫n�j�ӡA
                        �~�H��B�C\n\n"NOR,

        ]));
        set("exits", ([
                "west"    : __DIR__"shulin5",
                "east"    : __DIR__"shulin6",
                "north"   : __DIR__"shulin4",
                "southup" : __DIR__"shulin1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

