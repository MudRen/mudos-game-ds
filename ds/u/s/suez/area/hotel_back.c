// Room: /u/s/suez/area/hotel_back.c
inherit ROOM;
void create()
{
	set("short", "�ȴ̫�|");
	set("long", @LONG
�A�����e�@�G�A�@���Ѻ񪺤p�˴N�b�A���e�y�L�A�Ӥ@�y�i�R���p��
������W�A�|�P���˪L�]�����ƥX�M�n���s���A�����ﭱ���˪L������
�����p�Ωγ\�i�H�L�h(pass)�ݬݡC
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hotel_path",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_pass", "pass");
}

int do_pass(string arg)
{
        object me;
        me=this_player();
 

        if (arg != "�p�˾�" && arg !="��" )
                return 0;
        else 
        {
        me->move(__DIR__"hotel_room4");
        return 1;
        }
}