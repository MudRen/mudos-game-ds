// Room: /u/a/acme/area/rock.c

inherit ROOM;

void create()
{
	set("short", "�j�ۤW");
     set("light",1);
	set("long", @LONG
�o�̬O�r���W���j�ۡA���y���A���W�R�h�A�A�n�Ӯ̥h�A�K�N���F�U
�h�A�|�P������ݤ��M�A�����ݨ��r���ᦳ���۾��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"pool",
]));
     set("objects",([
          __DIR__"npc/oldman" : 1,
       ]));
	set("no_clean_up", 0);
     set("item_desc", ([
"�۾�" : "�o�O�r����誺�۾��A�W�������F�C�a�A�۾��S��S�p�A���G�O�V�����}�A�γ\\���(push)�}�C\n",
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
        if(arg != "�۾�") return 0;
        message_vision("$N�ϫl�����ʵۥ۾��A���h�ɥ۾��K�X�{�F�X�f�C\n\n",me);
         set("exits", ([
          "west" : __DIR__"stone",
          "down" : __DIR__"pool",
        ]));
        return 1;
}
