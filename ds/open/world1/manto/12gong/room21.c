inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�_�~�c�����W�A�u���e���i�H�ݨ���R���_�~�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���]�~�c�C
LONG);

        set("exits", ([
            "east"    :       __DIR__"room22",
            "westdown"  :       __DIR__"capricorn",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(2),
        __DIR__"npc/fighter03" : 1+random(3),
        ]));
        set("chance",60);
        set("mob_amount",20);
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}
