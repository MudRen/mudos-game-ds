inherit ROOM;

void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V���l�c�����W�A�u���e���i�H�ݨ���R�����l�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U�������c�C
LONG);

        set("exits", ([
           "southwest"    :       __DIR__"genini",
           "north"  :       __DIR__"room05",
        ]));
        set("chance",40);
        set("mob_amount",30); 
        set("objects", ([
        __DIR__"npc/fighter01" : random(2),
        __DIR__"npc/fighter02" : random(3),
        __DIR__"npc/fighter03" : random(2),
        ]));
        set("mob_object",({
        }) );
        set("outdoors", "12gong");
        setup();
}

