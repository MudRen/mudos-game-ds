inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG

�o�O���V��l�c�����W�A�u���e���i�H�ݨ���R����l�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U�����ɮc�C
LONG);

        set("exits", ([
           "northeast"    :       __DIR__"leo",
           "south"  :       __DIR__"room09",
        ]));
        set("chance",50);
        set("mob_amount",30); 
        set("objects", ([
        __DIR__"npc/fighter01" : random(2),
        __DIR__"npc/fighter02" : random(3),
        __DIR__"npc/fighter03" : random(3),
        ]));
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}
