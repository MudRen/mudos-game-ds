// Room: /u/t/tmr/area/inn_2f.c

inherit ROOM;

void create()
{
 set("short", "�H�ѫ�");
 set("long", @LONG
�o�̴N�O�¤ѼӪ��G�Ӫ��ѫǡA�O�M���R�n�H�Ѫ��P�n�}�P���C
�o�̦��@�i��l�A�W����ۤ@�i����H�Ѫ��ѽL�C�o�̱`�`�����ֺ�
��������l����E���󦹤��R�����C

LONG
);

        set("exits", ([ /* sizeof() == 2 */
          "west" : __DIR__"fc2",
]));
set("objects",([
        "/obj/cch.c" : 1,
]) );
        set("no_kill",1);
        set("no_fight",1);
        set("no_exert",1);
        set("no_cast",1);
    set("no_goto_cmd",1);
        set("no_recall",1);
        set("no_steal", 1);
        set("light",1);
        set("no_clean_up", 0);
set("light",1);

        setup();
}

