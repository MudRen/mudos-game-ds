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
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"camp016",
  "west" : __DIR__"camp009",
  "north" : __DIR__"camp011",
  "south" : __DIR__"camp013",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

