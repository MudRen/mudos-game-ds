inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A���b�p�|�W���A�ݵ۩P�򪺤s���q�����w�A�Pı���a�]�O���@�f
�����A�ᦳ�@�ئ۱o��֪����D�A���e��ݥh�p�|�w�g�C�C���U�A�Pı
���G���Ӥp�Y�A�i��n�p�ߤ@�I�C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"m5",
  "southeast" : __DIR__"m3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}



