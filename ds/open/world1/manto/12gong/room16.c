inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V���Ȯc�����W�A�u���e���i�H�ݨ���R�����Ȯc�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���ѩW�c�C
LONG);

        set("exits", ([
           "southwest"    :       __DIR__"scorpio",
           "north"  :       __DIR__"room15",
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

