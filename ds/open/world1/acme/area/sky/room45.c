// Room45.c

inherit ROOM;

void create()
{
        set("short","�Ѧa�|���x");
        set("long", @LONG
�A�����b�Ѧa�|�����x�A�o���x�������j���Ŷ��C�Ӧb�A���ǡA
�����ۤG�Q�W������������ƶ}�C�񲴱�h���B�A�|�P�Q�f�X��A�b
���R�s��U�O�A�߯��j���C���_�i�H��F�Ѧa�|�j���A���n�i�H��F
�Ѧa�|�P�{�C

LONG
        );
        set("exits", ([
                "north": __DIR__"room35",
                "south": __DIR__"room55",
        ]));  
        set("objects",([
        __DIR__"item/sky-ming_tree" :1,
]));
        set("light",1);
set("no_goto",1);
        setup();
        set("stroom",1);

}
