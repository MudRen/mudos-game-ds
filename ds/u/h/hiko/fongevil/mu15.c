inherit MOBROOM;
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
  "northup" : __DIR__"mu16",
  "southeast" : __DIR__"mu19",
  "westup" : __DIR__"mu14",
]));
set("chance",50);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"animal/cissa",
}) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 










