inherit ROOM;

void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�����c�����W�A�u���e���i�H�ݨ���R�������c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���զϮc�C
LONG);

        set("exits", ([
         "southeast"    :       __DIR__"taurus",
         "west"    :       __DIR__"room03",
        ]));
        set("chance",40);
        set("mob_amount",30);
        set("objects", ([
        __DIR__"npc/fighter01" : random(3),
        __DIR__"npc/fighter02" : random(3),
        ]));
        set("mob_object",({
        }) );

        set("outdoors", "12gong");
        setup();
}

