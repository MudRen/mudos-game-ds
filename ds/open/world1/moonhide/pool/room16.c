#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�y���E���E���E���z�A�W�v���n���A�Ӧ۬}�������w�A�C����
�n�T�A�ǹM�C�Ӧa��A�շt���F��A�P��誺���G�A�Φ��j�P����
��C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room19",  
  "south" : __DIR__"room17",
  "east" : __DIR__"room13",
  "north" : __DIR__"room15",]));
        set("no_clean_up", 0);

        setup();
}

