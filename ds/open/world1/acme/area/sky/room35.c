// Room35.c

inherit ROOM;

void create()
{
        set("short","�Ѧa�|�j��");
        set("long", @LONG
�A���e�����O�Ѧa�|�������j���A�@�ѵ¿p����Ţ�n�W���Y�C�P
��G�m�o�@�Ф��V�A�ⰼ�U�ƦC�F�Ʊi��l�M�Ȥl�A�H�ѴګȤ��ΡC
���������e���A�O�A�쥻��i���߲z�n�ɩ��P�C�b�A�߯����P���ɭ�
�A�oı�j�����Y������������W�A���ۨ��C����e�α��b����W�A
�b����W�樫�h�~���A�A��ı�����ä��O���q���C�C����i�H��F
���\��A���F�i�H��F�a�b��A���_�i�H��F�Ѧa�|�|ĳ�ǡC

LONG
        );
        set("exits", ([
                "north": __DIR__"room25",
                "east": __DIR__"room36",
                "south": __DIR__"room45",
                "west": __DIR__"room34",
  "up" : "/open/world1/wilfred/club/dragon/online",
        ]));
        set("objects",([
        __DIR__"item/equip_box" :1, // 2006.5.30 add by whoami
        ]));

        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
        call_other( "/obj/board/sky_room35_b", "???" );
}

void init()
{
  this_player()->set_temp("come_from_dragon",0);
  this_player()->set_temp("come_from_sky",1);
}

