inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG

�o�O���V�B�k�c�����W�A�u���e���i�H�ݨ���R���B�k�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U����l�c�C
LONG);


        set("exits", ([
            "north"    :       __DIR__"room12",
            "westdown"  :       __DIR__"leo",
        ]));
        set("chance",60);
        set("mob_amount",30); 
        set("objects", ([
        __DIR__"npc/fighter01" : random(2),
        __DIR__"npc/fighter02" : random(2),
        __DIR__"npc/fighter03" : random(3),
        ]));
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}

