inherit ROOM;

void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V���ɮc�����W�A�u���e���i�H�ݨ���R�����ɮc�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U�����l�c�C
LONG);


        set("exits", ([
            "eastdown"  :       __DIR__"genini",
             "west"    :       __DIR__"room08",
        ]));
        set("chance",50);
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

