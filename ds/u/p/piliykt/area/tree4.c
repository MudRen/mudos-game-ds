
inherit ROOM;
void create()
{
set("short","�p��");
set("long", @LONG
�o�̷Pı����G�F�@��, �i��O�e�観�X�f, �Ať�즳�@�ǷL�L���s
�s�n��. 
LONG
);
set("exits", ([ 
                "west"  : __DIR__"tree3.c",
                "out"  : __DIR__"tree5.c",
                           ]));
set("objects",([
__DIR__"npc/mouse.c" : 2,
              ]) );
        
setup();
        
}

