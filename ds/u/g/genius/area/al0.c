inherit ROOM;

void create()
{
set("short", "�R�����~");
        set("long", @LONG
�A���e�Ҩ��O�@�y�y�C�G���A���Ъ١A�o�̴N�O�¾몺�R�����F�C�o��
���Ů�Q���a�n�A�ѪŤ��Ƶۤ@�������m���C�A���߱��Q�����κZ�A�B��]
��ۻ��ְ_�ӡC
LONG
        );
        set("exits", ([
     "west":__DIR__"al1",
]));
        set("hide_exits", ([
        "out" : __DIR__"firstroom",
        ]));


        set("objects", ([
]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
