inherit ROOM;

void create()
{
   set("short","�p����j�U");
   set("long", @LONG
�o�̬O�p����j�U,�|�P�@�Ф��V,�O�H���q����,�o�̱`���p����
�B�ͨӧ�L��ѥ���,�`�O�᪺�ܶ}��..�o�̩�ۤ@�ӯd���O,���d
�Ө�������b���a�C
LONG );
  set("light", 1);
  set("exits", ([/* sizeof() == 2 */
  
"west" : "/u/s/sexking/workroom/horseroom.c",
"east" : "/u/s/sexking/workroom/workroom1.c",
"north" : "/u/s/sexking/workroom/skillroom.c",
]));
set("objects", ([ /* sizeof() == 1 */
]));
set("no_clean_up", 0);
    set("no_kill",1);
set("valid_startroom", 1);
setup();
call_other( "/obj/board/sexking_b.c", "???" );
}

