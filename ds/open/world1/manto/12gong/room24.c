inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�����c�����W�A�u���e���i�H�ݨ���R�������c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���_�~�c�C
LONG);

        set("exits", ([
            "west"    :       __DIR__"pisces",
            "northeast"  :       __DIR__"room23",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(2),
        __DIR__"npc/fighter03" : 2+random(2),
        ]));
        set("chance",60);
        set("mob_amount",20);
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}

