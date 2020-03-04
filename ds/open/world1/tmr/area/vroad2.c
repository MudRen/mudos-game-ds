// Room: /u/t/tmr/area/vroad2.c

inherit ROOM;

void create()
{
	set("short", "�s���s��");
	set("long", @LONG
�o�O�@�y���s�����p�s���A�b��᦬�ήɡA�o�̱`�`�|�Q�ΨӰ��V
�̵��u�@�A��A���ɡA�h�j���O�s���p�Ī����֦a��A�s�������ʼƤH�X
�ꪺ�Ѭh��A�ǻD���w���F���W�ʦ~���[�A��O�s��������F�C�����C��
�J������j�ơA�`�|�۬��󦹰Q�׽ͧP�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"vroad4",
  "west" : __DIR__"vroad3",
  "east" : __DIR__"vroad1",
]));
	set("objects",([
 	  __DIR__"npc/mvillager" : 4,
        __DIR__"npc/seller" : 1,
	]) );
	set("outdoors","land");
        set("item_desc", ([
	"�Ѭh��" : "�@�ʽL�ڿ��`���Ѭh��A�ڻ��w����P�A�ᦳ�F��C\n",
	]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_beg","beg");
}

int do_beg(string arg)
{
        object me;
        me=this_player();
        if (!arg) return 0;
          if(arg!="�Ѭh��") return 0;
        if(me->is_busy() || me->is_fighting() )
                return 0;
        else{           
                message_vision("$N�����q�q��ۦѬh��X�Q���F�ƫ��C\n",me);
                me->set_temp("beg-tree",1);
        }
        return 1;
}

