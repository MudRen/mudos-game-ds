#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", HIW"������"NOR);
    set("long", @LONG
�@�����O���A�S���ҿת��O�P�D�A��P���C�b�A���k���䦳�ӵo
�������Y�A[0;1;36m�[1m�[1m�[1m@[1m�[1mU[1m([1ml[1mo[1mo[1mk[1m)[0m�����w�|���X�G�w�ƪ��Ʊ��o�͡C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  
  "�o�������Y" : "[0;1;37m�[1mo[1m�[1mO[1m�[1md[1m�[1m�[1m�[1mw[1m�[1m[[1m�[1m�[1m�[1m�[1m�[1mY[1m�[1mA[1m�[1m@[1m�[1mH[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mA[1m�[1mp[1m�[1mG[1m�[1mA[1m�[1m�[1m�[1mN[1m�[1m�[1m�[1m�[1m([1mt[1mo[1mu[1mc[1mh[1m)[1m�[1m�[1m�[1m�[1m�[1mw[1m�[1m|[1m�[1mo[1m�[1m�[1m�[1m@[1m�[1m�[1m�[1m_[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mC[0m ",
]));
        set("world", "past");
                set("exits", ([ /* sizeof() == 1 */
  "out" : "/u/y/yunin/godarea/room5",
]));  
   set("no_clean_up", 0);

        setup();
}      
void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="�o�������Y" ) return 0;
        message_vision(HIR"�A�N�F�o�ө_�Ǫ����Y�A���M���W�F�ѡC \n"NOR,me);
        me->move(__DIR__"room13");
          tell_room(environment(me),me->query("name")+HIR"���M���W�F�ѡC\n"NOR,me );
return 1;
}

