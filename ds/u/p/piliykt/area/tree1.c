inherit ROOM;
void create()
{
set("short","����");
set("long", @LONG
�A�����b���j����K�W, �A���W��ǨӤF�ǳ\���n��, ���A�������Q
��W�Y�h�@�@, �A���|�P�G���F��K.
LONG
);
set("outdoors", "desert");
set("exits", ([ 
                "down"  : __DIR__"tree.c",
                "east"  : __DIR__"tree2.c",                                
                           ]));
 setup();
}

