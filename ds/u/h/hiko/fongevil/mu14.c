inherit ROOM;
void create()
{
        set("short", "��s");
        set("long",@LONG
�o�̬O�ݩ��s���a��A�X�G�ݰ_�ӬO���L�H��A�ʪ��]�۷��h
�A���ɷ|�Ӧ��a���j���u���y��άO�@�Ǳ��ĭ��A�ҥH�������Q����l
�A�S���@�I�H���J�Z������A���H�M�~���O��ӥ@�ɪ��Pı�C
LONG
        );
  
set("exits", ([
  "out" : __DIR__"mu12",
  "eastdown" : __DIR__"mu15",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 






