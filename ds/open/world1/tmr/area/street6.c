#include <path.h>
inherit ROOM;

void create()
{
        set("short", "�n�j��");
        set("long", @LONG
�A�����b�@���s�j���x����D�A��W��H�t�y�����A�j�h�O�����n��
�������Ҧb�A�¤ѼӴN�y���b���_�䪺�j�󤣻��B�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
              "north" : __DIR__"street5",
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}


