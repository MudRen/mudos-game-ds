// caoyuan.c ���
inherit ROOM;
void create()
{
        set("short", "�����t");
        set("long", @LONG
�o�̬O�j���M�F�z���[���a�A�C��ѵ}�ܱK�A�V����������ӥh�C
�a�W���X���d�m��L����L�A�ݼˤl�o�̱`�`���Ӷ��ө��C��n��n����
�Ǫ��ϡC
LONG);
        set("exits", ([
            "east" : __DIR__"caoyuan1.c",
            "northwest" : __DIR__"pmchang",
        ]));
        set("objects", ([
                    __DIR__"npc/biaoshi" : 1,
        ])); 
        set("outdoors", "land");
        setup();
}
