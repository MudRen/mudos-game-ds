inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�զϮc�����W�A�u���e���i�H�ݨ���R���զϮc�q�ߦb���L
�ǨȮp�W�I
LONG);
        set("exits", ([
      "northeast"    :       __DIR__"room02",
        ]));

       set("outdoors", "12gong");
        set("objects", ([
        __DIR__"npc/fighter01" : random(3),
        __DIR__"npc/fighter02" : random(2),
        ]));
        set("chance",40);
        set("mob_amount",30);
        set("mob_object",({
        }) );
        setup();
}

