inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�_�~�c�����W�A�u���e���i�H�ݨ���R���_�~�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���]�~�c�C
LONG);

        set("exits", ([
            "southeast"    :       __DIR__"aquarius",
            "west"  :       __DIR__"room21",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(3),
        __DIR__"npc/fighter03" : 1+random(2),
        ]));
        set("chance",60);
        set("mob_amount",20);
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}

