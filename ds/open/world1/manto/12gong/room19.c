inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�]�~�c�����W�A�u���e���i�H�ݨ���R���]�~�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���H���c�C
LONG);

        set("exits", ([
            "north"    :       __DIR__"room20",
            "southdown"  :       __DIR__"sagittarius",
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
