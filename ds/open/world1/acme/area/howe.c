// Room: /u/a/acme/area/howe.c
inherit ROOM;
void create()
{
	set("short", "�}��");
	set("long", @LONG
�o�̥��O�F�l�A�A���f�󤧤��o�]�뺡�F�ӨF�A�A�Pı��I�l�x���A
�Y������A�|�P�º������A���T�O�H���ͬ��ߡA�A�|�_����b�o�}�޺N��
�A�b�A���椧�ɡA�A�������M�N��F�@����A�b�o�Ӭ}�ޤ������@�D��
�A�O�H�_�F�n�_���ߡC
LONG
	);
set("exits", ([ /* sizeof() == 1 */
    "up" : __DIR__"hills1.c",
]));
set("objects" , ([
     __DIR__"npc/worm.c" : 4,
]) );
	set("no_clean_up", 0);
    set("item_desc", ([
        "��" : "�o�D��S�p�S�w�A�ݨӬO�V�����}���A�����w�A��α�(push)���C\n",
    ]));
	setup();
}
void init()
{
        add_action("typepush","push");
}
     int typepush(string arg)
{
       object me;
        me=this_player();
        if(arg != "��") return 0;
         else {
        message_vision(
        "$N�ϫl��������A�����n�Ӷ}�C\n\n"
         ,me);
         set("exits", ([
          "up" : __DIR__"hills1",
          "south" : __DIR__"howe1",
]));
 return 1;
        }
}

