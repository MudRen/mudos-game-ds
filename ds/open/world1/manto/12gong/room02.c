inherit ROOM;

void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�զϮc�����W�A�u���e���i�H�ݨ���R���զϮc�q�ߦb���L
�ǨȮp�W�I
LONG);
        set("exits", ([
           "east"    :       __DIR__"baiyang",
           "southwest"    :       __DIR__"room01",
        ]));

        set("chance",40);
        set("mob_amount",30);
        set("objects", ([
        __DIR__"npc/fighter01" : random(3),
        __DIR__"npc/fighter02" : random(2),
        ]));
        set("outdoors", "12gong");
        setup();
}

