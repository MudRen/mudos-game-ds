inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�A�����b�j����W, �A�ݤF���䦳�\�h����F�ξ�K, ���۳s�����\
�h����, �A���W�ݥu���@�j�����𸭾צ�A�����u, ���A�Q����̰��B��
�ݯ����������.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "down" : __DIR__"big_tree.c",
          "north" : __DIR__"tree.c",
               ]));
            
        set("no_clean_up", 0);
        set("outdoors","forest");               
        setup();
        replace_program(ROOM);
}


