inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�B�k�c�����W�A�u���e���i�H�ݨ���R���B�k�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U����l�c�C
LONG);


        set("exits", ([
           "northeast"    :       __DIR__"virgo",
           "south"  :       __DIR__"room11",
        ]));
        set("objects", ([
        __DIR__"npc/fighter01" : 1+random(2),
        __DIR__"npc/fighter02" : 1+random(2),
        __DIR__"npc/fighter03" : random(2),
        ]));
       set("chance",50);
        set("mob_amount",20);
        set("mob_object",({
    __DIR__"npc/fighter03",
            }) );
        set("outdoors", "12gong");
        setup();
}

