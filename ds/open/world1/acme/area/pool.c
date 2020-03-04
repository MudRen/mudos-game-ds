// Room: /u/a/acme/area/pool.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�Ѧ�");
	set("long", @LONG
�o�̴N�O�Ѥs���W���Ѧ��F�A�|�P�R���F����A�Ѧ����Φ��O�]�Ѧ�
�W�誺�r���R�k�Ӧ��A�r���W�����j�ۡA�]�j�ۦb���ҥH�r���@�����G�A
������h�˦��O���s���}�A�j�ۤW�o�w�����F��⪺�C�a�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"pass1",
"northup" : "/open/world1/faceoff/sky/ten1",
]));
        set("hide_exits", ([ /* sizeof() == 1 */
                 //"north" : SKY_CLUB+"room55.c",
                 "north" : "/open/world1/manto/sky2_1f/map_7_13.c",
        ]));
	set("no_clean_up", 0);
    set("outdoors","land");
     set("item_desc", ([
"�j��" : "�o�O�r���W���j�ۡA�W�������F�C�a�A�Y�ۻ{���\\�����A�γ\\���(jump)�W�h�C\n"
     ]));

	setup();
}
void init()
{
        add_action("typejump","jump");
}
     int typejump(string arg)
{
        object me;
        me=this_player();
        if(arg != "�j��") 
         return 0;
        else {
        message_vision(
        "$N�i�}�F���Z�����\\�A���j�ۤW���h�C\n\n" ,me);
        me->move(__DIR__"rock");
        return 1;
             }
}

int valid_leave(object me, string dir)
{
       object obj;
        if( dir=="north" && !wizardp(me))
        {
        // �����O�Ѧa���H��i�h, hmm �Ȯɥ��W�[�ӧP�_. by -Acme-
        if(objectp(obj!=present("ring of heaven and earth",me)))
                return notify_fail("�A���W�S���Ѧa�|���H���A�L�k�i�J�C\n");
        	if( CLUB_D->check_member("sky",getuid(me))<1 ) return notify_fail("���̥u���Ѧa�|�����~��i�h�C\n");
        	if( me->query_temp("killer") )
        	{
        		message_vision(HIW"\n�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�����F�H�ҥH�Ȯɤ���i�J���|�C\n"NOR,me);
        		return notify_fail("�A�������q�r�ɶ��L�F����~��i�J���|�C\n");
        	}
		if( me->query_temp("invader") )
		{
        message_vision(HIW"\n�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A���ˤF�H�ҥH�Ȯɤ���i�J���|�C\n"NOR,me);
			return notify_fail("�A�������q�r�ɶ��L�F����~��i�J���|�C\n");
		}
        }
        return ::valid_leave(me, dir);
}
