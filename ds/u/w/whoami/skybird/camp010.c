inherit ROOM;

void create()
{
        set("short", "�T�s��");
        set("long", @LONG
�x�礤���j�}�A�礤�^��L�ߡA�}�W���A�M�X�P�A�@�ѱ���
�����ӨӡA�A���ѧ󬰺�i�C�ݨ�A���e�ӡA�礤���h�L���­Y
�L��ơA�U�ۦ��ۦۤw���ơA�ݨ�x���p���Y���A�A���Ѥߤ��@
�_�C 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"camp014",
  "west" : __DIR__"camp005",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

