inherit ROOM;
void create ()
{
        set ("short", "�s��");
        set ("long", @LONG
�o�O���V�ѩW�c�����W�A�u���e���i�H�ݨ���R���ѩW�c�q�ߦb���L
�ǨȮp�W�I���������������٥i�H�ݨ��s�U���B�k�c�C
LONG);

        set("exits", ([
           "east"    :       __DIR__"room14",
          "westdown"  :       __DIR__"virgo",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(2),
        __DIR__"npc/fighter03" : 1+random(2),
        ]));
        set("chance",60);
        set("mob_amount",10);
        set("outdoors", "12gong");
        setup();
}


