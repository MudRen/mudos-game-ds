// Room: /u/d/domy/workroom.c

inherit ROOM;

void create()
{
        set("short", "[32m�h�̤p��[0m");
        set("long", @LONG
�A�{�b�Ҧb�O�h�̤p�����e�A�h�̨p�H�줽��
�A�{�N�ɪŪ��u�@�U.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "eeman" : "/u/e/eeman/workroom",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"area/npc/lieutenant" : 1,
]));
        set("no_clean_up", 0);
set("valid_startroom", 1);
setup();
call_other("/obj/board/domy_b.c", "???");
      
}

void init()
{

write("~~~~~[35m�w��Ө�h�̤p��[0m~~~~~\n"); 
}


